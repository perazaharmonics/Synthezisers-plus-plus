declare filename "untitled.dsp";
declare name "untitled";
import ("stdfaust.lib");
import("filters.lib");
import("envelopes.lib");
/*// 
distortion = +(offset) : *(pregain) :  clip(-1, 1) : cubic : fi.dcblocker
with {
        //cutoff = hslider("Cutoff",);
        
        drive = hslider("Drive[style:knob]", 0, 0, 1, 0.001) : si.smooth(0.9999);
        offset = hslider("DC Offset[style:knob]", 0, -0.1, 0.1, 0.001) : si.smooth(0.99999);
        pregain =  pow(10, drive*2) ; // linearization
        clip(lo , hi) =  min(hi) : max(lo);
        cubic(x) = x - pow(3, x) / 3; 
};*/ 

// Scroeder Allpass Comb Filter
/*allpass_fcomb1(maxdel, N, aN) = (+ <: de.delay(maxdel,N-1),*(aN)) : mem, _: +; */ 





// Direct Form-II Bi-Quads Section

tf22a(b0,b1,b2,a1,a2) = // tf2, direct-form 2:
    _ : (((_,_,_:>_)~*(-a1)<:mem,*(b0))~*(-a2))
      : (_<:mem,*(b1)),_ : *(b2),_,_ :> _;

/*lf_pulsetrain1(freq,duty) = 2.0*os.lf_pulsetrainpos(freq,duty) - 1.0
with{

    freq = 389;
    duty = 0.32;
};*/ 

/*flanger_stereo(dmax,curdel1,curdel2,depth,fb,invert) = dm.pf.flanger_mono(dmax,curdel1,curdel2,depth,fb,invert), dm.pf.flanger_mono(dmax,curdel1,curdel2,depth,fb,invert)
with{
        dmax = 0.1;
        curdel1 = 0.5;
        curdel2 = 0.33;
        depth = hslider("Depth[style:knob]", 0, 0, 1, 1);
        fb = hslider("Feedback[style:knob]", 0.5, 0, 1, 0.001);




};*/

fdelay1(n,d,x) = de.delay(n+1,int(d),x)*(1 - ma.frac(d)) + de.delay(n+1,int(d)+1,x)*ma.frac(d)

with{
        n = hslider("Max Delay Length[style:knob]", 1000, 0, 20000, 0.01) ;
        d = hslider("Fractional Delay Length[style:knob]", 10, 0, 1000, 0.001);


};



freqs = (hslider("Carrier Freq[style:knob]", 88, 0, 400, 0.0001), hslider("Message Freq 1 [style:knob]", 34, 0, 1000, 0.001), hslider("Message Freq 2 [style:knob]", 34, 0, 100, 0.001));
indices = (20, 300, 1000);


//freqs = (carrier, message1, message2);

gate = button("gate");
lowshelfa(n, len, bw) = fi.filterbank(n,(bw)) : _, *(ba.db2linear(len)) :> _;
process = hgroup("Synth", sy.fm(freqs, indices) * gate) <:  fdelay1 :>  tf22a(0.3, 0.44, 0.6, -0.44, 0.3) : si.smoo;