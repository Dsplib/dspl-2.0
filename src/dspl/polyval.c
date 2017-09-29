/*
*   DSPL-2.0 Digital Signal Processing Library
*   Copyright (C) 2017  Sergey Bakhurin [http://dsplib.org]
*
*   This file is part of DSPL-2.0
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version. 
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../dspl.h"




int polyval_r32(float* a, int ord, float* x, int n, float* y)
{
	int k;
	int m;   
	int err;
	
	if(!a || !x || !y)
	{
		err = DSPL_ERROR_PTR;
		goto exit_label;	
	}
	if(ord<0)
	{
		err = DSPL_ERROR_POLY_ORD;
		goto exit_label;	
	}
	if(n<1)
	{
		err = DSPL_ERROR_SIZE;
		goto exit_label;	
	}
	
	for(k = 0; k < n; k++)
	{
		y[k] = a[ord];
	 	for(m = ord-1; m > -1; m--)
			y[k] = y[k]*x[k] + a[m];			
	}  
	
	err = DSPL_OK;		
exit_label:
	return err;
}
  




int polyval_r64(double* a, int ord, double* x, int n, double* y)
{
	int k;
	int m;   
	int err;
	
	if(!a || !x || !y)
	{
		err = DSPL_ERROR_PTR;
		goto exit_label;	
	}
	if(ord<0)
	{
		err = DSPL_ERROR_POLY_ORD;
		goto exit_label;	
	}
	if(n<1)
	{
		err = DSPL_ERROR_SIZE;
		goto exit_label;	
	}
	
	for(k = 0; k < n; k++)
	{
		y[k] = a[ord];
	 	for(m = ord-1; m > -1; m--)
			y[k] = y[k]*x[k] + a[m];			
	}  
	
	err = DSPL_OK;		
exit_label:
	return err;
}







int polyval_c64(complex64* a, int ord, complex64* x, int n, complex64* y)
{
	int k;
	int m;   
	int err;
	complex64 t;

	if(!a || !x || !y)
	{
		err = DSPL_ERROR_PTR;
		goto exit_label;	
	}
	if(ord<0)
	{
		err = DSPL_ERROR_POLY_ORD;
		goto exit_label;	
	}
	if(n<1)
	{
		err = DSPL_ERROR_SIZE;
		goto exit_label;	
	}
	
	for(k = 0; k < n; k++)
	{
		y[k][0] = a[ord][0];
        y[k][1] = a[ord][1];
	 	for(m = ord-1; m > -1; m--)
        {
            t[0] = y[k][0]*x[k][0] - y[k][1]*x[k][1];
            t[1] = y[k][1]*x[k][0] + y[k][0]*x[k][1];
			y[k][0] = t[0] + a[m][0];	
            y[k][1] = t[0] + a[m][1];	
        }	
	}  
	
	err = DSPL_OK;		
exit_label:
	return err;
}






int polyval_c128(complex128* a, int ord, complex128* x, int n, complex128* y)
{
	int k;
	int m;   
	int err;
	complex128 t;

	if(!a || !x || !y)
	{
		err = DSPL_ERROR_PTR;
		goto exit_label;	
	}
	if(ord<0)
	{
		err = DSPL_ERROR_POLY_ORD;
		goto exit_label;	
	}
	if(n<1)
	{
		err = DSPL_ERROR_SIZE;
		goto exit_label;	
	}
	
	for(k = 0; k < n; k++)
	{
		y[k][0] = a[ord][0];
        y[k][1] = a[ord][1];
	 	for(m = ord-1; m > -1; m--)
        {
            t[0] = y[k][0]*x[k][0] - y[k][1]*x[k][1];
            t[1] = y[k][1]*x[k][0] + y[k][0]*x[k][1];
			y[k][0] = t[0] + a[m][0];	
            y[k][1] = t[0] + a[m][1];	
        }	
	}  
	
	err = DSPL_OK;		
exit_label:
	return err;
}




