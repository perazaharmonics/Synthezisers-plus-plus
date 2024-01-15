declare filename "untitled.dsp";
declare name "untitled";
declare filename "LFO.dsp";
declare name "Josue Enrique Peraza Velazquez, B.Sc.EE, M.Eng.EE, M.Eng.EE";
import("stdfaust.lib");
import("music.lib");
import("filter.lib");

myOnePole =  +~(*(-a1)) 
with{
 
    a1 = nentry("[2]a1[style:knob]",0.10, -0.93, 0.93, 0.0001):si.smoo;
 
};



stereoRingMod = _ <: *(1 - pan), *(pan)
with{
    pan = 1 - depth*(os.lf_rawsaw(freq)*(0.5+0.5));
    depth = hslider("[3]Depth[style:knob]", 0, 0, 1, 0.01) : si.smooth(0.999);
    freq = hslider("[4]Freq[style:knob]", 5.0, 0.01, 1000, 0.01) : si.smooth(0.999);
};

g1 = vslider("[6] Gain[style:knob]", 0.2, 0, 0.997, 0.0001); 


myEcho = _<:  *(dry) , (+~(fdelay(65536, delLength)*feedback*-1) : *(1 - dry)) :> _
with{
    delLength = hslider("[7]Time (ms)[style:knob]",250, 0.1, 1000, 0.1 )*0.001*SR : si.smoo; // applies to NSamples
    feedback = hslider("[8]Feedback[style:knob]",0, 0, 1, 0.0001):si.smoo;
    dry = hslider("[9]Dry[style:knob]", 1, 0, 1, 0.01) : si.smoo;
};


lfo = hslider("Osc[style:knob][units:linear]", 1, 0.1, 20, 0.01);
gate = button("Gate");
source = os.quadosc(lfo);




process =  hgroup("Ring Modulation",  gate*(source :> stereoRingMod:> myEcho : myOnePole)) ;