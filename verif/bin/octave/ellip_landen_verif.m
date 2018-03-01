clear all; close all; clc;

addpath("functions")

[k, n, m] = readbin("../dat/ellip_landen_in.bin");
[y, n, m] = readbin("../dat/ellip_landen_out.bin");


z = landen(k, length(y));

verification("ellip_landen",  y, z);


