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


#define N 4096



int main(int argc, char* argv[]) 
{
    complex_t x[N], y[N];


    randn((double*)x, 2*N, 0.0, 100.0);
    writebin(x, N, DAT_COMPLEX,  "dat/complex_in.bin");

    acos_cmplx(x, N, y);
    writebin(y, N, DAT_COMPLEX,  "dat/complex_acos.bin");


    asin_cmplx(x, N, y);
    writebin(y, N, DAT_COMPLEX,  "dat/complex_asin.bin");


    cos_cmplx(x, N, y);
    writebin(y, N, DAT_COMPLEX,  "dat/complex_cos.bin");


    log_cmplx(x, N, y);
    writebin(y, N, DAT_COMPLEX,  "dat/complex_log.bin");


    sin_cmplx(x, N, y);
    writebin(y, N, DAT_COMPLEX,  "dat/complex_sin.bin");


    sqrt_cmplx(x, N, y);
    writebin(y, N, DAT_COMPLEX,  "dat/complex_sqrt.bin");


    return 0;
}
