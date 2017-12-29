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

#ifndef DSPL_H
#define DSPL_H

#include <math.h>
#include "common.h"



#define DSPL_SYMMETRIC  0x00000000
#define DSPL_PERIODIC  0x00000001


int conv(double* a, int na, double* b, int nb, double* c);
int conv_cmplx(complex_t* a, int na, complex_t* b, int nb, complex_t* c);



int dft(double* x, int n, complex_t *y);
int dft_cmplx(complex_t* x, int n, complex_t *y);



int fft_shift(double* x, int n, double* y);


int linspace(double x0, double x1, int n, int type, double* x);
int logspace(double x0, double x1, int n, int type, double* x);



int polyval(double* a, int ord, double* x, int n, double* y);
int polyval_cmplx(complex_t* a, int ord, complex_t* x, int n, complex_t* y);



int randn(double* x, int n, double mu, double sigma);
int randu(double* x, int n);

#endif
 
