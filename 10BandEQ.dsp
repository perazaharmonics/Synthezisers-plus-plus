declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");


bandsNumber = 10;


oneBand(i) = hgroup("Band- %i", fi.peak_eq(Lfx, fx, B))
with {
    highestBand = 10000;
    currentFreq = highestBand*(i+1) / bandsNumber;
    fx = hslider("[1]Freq[style:knob]", currentFreq, 0., 20000., 0.001);
    B = hslider("[2]Q factor[style:knob]", 100., 1., 44100, 0.01);
    Lfx = vslider("[3]Peak / Notch", 0, -60., 10, 0.1);

};

paramEqs(NBands) = hgroup("Parametric EQ",seq(i, NBands, oneBand(i)));
process = _ : paramEqs(bandsNumber);