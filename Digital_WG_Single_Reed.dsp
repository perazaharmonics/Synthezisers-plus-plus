declare filename "untitled.dsp";
declare name "untitled";
import("music.lib");
import("stdfaust.lib");
import("filters.lib");

// Oscillator and gains definitions
freq0 = hslider("wave_1[freq]", 440, 0, 21200, .001);
gain0 = hslider("Amplitude_1 [gain]", 0.5, 0, 1, 0.001);

// Create oscillators with the defined frequencies and gains
osc0 = os.osc(freq0) * gain0;

reflection_filter(signal) = signal * 0.7 + (+(signal * 0.3) ~ _);



// Define the reed table to simulate the behavior of the reed
reed_table(x, stiffness) = tanh(stiffness * x);


// Define delay functions
// This computes the number of samples needed to create a delay line for a given frequency.
delay_samples(freq) = int(fSamplingFreq / max(1.0f, freq)); // Ensures freq is not zero to avoid division by zero.


delay_line(freq, signal) = signal + @(delay_samples(freq));

// Feedback delay line with a fixed amount of attenuation for feedback
feedback_delay_line(nMax, n, attenuation) =
    +(+(attenuation)) ~ de.fdelay4(nMax, n);

// The digital waveguide model of the single-reed instrument with a feedback delay network
single_reed_digital_waveguide(freq, gate, sr, gain, attenuation) =
    gate
    : reed_table(_, reed_stiffness)
    : feedback_delay_line(delay_samples(freq), freq, attenuation)
    : *(gain);
fSamplingFreq = 44100; // CD quality sampling frequency

// Define the frequencies for each note
A3 = os.osc(220.0);
B3 = os.osc(247.5);
C4 = os.osc(261.63);
D4 = os.osc(293.66);
E4 = os.osc(329.63);
F4 = os.osc(349.23);
G4 = os.osc(392.00);

// Define Amplitude, gain and reed stiffness controls

reed_stiffness = hslider("reed_stiffness", 0.7, 0, 1, 0.01);
gain = hslider("gain[style:knob]", 0.5, 0, 1, 0.001);

bellfreq = nentry("bell_freq", 1000.0, 20.0, 20000.0,  1.0 ); // Bell frequency control, smoothed
bellQ = nentry("bell_Q", 0.707, 0.1, 10, 0.01); // Bell Q factor control, smoothed



// Define the buttons for each note
a_gate = si.smoo(button("A4"));
b_gate = si.smoo(button("B4"));
c_gate = si.smoo(button("C4"));
d_gate = si.smoo(button("D4"));
e_gate = si.smoo(button("E4"));
f_gate = si.smoo(button("F4"));
g_gate = si.smoo(button("G4"));

// Convert button presses into impulses
a_impulse = a_gate : ba.impulsify;
b_impulse = b_gate : ba.impulsify;
c_impulse = c_gate : ba.impulsify;
d_impulse = d_gate : ba.impulsify;
e_impulse = e_gate : ba.impulsify;
f_impulse = f_gate : ba.impulsify;
g_impulse = g_gate : ba.impulsify;

// Define active frequency signal by summing all impulse signals multiplied by their frequencies
active_freq = a_impulse * A3 + b_impulse * B3 + c_impulse * C4 + d_impulse * D4 + e_impulse * E4 + f_impulse * F4 + g_impulse * G4;

// Define the active gate signal by summing all impulse signals
active_gate = a_impulse + b_impulse + c_impulse + d_impulse + e_impulse + f_impulse + g_impulse;

// Excitation envelope (short burst when the gate is triggered)
excitation_env = en.adsr(0.01, 0.05, 0, 0.01, active_gate);

// Multiply the gate by the envelope to apply it
gate_with_env = active_gate * excitation_env;

process = single_reed_digital_waveguide(active_freq, gate_with_env, fSamplingFreq, gain, 0.7) : reflection_filter;

