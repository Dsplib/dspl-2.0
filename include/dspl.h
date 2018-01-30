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



typedef struct{
    void      *pfftw;
    complex_t *in;
    complex_t *out;
    size_t     size;
} fft_t;




#define DSPL_SYMMETRIC                  0x00000000
#define DSPL_PERIODIC                   0x00000001

#define DSPL_WIN_SYM_MASK               0x00000001
#define DSPL_WIN_MASK                   0x000FFFFE

#define DSPL_WIN_SYMMETRIC              DSPL_SYMMETRIC
#define DSPL_WIN_PERIODIC               DSPL_PERIODIC


#define DSPL_WIN_BARTLETT               0x00000004
#define DSPL_WIN_BARTLETT_HANN          0x00000008	
#define DSPL_WIN_BLACKMAN               0x00000010			
#define DSPL_WIN_BLACKMAN_HARRIS        0x00000040	 
#define DSPL_WIN_BLACKMAN_NUTTALL       0x00000080    	
#define DSPL_WIN_FLAT_TOP               0x00000100			
#define DSPL_WIN_GAUSSIAN               0x00000400			
#define DSPL_WIN_HAMMING                0x00000800			
#define DSPL_WIN_HANN                   0x00001000				
#define DSPL_WIN_LANCZOS                0x00004000			
#define DSPL_WIN_NUTTALL                0x00008000			
#define DSPL_WIN_RECT                   0x00010000				
#define DSPL_WIN_COS                    0x00040000
  

int butter_ap(double Rp, int ord, double* b, double* a);
int cheby1_ap(double Rp, int ord, double* b, double* a);
int cheby2_ap(double Rs, int ord, double *b, double *a);

int conv(double* a, int na, double* b, int nb, double* c);
int conv_cmplx(complex_t* a, int na, complex_t* b, int nb, complex_t* c);

int dft(double* x, int n, complex_t *y);
int dft_cmplx(complex_t* x, int n, complex_t *y);


#define ELLIP_ITER       16
#define ELLIP_MAX_ORD    24

int ellip_acd(double* w, int n, double k, double* u);
int ellip_asn(double* w, int n, double k, double* u);

int ellip_cd(double* u, int n, double k, double* y);
int ellip_landen(double k, int n, double* y);
int ellip_sn(double* u, int n, double k, double* y);





int filter_iir(double* b, double* a, int ord, double* x, int n, double* y);


int fft_create( fft_t *pfft, int n);
void fft_destroy(fft_t *pfft);

int fft_shift(double* x, int n, double* y);

int fourier_series_dec(double* t, double* s, int nt, double period, int nw, double* w, complex_t* y);
int fourier_series_rec(double* w, complex_t* s, int nw, double *t, int nt, complex_t* y);

int freqs(double* b, double* a, int ord, double* w, int n, complex_t *h);
int freqz(double* b, double* a, int ord, double* w, int n, complex_t *h);

int goertzel(double *x, int n, int *ind, int k, complex_t *y);
int goertzel_cmplx(complex_t *x, int n, int *ind, int k, complex_t *y);

int linspace(double x0, double x1, int n, int type, double* x);
int logspace(double x0, double x1, int n, int type, double* x);

int polyval(double* a, int ord, double* x, int n, double* y);
int polyval_cmplx(complex_t* a, int ord, complex_t* x, int n, complex_t* y);

int randn(double* x, int n, double mu, double sigma);
int randu(double* x, int n);

int rcompos(double *b, double *a, int n, double *c, double *d, int p, double *beta, double *alpha);

int signal_pimp(double* t, size_t n, double amp, double tau, double dt, double period, double* y);

int window(double* w, int n, int win_type, double param);

#endif
 
