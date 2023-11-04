declare filename "untitled.dsp";
declare name "untitled";

import("music.lib");
import("stdfaust.lib");

// Define the sampling frequency
fSamplingFreq = 44100; // CD quality sampling frequency

// Define Amplitude, gain, reed stiffness, and embouchure offset controls
reed_stiffness = hslider("reed_stiffness", 0.7, 0, 1, 0.01);
gain = hslider("gain[style:knob]", 0.5, 0, 1, 0.001);
embouchure_offset = hslider("embouchure_offset", 0.0, -1.0, 1.0, 0.01);

// Define the bell controls
bellfreq = nentry("bell_freq", 1000.0, 20.0, 20000.0, 1.0); // Bell frequency control, smoothed
bellQ = nentry("bell_Q", 0.707, 0.1, 10, 0.01); // Bell Q factor control, smoothed

// Excitation envelope (short burst when the gate is triggered)
excitation_env = en.adsr(0.01, 0.05, 0, 0.01, button("gate"));

// Multiply the gate by the envelope to apply it
gate_with_env = button("gate") * excitation_env;

// Define the reed table to simulate the behavior of the reed
reed_table(x, stiffness, embouchure_offset) = tanh(stiffness * (x - embouchure_offset));

// Define delay functions
delay_samples(freq) = int(fSamplingFreq / max(1.0f, freq)); // Ensures freq is not zero to avoid division by zero.

delay_line(freq, signal) = signal + @(delay_samples(freq));

// Feedback delay line with a fixed amount of attenuation for feedback
feedback_delay_line(nMax, n, attenuation) =
    +(+(attenuation)) ~ de.fdelay4(nMax, n);

// The digital waveguide model of the single-reed instrument with a feedback delay network
single_reed_digital_waveguide(freq, gate, sr, gain, attenuation) =
    gate
    : reed_table(_, reed_stiffness, embouchure_offset)
    : feedback_delay_line(delay_samples(freq), freq, attenuation)
    : *(gain);

// Define a high-pass filter for the bell effect
// High-pass filter definition to simulate the bell output
high_pass_filter(freq, Q, signal) = fi.highpass(3, hslider("lowfreq", 400, 20, 20000, 1))(signal);

// Assuming `single_reed_digital_waveguide` outputs an audio signal,
// we will now apply the high-pass filter to it.
process = single_reed_digital_waveguide(button("gate") * 440.0, gate_with_env, fSamplingFreq, gain, 0.3)
          : high_pass_filter(bellfreq, bellQ, _);