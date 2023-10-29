declare filename "untitled.dsp";
declare name "untitled";
// General Linear System State-Space Model

import("stdfaust.lib");

p = 2; //number of inputs
q = 3; // Number of output
N = 5; //Number of States

A = matrix(N, N); //state transition matrix map
B = matrix(N, p); // input-to-states matrix map
C = matrix(q, N); // states-to-output matrix map
D = matrix(q, p); // direct-term-matrix, bypassing state

matrix(M, N) = tgroup("Matrix: %M x %N", par(in, N, _) <: par(out, M, mixer(N, out))) with {

fader(in) = ba.db2linear(vslider("Input %in", -10, -96, 4, 0.1));
mixer(N, out) = hgroup("Output %out", par(in, N, *(fader(in)) ) :> _);
};

Bd = par(i, p, mem) : B; // input delay needed for conventional definition
vsum(N) = si.bus(2*N) :> si.bus(N); // vector sum of two N-vectors
impulse = 1 - 1'; // For zero initial state, set impulse = 0 or simplify code
x0 = par(i, N, i*impulse); // intia; state = (0, 1, 2, 3, ..., N-1)


system = si.bus(p) <: D, (Bd : vsum(N)~(A), x0 : vsum(N) : C) :> si.bus(q);

process = system;