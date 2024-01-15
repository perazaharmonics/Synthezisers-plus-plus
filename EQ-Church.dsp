declare filename "untitled.dsp";
declare name "untitled";
declare filename "Spooky Non-Clippy Church Bell.dsp";
declare name "Josué E. Peraza, B.Sc, M. EngEe";

import("music.lib");
import("stdfaust.lib");

mychurchBell = vgroup("[0]Church Bell",pm.churchBell(strikePosition, strikeCutoff,strikeSharpness, gain, gate))
with {
    strikePosition = nentry("v:churchBell/[0]strikePosition", 0, 0, 4, 1);
    strikeCutoff = hslider("v:churchBell/[1]strikeCutoff", 6500, 20, 20000, 1);
    strikeSharpness = hslider("v:churchBell/[2]strikeSharpness",
	0.5,0.01,5,0.01);
    gain = hslider("v:churchBell/[3]gain", 1, 0, 1, 0.01);
    gate = button("v:churchBell/[4]gate");

};

// Echo
myEcho = hgroup("Echo Filter",_<:  *(dry) , (+~(fdelay(65536, delLength)*feedback*-1) : *(1 - dry)) :> _ )
with{
    delLength = hslider("[1]Time (ms)[style:knob]",250, 0.1, 1000, 0.1 )*0.001*SR : si.smooth(0.4337); // applies to NSamples
    feedback = hslider("[2]Feedback[style:knob]",0, 0, 1, 0.0001):si.smoo;
    dry = hslider("[3]Dry[style:knob]", 1, 0, 1, 0.01) : si.smoo;
   
};

bandsNumber = 10;


oneBand(i) = hgroup("Band- %i", fi.peak_eq(Lfx, fx, B))
with {
    highestBand = 10000;
    currentFreq = highestBand*(2*i+1) / bandsNumber;
    fx = nentry("[1]Freq", currentFreq, 0., 20000., 0.001);
    B = hslider("[2]Q factor[style:knob]", 100., 1., 44100, 0.01);
    Lfx = vslider("[3]Peak / Notch", 0, -60., 10, 0.1);

};

paramEqs(NBands) = hgroup("Parametric EQ",seq(i, NBands, oneBand(i)));


myDCblock = fi.dcblockerat(70) : si.smooth(0.441);


process = mychurchBell :myEcho <: paramEqs (bandsNumber) : myDCblock;