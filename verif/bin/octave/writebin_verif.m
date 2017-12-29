clear all; close all; clc;

addpath("functions")

[r, n, m] = readbin("../dat/writebin_double.bin");
[c, n, m] = readbin("../dat/writebin_complex.bin");

r0 = linspace(0,9,10).';
c0 = linspace(0,19,20).';
c0 = c0(1:2:end) + 1i * c0(2:2:end); 

verification("writebin for double  vector", r, r0);
verification("writebin for complex vector", c, c0);

