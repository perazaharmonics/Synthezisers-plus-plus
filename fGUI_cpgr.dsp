declare filename "untitled.dsp";
declare name "untitled";
// Controls
fr = nentry("frequency (Hz)", 1000, 20, 20000, 1);
bw = nentry("bandwidth (Hz)", 100, 20, 20000, 10);
g = hslider("peak gain", 1, 0, 10, 0.01);


/* Constants (FAUST provides these in math.lib)*/
SR = fconstant(int fSamplingFreq, <math.h>);
PI = 3.1415926535897932385;

/* The resonator*/

/* The resonator */
process = firpart : + ~ feedback
with {
R = exp(-PI*bw/SR); // pole radius
A = 2*PI*fr/SR; // pole angle (radians)
RR = R*R;
firpart(x) = (x - x@(2)) * g * (1-RR)/2;
// time-domain coefficients ASSUMING ONE-SAMPLE FEEDBACK DELAY:
feedback(v) = 0 + 2*R*cos(A)*v - RR*v@(1);
};