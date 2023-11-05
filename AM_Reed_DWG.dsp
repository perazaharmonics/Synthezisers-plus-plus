declare filename "untitled.dsp";
declare name "untitled";
declare filename "ReedDWG_AM_Synthesis.dsp";
declare name "Josué E. Peraza, B.Sc, M. EngEe";

import("music.lib");
import("stdfaust.lib");

// Define the sampling frequency
fSamplingFreq = 44100; // CD quality sampling frequency

// Grouped Controls
gain = hslider("gain[style:knob]", 0.5, 0, 1, 0.001);
reed_stiffness=hslider("reed_stiffness", 0.7, 0, 1, 0.1);
embouchure_offset = hslider("embouchure_offset", 0.0, -1.0, 1.0, 0.01);
reed_group = hgroup("Reed Parameters", reed_stiffness, embouchure_offset);

carrierFreq = hslider("[0]carrierFreq[Carrier Frequency]", 440.0, 20.0, 20000.0, 1.0);modulatorFreq = hslider("[1]modulatorFreq[Modulator Frequency]", 1.0, 0.1, 20.0, 0.1);

modulationIndex = hslider("[2]modulationIndex[Modulation Index]", 1.0, 0.0, 10.0, 0.001);

mod_group = hgroup("AM Tune", carrierFreq, modulatorFreq, modulationIndex);

gate=button("gate");

reflection_cutoff = hslider("[0]reflection_cutoff[Reflection Lowpass Cutoff]", 5000, 20, 10000, 1);
radiation_cutoff = hslider("[1]radiation_cutoff[Radiation highpass Cutoff]", 1000, 20, 5000, 1);

filt_group=vgroup("Horn Tune", reflection_cutoff, radiation_cutoff);



// AM Synthesizer
am_synthesizer = os.osc(carrierFreq) * (1 + os.osc(modulatorFreq) * modulationIndex);

// Envelope Generator (unchanged)
excitation_env = en.adsr(0.01, 0.05, 0, 0.01, gate);

// Excited AM Signal
excited_am_signal = am_synthesizer * excitation_env * gain;

// Reflection and Radiation functions (unchanged)
reflection_function(cutoff) = _ <: _,_ : *(0.5),*(0.5) :> _ : fi.lowpass(1, cutoff);
radiation_function(cutoff) = fi.highpass(1, cutoff);

// Delay line (unchanged)
maxdelay = fSamplingFreq;
reed_delay = delay(maxdelay, fSamplingFreq / carrierFreq);

// Waveguide (unchanged)
waveguide(signal) = signal <: reed_delay, reed_delay : reflection_function(reflection_cutoff), radiation_function(radiation_cutoff) :> _ + _;

// Process (updated with AM synth signal)
process = waveguide(excited_am_signal);