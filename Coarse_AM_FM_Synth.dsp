declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

// Definitions
carrierFreq = hslider("Carrier Frequency[Hz]", 440, 20, 2000, 0.01); 
modulatorFreq = hslider("Modulator Frequency[Hz]", 220, 20, 2000, 0.001);
index = hslider("FM Index", 100, 0, 1000, 0.001);
messageFreq = hslider("AM Message Frequency[Hz]", 1, 0.1, 10, 0.01); 
IMIntensity = hslider("Intermodulation Intensity", 0.1, 0, 1, 0.01);

// FM Modulation
fm = os.osc(carrierFreq + os.osc(modulatorFreq)*index);

// AM Modulation
am = os.osc(messageFreq);
amModulated = fm * am;

// Intermodulation: Using a simple polynomial as the nonlinearity
intermodSignal = (1 - IMIntensity) * amModulated + IMIntensity * (amModulated^2);

// Process
process = intermodSignal <: dm.zita_rev1;