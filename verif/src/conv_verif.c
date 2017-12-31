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
#define M 64


int main(int argc, char* argv[]) 
{

    double    ar[N], br[M], cr[N+M-1];
    complex_t ac[N], bc[M], cc[N+M-1];

    randu(ar, N);
    randu(br, M);
    conv(ar, N, br, M, cr);    

    writebin(ar, N, DAT_DOUBLE,  "dat/conv_double_a_in.bin");
    writebin(br, M, DAT_DOUBLE,  "dat/conv_double_b_in.bin");
    writebin(cr, M+N-1, DAT_DOUBLE,  "dat/conv_double_out.bin");

    randu((double*)ac, 2*N);
    randu((double*)bc, 2*M);
    conv_cmplx(ac, N, bc, M, cc);

    writebin(ac, N, DAT_COMPLEX,  "dat/conv_complex_a_in.bin");
    writebin(bc, M, DAT_COMPLEX,  "dat/conv_complex_b_in.bin");
    writebin(cc, M+N-1, DAT_COMPLEX,  "dat/conv_complex_out.bin");    
    
    return 0;
}
