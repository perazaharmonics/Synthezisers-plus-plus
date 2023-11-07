declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

process = no.noise : myOnePole;

myOnePole = + ~ ( _ * (-al) ) : @(delLength)
with {
  al = hslider("feedback gain[-1,1]", 0, -1, 1, 0.01) : si.smoo;
  delLength = hslider("delay length[1,2048]", 2048, 1, 2048, 1);
};
