clear all; close all; clc;

addpath("functions")

[xr, n, m] = readbin("../dat/dft_double_in.bin");
[xc, n, m] = readbin("../dat/dft_complex_in.bin");
[yr, n, m] = readbin("../dat/dft_double_out.bin");
[yc, n, m] = readbin("../dat/dft_complex_out.bin");

zr = fft(xr);
zc = fft(xc);

verification("dft for double  vector",  yr, zr);
verification("dft for complex  vector", yc, zc);


