declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");
import("delays.lib");
//-------------------------------------------------------------------------
// Shared Control Parameters
//-------------------------------------------------------------------------
attack = hslider("Attack [0:1]", 0.01, 0.0, 1.0, 0.01);
decay = hslider("Decay [0:1]", 0.1, 0.0, 1.0, 0.01);
sustain = hslider("Sustain[0:1]", 0.7, 0.0, 1.0, 0.01);
release = hslider("Release[0:1]", 0.5, 0.0, 1.0, 0.01);
octave = hslider("Octave[-3:3]", 0, -3, 3, 1) : int;
gain = hslider("gain[style:knob]", 0.5, 0, 1, 0.001);

//-------------------------------------------------------------------------
// LFO Synthesizer Parameters
//-------------------------------------------------------------------------
// Chorus parameters
delayTime = hslider("Chorus Delay Time[ms]", 15, 0, 50, 0.1);
depth = hslider("Chorus Depth[ms]", 2, 0, 20, 0.1);
rate = hslider("Chorus Rate[Hz]", 1.5, 0.1, 5, 0.01);

//-------------------------------------------------------------------------
// ReedDWG AM Synthesis Parameters
//-------------------------------------------------------------------------
reed_stiffness = hslider("reed_stiffness", 0.7, 0, 1, 0.1);
embouchure_offset = hslider("embouchure_offset", 0.0, -1.0, 1.0, 0.01);
reed_group = hgroup("Reed Parameters", reed_stiffness, embouchure_offset);

carrierFreq = hslider("[0]carrierFreq[Carrier Frequency]", 440.0, 20.0, 20000.0, 1.0);
modulatorFreq = hslider("[1]modulatorFreq[Modulator Frequency]", 1.0, 0.1, 20.0, 0.1);
modulationIndex = hslider("[2]modulationIndex[Modulation Index]", 1.0, 0.0, 10.0, 0.001);
mod_group = hgroup("AM Tune", carrierFreq, modulatorFreq, modulationIndex);

gate = button("gate");
reflection_cutoff = hslider("[0]reflection_cutoff[Reflection Lowpass Cutoff]", 5000, 20, 10000, 1);
radiation_cutoff = hslider("[1]radiation_cutoff[Radiation highpass Cutoff]", 1000, 20, 5000, 1);
filt_group = vgroup("Horn Tune", reflection_cutoff, radiation_cutoff);

//-------------------------------------------------------------------------
// Combined Process
//-------------------------------------------------------------------------
// Common ADSR envelope
adsr_env = en.adsr(attack, decay, sustain, release, gate);

// LFO Synthesizer Process
lfo = (os.osc(rate) + 1) * (depth/2);

reed_delay = de.fdelay(maxdelay, int(ma.SR / carrierFreq));


maxdelay = ma.SR; // Max delay in samples, using the current sampling rate
// Define the maximum delay time in samples
maxDelayInSamples = 44100; // 1 second at 44.1kHz

// Create a delay line with a variable delay time
modulableDelayLine(delayInSamples) = fdelay(maxDelayInSamples, delayInSamples);

modulatedDelaySamples = int((delayTime + lfo) * ma.SR / 1000);
maxDelaySamples = int(maxdelay * ma.SR / 1000);  // Max delay in samples
modulatedDelayTime = delayTime + lfo;  // Fractional delay time

// Define the chorus delay line using fractional delay (fdelay)
delayed(signal) = fdelay(maxDelaySamples, modulatedDelayTime, signal);


// Assuming modulatedDelaySamples gives the delay in samples


// Chorus effect for a single input signal
chorusEffect(signal) = 
(
    signal,               // dry signal
    delayed(signal)       // wet signal (with chorus delay applied)
) :> _;  // Sum the dry and wet signals


osc(freq) = os.osc(freq * pow(2, octave)) * adsr_env;
oscA = osc(440.00);
oscB = osc(493.88);
oscC = osc(261.63);
oscD = osc(293.66);
oscE = osc(329.63);
oscF = osc(349.23);
oscG = osc(392.00);
combined = oscA + oscB + oscC + oscD + oscE + oscF + oscG;
processedLFO = combined : chorusEffect;

// ReedDWG AM Synthesis Process
am_synthesizer = os.osc(carrierFreq) * (1 + os.osc(modulatorFreq) * modulationIndex);
excited_am_signal = am_synthesizer * adsr_env * gain;

// Reflection and Radiation functions
reflection_function(cutoff) = _ <: _,_ : *(0.5),*(0.5) :> _ : fi.lowpass(1, cutoff);
radiation_function(cutoff) = fi.highpass(1, cutoff);


waveguide(signal) = signal <: reed_delay, reed_delay : reflection_function(reflection_cutoff), radiation_function(radiation_cutoff) :> _ + _;
processedAM = waveguide(excited_am_signal);

// Mix both synthesizer signals
process = (processedLFO * 0.5 + processedAM * 0.5) <: _,_;