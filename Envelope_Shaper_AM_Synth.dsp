declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");
// Parameters for the ADSR envelope
attack = hslider("Attack [0:1]", 0.01, 0.0, 1.0, 0.01);
decay = hslider("Decay [0:1]", 0.1, 0.0, 1.0, 0.01);
sustain = hslider("Sustain[0:1]", 0.5, 0.0, 1.0, 0.01 ); 
release = hslider("Release[0:1]", 0.5, 0.0, 1.0, 0.01 );
gate = button("gate");
freq = hslider("Freq", 440, 0.0, 18000, 1.0);

// Oscillators
osc1 = os.osc(freq);
osc2 = os.osc(2 * freq);
osc3 = os.osc(3 * freq);

// ADSR envelope
adsr(A, D, S, R) = si.smoo(A) * gate - si.smoo(D) * (1 - S) * gate + S * gate : *(1 - gate) + si.smoo(R) * S : *(gate);

// Combine the oscillators and modulate with the envelope
super_sig = (osc1 + osc2 + osc3) * 0.33;  // Reduce amplitude since we're adding 3 signals

// Modulating White Noise with the envelope
process = super_sig* adsr(attack, decay, sustain, release) <: _,_;
/*
Process:
 noise_gen * envelope multiplies the White Noise Generator by the envelop
 <: is Faust's parallel operator. It take L-R channels from the left and routes them to channels on the right.
 _,_ splits the signal into two channels making it stereo 

*\