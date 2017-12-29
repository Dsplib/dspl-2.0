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
#include "dspl.h"





/**************************************************************************************************
Real polynomial evaluation 
***************************************************************************************************/
int polyval(double* a, int ord, double* x, int n, double* y)
{
	int k, m;
	
	if(!a || !x || !y)
		return ERROR_PTR;	
	if(ord<0)
		return ERROR_POLY_ORD;	
	if(n<1)
		return ERROR_SIZE;
	
	for(k = 0; k < n; k++)
	{
		y[k] = a[ord];
	 	for(m = ord-1; m>-1; m--)
			y[k] = y[k]*x[k] + a[m];			
	}  	
	return RES_OK;
}





/**************************************************************************************************
Complex polynomial evaluation 
***************************************************************************************************/
int polyval_cmplx(complex_t* a, int ord, complex_t* x, int n, complex_t* y)
{
	int k, m;
    complex_t t;	

	if(!a || !x || !y)
		return ERROR_PTR;	
	if(ord<0)
		return ERROR_POLY_ORD;	
	if(n<1)
		return ERROR_SIZE;
	
	for(k = 0; k < n; k++)
	{
		RE(y[k]) = RE(a[ord]);
		IM(y[k]) = IM(a[ord]);
	 	for(m = ord-1; m>-1; m--)
        {
            RE(t) = CMRE(y[k], x[k]);
            IM(t) = CMIM(y[k], x[k]);
            RE(y[k]) = RE(t) + RE(a[m]);
            IM(y[k]) = IM(t) + IM(a[m]); 
        }		
	}  	
	return RES_OK;
}



