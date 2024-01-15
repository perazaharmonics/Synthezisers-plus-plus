declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");
import("music.lib");
import("filter.lib");
// reflections imply attenuated feedbacks.... of course... attenuated sometimes by reflection filters

//to right of the feedback operator, i am making computations on the feedback loop (branch), vice-vera on the LHS 

// FIR Averaging Filter
// process = +~_ : + ~(*(0.25) + 0.25); RHS of the tilde operator

//process = (- : *(0.1))~_ : *(0.5) ; // LHS of the tilde operator example

// Echo - Filter

myEcho = _<:  *(dry) , (+~(fdelay(65536, delLength)*feedback*-1) : *(1 - dry)) :> _
with{
    delLength = hslider("[1]Time (ms)[style:knob]",250, 0.1, 1000, 0.1 )*0.001*SR : si.smoo; // applies to NSamples
    feedback = hslider("[2]Feedback[style:knob]",0, 0, 1, 0.0001):si.smoo;
    dry = hslider("[3]Dry[style:knob]", 1, 0, 1, 0.01) : si.smoo;
};

process = myEcho;


