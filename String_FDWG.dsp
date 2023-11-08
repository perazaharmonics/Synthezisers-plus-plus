declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");

import("filter.lib");

modelString(freq, feedback) = + ~ (fdelay4(1024, delLength) * (feedback))
with{
        delLength = SR / freq;

};

freq = hslider("freq", 440, 51, 2000, 0.01);
feedback = hslider("feedback", 0.9, 0, 1, 0.01);

process = modelString(freq, feedback);
/*process = no.noise : myOnePole;

myOnePole = + ~ ( _ * (-al) ) : @(delLength)
with {
  al = hslider("feedback gain[-1,1]", 0, -1, 1, 0.01) : si.smoo;
  delLength = hslider("delay length[1,2048]", 2048, 1, 2048, 1);
};
*/