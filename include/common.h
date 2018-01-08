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



#ifndef COMMON_H
#define COMMON_H

#include <math.h>
  

/* math const definition */
#ifndef M_PI
	#define M_PI	3.1415926535897932384626433832795
#endif
#ifndef M_2PI
	#define M_2PI	6.283185307179586476925286766559
#endif
     

typedef double complex_t[2];	 


#define RE(x) (x[0])
#define IM(x) (x[1]) 

#define CMRE(a,b)  ((RE(a)) * (RE(b)) - (IM(a)) * (IM(b)))
#define CMIM(a,b)  ((RE(a)) * (IM(b)) + (IM(a)) * (RE(b)))

#define CMCONJRE(a, b)  ((RE(a)) * (RE(b)) + (IM(a)) * (IM(b)))
#define CMCONJIM(a, b)  ((IM(a)) * (RE(b)) - (RE(a)) * (IM(b))) 

#define SQR(x) ((x) * (x)) 

#define ABS(x)    sqrt((RE(x)) * (RE(x)) + (IM(x)) * (IM(x)))
#define ABSSQR(x)     ((RE(x)) * (RE(x)) + (IM(x)) * (IM(x)))




#define RES_OK						    0

/* Error codes 									  */
/* A									0x01xxxxxx*/
/* B									0x02xxxxxx*/
/* C									0x03xxxxxx*/
/* D									0x04xxxxxx*/
#define ERROR_DAT_TYPE                  0x04012020
#define ERROR_DIV_ZERO                  0x04102226
/* E									0x05xxxxxx*/
/* F									0x06xxxxxx*/
#define ERROR_FILTER_A0                 0x06100100
#define ERROR_FILTER_ORD                0x06101518
#define ERROR_FILTER_RP                 0x06101816
#define ERROR_FILTER_RS                 0x06101819
#define ERROR_FNAME                     0x06140113
#define ERROR_FOPEN                     0x06151605
#define ERROR_FWRITE_SIZE               0x06231820
/* G									0x07xxxxxx*/
/* H									0x08xxxxxx*/
/* I									0x09xxxxxx*/
/* J									0x10xxxxxx*/
/* K									0x11xxxxxx*/
/* L									0x12xxxxxx*/
/* M									0x13xxxxxx*/
/* N									0x14xxxxxx*/
/* O									0x15xxxxxx*/
/* P									0x16xxxxxx*/
#define ERROR_POLY_ORD                  0x16151518
#define ERROR_PTR					    0x16201800
/* Q									0x17xxxxxx*/
/* R									0x18xxxxxx*/
#define ERROR_RAND_SIGMA                0x18011909
#define ERROR_RESAMPLE_RATIO            0x18051801
#define ERROR_RESAMPLE_FRAC_DELAY       0x18050604
/* S									0x19xxxxxx*/
#define ERROR_SIZE					    0x19092605
#define ERROR_SYM_TYPE                  0x19251320
/* T									0x20xxxxxx*/
/* U									0x21xxxxxx*/
/* V									0x22xxxxxx*/
/* W									0x23xxxxxx*/
#define ERROR_WIN_TYPE                  0x23092025
#define ERROR_WIN_SYM                   0x23091925
/* X									0x24xxxxxx*/
/* Y									0x25xxxxxx*/
/* Z									0x26xxxxxx*/


#define DAT_DOUBLE      0
#define DAT_COMPLEX     1


int re2cmplx(double* x, int n, complex_t **y);
int cmplx2re(complex_t* x, int n, double **re, double **im);

int trapint(double* x, double* y, int n, double* sum);
int trapint_cmplx(double* x, complex_t* y, int n, complex_t* sum);

int writebin(void* x, int n, int dtype, char* fn);
int writetxt(double* x, double *y, int n, char* fn);

#endif
 
