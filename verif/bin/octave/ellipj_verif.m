clear all; close all; clc;

addpath("functions")

[k, n, m] = readbin("../dat/ellipj_k.bin");
[ur, n, m] = readbin("../dat/ellipj_ur.bin");
[uc, n, m] = readbin("../dat/ellipj_uc.bin");

[ycdr, n, m] = readbin("../dat/ellipj_cdr.bin");
[ycdc, n, m] = readbin("../dat/ellipj_cdc.bin");

[ysnr, n, m] = readbin("../dat/ellipj_snr.bin");
[ysnc, n, m] = readbin("../dat/ellipj_snc.bin");

[zcdr, zsnr] = ellipj_func(k, ur, 16);
[zcdc, zsnc] = ellipj_func(k, uc, 16);

verification("ellipj_cd for real",     ycdr, zcdr);
verification("ellipj_cd for complex",  ycdc, zcdc);
verification("ellipj_sn for real",     ysnr, zsnr);
verification("ellipj_sn for complex",  ysnc, zsnc);
