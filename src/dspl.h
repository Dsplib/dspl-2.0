/*
* Copyright (c) 2015-2017 Sergey Bakhurin
* Digital Signal Processing Library [http://dsplib.org]
*
* This file is part of DSPL.
*  
* DSPL is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef DSPL_H
#define DSPL_H

#include <math.h>
  

/* math const definition */
#ifndef M_PI
	#define M_PI	3.1415926535897932384626433832795
#endif
#ifndef M_2PI
	#define M_2PI	6.283185307179586476925286766559
#endif
     

typedef double complex128[2];	 
typedef float  complex32[2];


#define DSPL_OK						0

/* Error codes 									*/
/* A									0x0001XXXX*/
/* B									0x0002XXXX*/
/* C									0x0003XXXX*/
/* D									0x0004XXXX*/
/* E									0x0005XXXX*/
/* F									0x0006XXXX*/
/* G									0x0007XXXX*/
/* H									0x0008XXXX*/
/* I									0x0009XXXX*/
/* J									0x0010XXXX*/
/* K									0x0011XXXX*/
/* L									0x0012XXXX*/
/* M									0x0013XXXX*/
/* N									0x0014XXXX*/
/* O									0x0015XXXX*/
/* P									0x0016XXXX*/
#define DSPL_ERROR_POLY_ORD				0x00160100
#define DSPL_ERROR_PTR					0x00160200
/* Q									0x0017XXXX*/
/* R									0x0018XXXX*/
/* S									0x0019XXXX*/
#define DSPL_ERROR_SIZE					0x00190100
/* T									0x0020XXXX*/
/* U									0x0021XXXX*/
/* V									0x0022XXXX*/
/* W									0x0023XXXX*/
/* X									0x0024XXXX*/
/* Y									0x0025XXXX*/
/* Z									0x0026XXXX*/





int polyval_c32  (complex32*  a,  int ord,  complex32*  x, int n, complex32*  y);
int polyval_c128 (complex128* a,  int ord,  complex128* x, int n, complex128* y);
int polyval_r16 (float*       a,  int ord,  float*      x, int n, float*      y);
int polyval_r64 (double*      a,  int ord,  double*     x, int n, double*     y);


#endif


