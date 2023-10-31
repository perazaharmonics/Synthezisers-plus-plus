declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

// Oscillator and gains definitions
freq0 = hslider("wave_1[freq]", 440, 0, 21200, .001);
gain0 = hslider("Amplitude_1 [gain]", 0.5, 0, 1, 0.001);

freq1 = hslider("wave_2[freq]", 130.81, 0, 21200, .01);
gain1 = hslider("Amplitude_2 [gain]", 0.5, 0, 1, 0.001);

attack = hslider("Attack [0:1]", 0.01, 0.0, 1.0, 0.01);
decay = hslider("Decay [0:1]", 0.1, 0.0, 1.0, 0.01);
sustain = hslider("Sustain[0:1]", 0.5, 0.0, 1.0, 0.01 ); 
release = hslider("Release[0:1]", 0.5, 0.0, 1.0, 0.01 );
gate = button("gate");


// ADSR envelope
adsr(A, D, S, R) = si.smoo(A) * gate - si.smoo(D) * (1 - S) * gate + S * gate : *(1 - gate) + si.smoo(R) * S : *(gate);

// Create oscillators with the defined frequencies and gains
osc0 = os.osc(freq0) * gain0;
osc1 = os.osc(freq1) * gain1;

supersig = (osc0 + osc1) * 0.5;
// Merge signals, replicate to stereo, and process with reverb
process = supersig* adsr(attack, decay, sustain, release) <: _,_ : dm.zita_rev1;