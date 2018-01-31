clear all; close all; clc;

addpath("functions")

[x, n, m] = readbin("../dat/complex_in.bin");

[y, n, m] = readbin("../dat/complex_cos.bin");
z = cos(x);
verification("complex cosine vector",  y, z);

[y, n, m] = readbin("../dat/complex_sin.bin");
z = sin(x);
verification("complex sine vector",  y, z);


[y, n, m] = readbin("../dat/complex_sqrt.bin");
z = sqrt(x);
verification("complex sqrt vector",  y, z);


