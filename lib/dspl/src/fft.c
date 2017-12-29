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


#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dspl.h"



/**************************************************************************************************
FFT shifting
***************************************************************************************************/
int fft_shift(double* x, int n, double* y)
{
	int n2, r;
	int k;
	double tmp;
	double *buf;
	
	if(!x || !y)
		return ERROR_PTR;

	if(n<1)
		return ERROR_SIZE;
		
	r = n%2;
	if(!r)
	{
		n2 = n>>1;
		for(k = 0; k < n2; k++)
		{
			tmp = x[k];
			y[k] = x[k+n2];
			y[k+n2] = tmp;
		}
			
	}
	else
	{
		n2 = (n-1) >> 1;
		buf = (double*) malloc(n2*sizeof(double));
		memcpy(buf, x, n2*sizeof(double));
		memcpy(y, x+n2, (n2+1)*sizeof(double));
		memcpy(y+n2+1, buf, n2*sizeof(double));
		free(buf);
	}	
	return RES_OK;
}
