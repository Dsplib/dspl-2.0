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


#define N 10

int main(int argc, char* argv[]) 
{

    double    x[N];
    complex_t y[N];
    int res;

    linspace(0.0, N, N, DSPL_PERIODIC, x);
    linspace(0.0, 2.0*N, 2*N, DSPL_PERIODIC, (double*)y);
    
    res = writebin(x, N, DAT_DOUBLE,  "dat/writebin_double.bin");
    printf("res= %d\n", res);
    res = writebin(y, N, DAT_COMPLEX, "dat/writebin_complex.bin");
    printf("res= %d\n", res);

    return 0;
}
