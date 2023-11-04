declare filename "httpsfaustservicecloudgramefr.dsp";
declare name "httpsfaustservicecloudgramefr";
declare filename "ReedDWG_FM_Synthesis_With_Reverb.dsp";
declare name "Josué E. Peraza, B.Sc, M. EngEe";

import("music.lib");
import("stdfaust.lib");

// Define the sampling frequency
fSamplingFreq = 44100; // CD quality sampling frequency

// Define Amplitude, gain, reed stiffness, and embouchure offset controls
reed_stiffness = hslider("reed_stiffness", 0.7, 0, 1, 0.01);
gain = hslider("gain[style:knob]", 0.5, 0, 1, 0.001);
embouchure_offset = hslider("embouchure_offset", 0.0, -1.0, 1.0, 0.01);

// Define FM Synthesizer controls
carrierFreq = hslider("carrierFreq", 440.0, 20.0, 20000.0, 1.0); // Carrier frequency control
modulatorFreq = hslider("modulatorFreq", 220.0, 20.0, 20000.0, 1.0); // Modulator frequency control
fmindex = hslider("index", 1.0, 0.0, 10.0, 0.01); // Index control for FM modulation

// FM Synthesizer
fm_synthesizer = os.osc(carrierFreq + os.osc(modulatorFreq) * fmindex);

// Create a gate control
gate = button("gate");

// Excitation envelope (short burst when the gate is triggered)
excitation_env = en.adsr(0.01, 0.05, 0, 0.01, gate);

// Multiply the excitation envelope by the FM synthesizer signal
excited_fm_signal = fm_synthesizer * excitation_env;

// Add a wet/dry control for the reverb effect
dry = hslider("dry", 1, 0, 1, 0.01);
wet = hslider("wet", 0, 0, 1, 0.01);

// Apply the reverb effect
reverb_signal = excited_fm_signal <: dm.zita_rev1 : (_, _, dry, wet);

// Assuming `reverb_signal` outputs an audio signal, use it as the final output
process = reverb_signal;