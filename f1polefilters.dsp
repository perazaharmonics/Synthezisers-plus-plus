declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

smooth(coeff, x) = fb ~ _ with { fb(y) = y + (1.0 - coeff) * (x - y); };
c = 1.0 - 44.1 / ma.SR;
smooth3(coeff, x) = fb ~ _ with { fb(y) = coeff * (y - x) + x; };

// Process each channel with a different smoothing function
process = _ <: si.smooth(c), smooth(c), smooth3(c);
