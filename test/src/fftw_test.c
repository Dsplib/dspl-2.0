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
#include <stdlib.h>
#include <math.h>
#include "dspl.h"
#include "fftw3.h"



#define N 16

int main(int argc, char* argv[]) {
    complex_t *in = NULL, *out= NULL;
    void* pfftw;
    int k;


    in  = (complex_t*) malloc(sizeof(complex_t) * N);
    out = (complex_t*) malloc(sizeof(complex_t) * N);
    
    pfftw = (void*)fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
 

    for(k = 0; k < N; k++)
    {
        RE(in[k]) = (double)k;
        IM(in[k]) = 0.0;
    } 


    fftw_execute(pfftw);  // repeat as needed 


    for(k = 0; k < N; k++)
        printf("%.3d%12.2f%12.2f%12.2f%12.2f\n", 
        k, RE(in[k]), IM(in[k]), RE(out[k]), IM(out[k]));


    fftw_destroy_plan(pfftw);
    fftw_free(in); 
    fftw_free(out);
    

    return 0;
}
