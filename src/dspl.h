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
     

typedef double complex[2];	 

#define DSPL_OK						0

/* Error codes 									*/
/* A									0x0001XXXX*/
/* B									0x0002XXXX*/
/* C									0x0003XXXX*/
/* D									0x0004XXXX*/
/* E									0x0005XXXX*/
#define DSPL_ERROR_ELLIP_K				0x00050100
/* F									0x0006XXXX*/
#define	DSPL_ERROR_FFT_SIZE				0x00060100	
#define DSPL_ERROR_FILTER_A0			0x00060200
#define	DSPL_ERROR_FILTER_ORD			0x00060300
#define	DSPL_ERROR_FILTER_RP			0x00060400	
#define	DSPL_ERROR_FILTER_RS			0x00060500 
#define	DSPL_ERROR_FILTER_WP			0x00060600 
#define DSPL_ERROR_FNAME				0x00060700	
#define DSPL_ERROR_FOPEN				0x00060800
#define DSPL_ERROR_FS					0x00060900
/* G									0x0007XXXX*/
/* H									0x0008XXXX*/
/* I									0x0009XXXX*/
/* J									0x0010XXXX*/
/* K									0x0011XXXX*/
/* L									0x0012XXXX*/
/* M									0x0013XXXX*/
/* N									0x0014XXXX*/
/* O									0x0015XXXX*/
#define DSPL_ERROR_OVERLAP				0x00150100
/* P									0x0016XXXX*/
#define DSPL_ERROR_POLY_ORD				0x00160100
#define DSPL_ERROR_PTR					0x00160200
/* Q									0x0017XXXX*/
/* R									0x0018XXXX*/
#define DSPL_ERROR_RAND_SIGMA			0x00180100
#define DSPL_ERROR_RESAMPLE_FRAC_DELAY	0x00180200
#define	DSPL_ERROR_RESAMPLE_RATIO		0x00180300
#define	DSPL_ERROR_RESAMPLE_SIZE		0x00180400
/* S									0x0019XXXX*/
#define DSPL_ERROR_SIZE					0x00190100
/* T									0x0020XXXX*/
/* U									0x0021XXXX*/
#define DSPL_ERROR_UNWRAP				0x00210100
/* V									0x0022XXXX*/
/* W									0x0023XXXX*/
#define	DSPL_ERROR_WIN_TYPE				0x00230100
/* X									0x0024XXXX*/
/* Y									0x0025XXXX*/
/* Z									0x0026XXXX*/




int polyval_real(double* a, int ord, double* x, int n, double* y);


#endif


