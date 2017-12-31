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


#define N 32


int main(int argc, char* argv[]) 
{

    double    xr[N];
    complex_t xc[N], yr[N], yc[N];
    int ind[N], k;

    randu(xr, N);
    randu((double*)xc, 2*N);

    for(k = 0; k < N; k++)
        ind[k] = k;

    goertzel(xr, N, ind, N, yr);
    goertzel_cmplx(xc, N, ind, N, yc);

    writebin(xr, N, DAT_DOUBLE,  "dat/goertzel_double_in.bin");
    writebin(yr, N, DAT_COMPLEX, "dat/goertzel_double_out.bin");

    writebin(xc, N, DAT_COMPLEX, "dat/goertzel_complex_in.bin");
    writebin(yc, N, DAT_COMPLEX, "dat/goertzel_complex_out.bin");
 
    return 0;
}
