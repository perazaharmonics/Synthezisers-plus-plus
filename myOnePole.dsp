declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");
myOnePole =  +~(*(-a1)) 
with{
 
    a1 = hslider("[2]a1[style:knob]",0.5, -0.93, 0.93, 0.0001):si.smoo;
 
};

process = _ : myOnePole;