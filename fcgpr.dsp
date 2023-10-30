declare filename "untitled.dsp";
declare name "untitled";
process = firpart : + ~ feedback
with {
bw = 100; fr = 1000; g = 1; // parameters - see caption
SR = fconstant(int fSamplingFreq, <math.h>);
pi = 4*atan(1.0); // circumference over diameter
R = exp(-pi*bw/SR); // pole radius
A = 2*pi*fr/SR; // pole angle (radians)
RR = R*R;
firpart(x) = (x - x@(2)) * g * (1-RR)/2;
// time-domain coefficients ASSUMING ONE-SAMPLE FEEDBACK DELAY:
feedback(x) = 0 + 2*R*cos(A)*x - RR*(x: mem);
};
