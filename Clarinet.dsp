declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

blow(pressure, breathGain, breathCutoff, vibratoFreq, vibratoGain) = pressure + vibrato + breathNoise
with {
        vibrato = os.osc(vibratoFreq) * vibratoGain;
        breathNoise = no.noise : fi.lowpass(2, breathCutoff) : *(pressure*breathGain);


};

digWG_ud(nMax, n) = par(i, 2, de.fdelay(nMax, n)), _;
bridgefilter1(brightness, absorption, x) = rho * (h0 * x' + h1*(x + x''))
with {
        freq = 320;
        t60 = (1.0 - absorption)*20.0;
        h0 = (1.0 + brightness) * 0.5;
        h1 = (1.0 - brightness) * 0.25;
        rho = pow(0.001, 1.0 / (freq*t60));


} ;

wBell(opening) = pm.rTermination(pm.basicBlock, si.smooth(opening));
process = blow <:  digWG_ud(1, 1) : bridgefilter1 <: _, _, _, _ : wBell :> _;