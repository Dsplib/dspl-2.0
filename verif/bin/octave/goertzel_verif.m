clear all; close all; clc;

addpath("functions")

[xr, n, m] = readbin("../dat/goertzel_double_in.bin");
[yr, n, m] = readbin("../dat/goertzel_double_out.bin");

[xc, n, m] = readbin("../dat/goertzel_complex_in.bin");
[yc, n, m] = readbin("../dat/goertzel_complex_out.bin");

zr = fft(xr);
zc = fft(xc);

verification("goertzel for double  vector", yr, zr);
verification("goertzel for complex vector", yc, zc);


