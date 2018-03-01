/*
* Copyright (c) 2015-2017 Sergey Bakhurin
* Digital Signal Processing Library [http://dsplib.org]
*
* This file is part of DSPL.
*  
* is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DSPL is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include "dspl.h"


#define N 16

int main(int argc, char* argv[]) 
{

    double      k;
    double      ur[N], yr[N];
    complex_t   uc[N], yc[N];

    randu(&k, 1);
    randn(ur, N, 0.0, 10.0);
    randn((double*)uc, N*2, 0.0, 10.0);
    writebin(&k,  1, DAT_DOUBLE,   "dat/ellipj_k.bin");
    writebin(ur,  N, DAT_DOUBLE,   "dat/ellipj_ur.bin");
    writebin(uc,  N, DAT_COMPLEX,  "dat/ellipj_uc.bin");


    ellip_cd(ur, N, k, yr);
    ellip_cd_cmplx(uc, N, k, yc);
    writebin(yr,  N, DAT_DOUBLE,   "dat/ellipj_cdr.bin");
    writebin(yc,  N, DAT_COMPLEX,  "dat/ellipj_cdc.bin");


    ellip_sn(ur, N, k, yr);
    ellip_sn_cmplx(uc, N, k, yc);
    writebin(yr,  N, DAT_DOUBLE,   "dat/ellipj_snr.bin");
    writebin(yc,  N, DAT_COMPLEX,  "dat/ellipj_snc.bin");
        
    return 0;
}
