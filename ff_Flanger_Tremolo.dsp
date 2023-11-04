declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");
flanger(freq,wet,depth) = _ <: de.delay(256,d)*wet,_ :> /(2)
with{
    d = (os.osc(freq) + 1)*127*depth;
};
tremolo(freq,depth) = _*(1-(os.osc(freq)*0.5 + 0.5)*depth);
f = hslider("Frequency",10,0.1,100,0.01);
w = hslider("Wet",0.5,0,1,0.01);
d = hslider("Depth",0.5,0,1,0.01);
process = flanger(f,w,d) : tremolo(5,1) <: _,_;