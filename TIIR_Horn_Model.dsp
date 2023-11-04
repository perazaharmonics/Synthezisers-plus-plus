declare filename "untitled.dsp";
declare name "untitled";
import("music.lib");
import("stdfaust.lib");

// Parameters
frequency = hslider("frequency[Hz]", 440, 20, 5000, 0.01); // The fundamental frequency of the note
amplitude = hslider("amplitude", 0.5, 0, 1, 0.01); // The amplitude of the excitation
lip_stiffness = hslider("lip_stiffness", 0.7, 0, 1, 0.01); // Controls the nonlinearity of the lip model

// Nonlinear function to simulate lip buzzing
nonlinear_lip_model(x) = tanh(lip_stiffness * x);

// Sine wave oscillator
oscillator = os.osc(frequency) * amplitude;

// Excitation signal
excitation_signal = oscillator : nonlinear_lip_model;

// Define a one-pole TIIR filter with a delay to prevent endless cycles
// Define a one-pole TIIR filter with a single-sample delay to prevent cycles
// Define a one-pole TIIR filter
one_pole_tiir(R) = +(R) : *(1 - R*R) : @(1);



// Function to calculate stable one-pole TIIR filter coefficient from an unstable one
stable_coeff(unstable_coeff) = 1.0 / unstable_coeff;

// Reflection coefficient slider with values that ensure stability
reflection_coeff = hslider("reflection_coeff", 0.6, -0.99, 0.99, 0.01); 

// Calculation of the stable reflection coefficient
stable_R = stable_coeff(reflection_coeff);

// Apply the excitation signal to the TIIR filter and output the process
process = excitation_signal : one_pole_tiir(stable_R);
