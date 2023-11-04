declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

/*

ZITA_REVERB DESCRIPTION:

APPLICATIONS: Guitar Pedal

The simplicity of this zita_reverb implementation is meant to be exported for use with hardware implementation such as guitar pedals. The following parameters allow
you to shape the reverberation effect. These parameters are those best fit to modify with sliders if an expansion of the reverb properties is done with GUI elements. 

[1] rdel: This parameter is used in the zita_in_delay function, representing the input delay in milliseconds. Adjusting this will change the initial delay before the reverb effect begins.

[2] f1 and f2: These are used in the zita_rev_fdn function and represent frequencies that are used to shape the delay filters within the feedback delay network. f1 could be understood as a low-frequency cutoff, and f2 as a high-frequency cutoff for the reverberation effect.

[3] t60dc and t60m: These parameters are used in the zita_rev_fdn function to define the reverberation time (how long it takes for the reverb to decay 60 decibels) at direct current (DC) and at mid frequencies, respectively.

[4] fsmax: This is the maximum sampling rate expected to be used with this reverb. It influences delay calculations to ensure that delay buffers are large enough for the highest sampling rate.

[5] eq1f, eq1l, eq1q, eq2f, eq2l, eq2q: These parameters are related to the equalization stage after the reverb. The f parameters are the center frequencies for the peaking EQ, l parameters are the gain levels, and q parameters are the Q-factors or bandwidths of the EQ filters.

[6] drywet: This parameter adjusts the balance between the dry (unprocessed) and wet (processed) signal. It can be controlled in real-time with a GUI slider.

[7] gain: This controls the overall output level of the reverb.

*/

zita_rev_fdn(f1,f2,t60dc,t60m,fsmax) =
  ((si.bus(2*N) :> allpass_combs(N) : feedbackmatrix(N)) ~
   (delayfilters(N,freqs,durs) : fbdelaylines(N)))
with {
  N = 8;

  // Delay-line lengths in seconds:
  apdelays = (0.020346, 0.024421, 0.031604, 0.027333, 0.022904,
              0.029291, 0.013458, 0.019123); // feedforward delays in seconds
  tdelays = ( 0.153129, 0.210389, 0.127837, 0.256891, 0.174713,
              0.192303, 0.125000, 0.219991); // total delays in seconds
  tdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,tdelays)); // samples
  apdelay(i) = floor(0.5 + ma.SR*ba.take(i+1,apdelays));
  fbdelay(i) = tdelay(i) - apdelay(i);
  // NOTE: Since SR is not bounded at compile time, we can't use it to
  // allocate delay lines; hence, the fsmax parameter:
  tdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,tdelays));
  apdelaymaxfs(i) = floor(0.5 + fsmax*ba.take(i+1,apdelays));
  fbdelaymaxfs(i) = tdelaymaxfs(i) - apdelaymaxfs(i);
  nextpow2(x) = ceil(log(x)/log(2.0));
  maxapdelay(i) = int(2.0^max(1.0,nextpow2(apdelaymaxfs(i))));
  maxfbdelay(i) = int(2.0^max(1.0,nextpow2(fbdelaymaxfs(i))));

  apcoeff(i) = select2(i&1,0.6,-0.6);  // allpass comb-filter coefficient
  allpass_combs(N) =
    par(i,N,(fi.allpass_comb(maxapdelay(i),apdelay(i),apcoeff(i)))); // filters.lib
  fbdelaylines(N) = par(i,N,(de.delay(1024,(fbdelay(i)))));
  freqs = (f1,f2); durs = (t60dc,t60m);
  delayfilters(N,freqs,durs) = par(i,N,filter(i,freqs,durs));
  feedbackmatrix(N) = ro.hadamard(N);

  staynormal = 10.0^(-20); // let signals decay well below LSB, but not to zero

  special_lowpass(g,f) = si.smooth(p) with {
    // unity-dc-gain lowpass needs gain g at frequency f => quadratic formula:
    p = mbo2 - sqrt(max(0,mbo2*mbo2 - 1.0)); // other solution is unstable
    mbo2 = (1.0 - gs*c)/(1.0 - gs); // NOTE: must ensure |g|<1 (t60m finite)
    gs = g*g;
    c = cos(2.0*ma.PI*f/float(ma.SR));
  };

  filter(i,freqs,durs) = lowshelf_lowpass(i)/sqrt(float(N))+staynormal
  with {
    lowshelf_lowpass(i) = gM*low_shelf1_l(g0/gM,f(1)):special_lowpass(gM,f(2));
    low_shelf1_l(G0,fx,x) = x + (G0-1)*fi.lowpass(1,fx,x); // filters.lib
    g0 = g(0,i);
    gM = g(1,i);
    f(k) = ba.take(k,freqs);
    dur(j) = ba.take(j+1,durs);
    n60(j) = dur(j)*ma.SR; // decay time in samples
    g(j,i) = exp(-3.0*log(10.0)*tdelay(i)/n60(j));
  };
};

// Stereo input delay used by zita_rev1 in both stereo and ambisonics mode:
zita_in_delay(rdel) = zita_delay_mono(rdel), zita_delay_mono(rdel) with {
  zita_delay_mono(rdel) = de.delay(2700,ma.SR*rdel*0.001) * 0.3;
};

// Stereo input mapping used by zita_rev1 in both stereo and ambisonics mode:
zita_distrib2(N) = _,_ <: fanflip(N) with {
   fanflip(4) = _,_,*(-1),*(-1);
   fanflip(N) = fanflip(N/2),fanflip(N/2);
};

zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax) =
   zita_in_delay(rdel)
 : zita_distrib2(N)
 : zita_rev_fdn(f1,f2,t60dc,t60m,fsmax)
 : output2(N)
with {
 N = 8;
 output2(N) = outmix(N) : *(t1),*(t1);
 t1 = 0.37; // zita-rev1 linearly ramps from 0 to t1 over one buffer
 outmix(4) = !,ro.butterfly(2),!; // probably the result of some experimenting!
 outmix(N) = outmix(N/2),par(i,N/2,!);
};

zita_light = hgroup("zita",(_,_ <: zita_rev1_stereo(rdel,f1,f2,t60dc,t60m,fsmax),_,_ : 
	out_eq,_,_ : dry_wet : out_level))
with{
	fsmax = 48000.0;  // highest sampling rate that will be used
	rdel = 60;
	f1 = 200;
	t60dc = 3;
	t60m = 2;
	f2 = 6000;
	out_eq = pareq_stereo(eq1f,eq1l,eq1q) : pareq_stereo(eq2f,eq2l,eq2q);
	pareq_stereo(eqf,eql,Q) = fi.peak_eq_rm(eql,eqf,tpbt), fi.peak_eq_rm(eql,eqf,tpbt)
	with {
		tpbt = wcT/sqrt(max(0,g)); // tan(PI*B/SR), B bw in Hz (Q^2 ~ g/4)
		wcT = 2*ma.PI*eqf/ma.SR;  // peak frequency in rad/sample
		g = ba.db2linear(eql); // peak gain
	};
	eq1f = 315;
	eq1l = 0;
	eq1q = 3;
	eq2f = 1500;
	eq2l = 0;
	eq2q = 3;
	dry_wet(x,y) = *(wet) + dry*x, *(wet) + dry*y 
	with {
		wet = 0.5*(drywet+1.0);
		dry = 1.0-wet;
	};
	drywet = vslider("dryWet",
		0,-1.0,1.0,0.01) : si.smoo;
	gain = vslider("level", -6, -70, 40, 0.1) : ba.db2linear : si.smoo;
	out_level = *(gain),*(gain);
};

process = zita_light;