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

int main(int argc, char* argv[]) {

    double    x[N];
    complex_t y[N];
    int res;

    linspace(0.0, 1.0,   N, DSPL_SYMMETRIC, x);
    linspace(0.0, 1.0, 2*N, DSPL_SYMMETRIC, (double*)x);
    
    writebin(x, N, DAT_DOUBLE,  "test_double.bin");
    writebin(y, N, DAT_COMPLEX, "test_complex.bin");
    return 0;
}
