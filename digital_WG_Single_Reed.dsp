declare filename "httpsfaustservicecloudgramefr.dsp";
declare name "httpsfaustservicecloudgramefr";
import("music.lib");
import("stdfaust.lib");

// Define the sampling frequency
fSamplingFreq = 44100; // CD quality sampling frequency

// Define the frequencies for each note
A3 = 220.0;
B3 = 247.5;
C4 = 261.63;
D4 = 293.66;
E4 = 329.63;
F4 = 349.23;
G4 = 392.00;

// Define Amplitude, gain and reed stiffness controls

reed_stiffness = hslider("reed_stiffness", 0.7, 0, 1, 0.01);
gain = hslider("gain[style:knob]", 0.5, 0, 1, 0.001);

bellfreq = nentry("bell_freq", 1000.0, 20.0, 20000.0,  1.0 ); // Bell frequency control, smoothed
bellQ = nentry("bell_Q", 0.707, 0.1, 10, 0.01); // Bell Q factor control, smoothed



// Define the buttons for each note
a_gate = button("A3");
b_gate = button("B3");
c_gate = button("C4");
d_gate = button("D4");
e_gate = button("E4");
f_gate = button("F4");
g_gate = button("G4");

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

// Define a high-pass filter for the bell effect
// High-pass filter definition to simulate the bell output
high_pass_filter(freq, Q, signal) = fi.highpass(3, hslider("lowfreq", 400, 20, 20000,1 ))(signal);



// Assuming `single_reed_digital_waveguide` outputs an audio signal,
// we will now apply the high-pass filter to it.
// ...
process = single_reed_digital_waveguide(active_freq, gate_with_env, fSamplingFreq, gain, 0.3)
          : high_pass_filter(bellfreq, bellQ, _);



