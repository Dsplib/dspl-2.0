clear all; close all; clc;

addpath("functions")

[ar, n, m] = readbin("../dat/conv_double_a_in.bin");
[br, n, m] = readbin("../dat/conv_double_b_in.bin");
[cr, n, m] = readbin("../dat/conv_double_out.bin");


[ac, n, m] = readbin("../dat/conv_complex_a_in.bin");
[bc, n, m] = readbin("../dat/conv_complex_b_in.bin");
[cc, n, m] = readbin("../dat/conv_complex_out.bin");

zr = conv(ar, br);
zc = conv(ac, bc);

verification("conv for double  vector",  cr, zr);
verification("conv for complex  vector", cc, zc);


