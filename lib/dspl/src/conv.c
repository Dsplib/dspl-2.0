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
#include "dspl.h"




/**************************************************************************************************
Real vectors linear convolution 
***************************************************************************************************/
int conv(double* a, int na, double* b, int nb, double* c)
{
	int k;
	int n;

    double *t;
	size_t bufsize;	    
	
    if(!a || !b || !c)
        return ERROR_PTR;
    if(na < 1 || nb < 1)
        return ERROR_SIZE;


    bufsize = (na + nb - 1) * sizeof(double);	
	
    if((a != c) && (b != c))
		t = c;
	else
		t = (double*)malloc(bufsize);

    memset(t, 0, bufsize);

	for(k = 0; k < na; k++)
		for(n = 0; n < nb; n++)
			t[k+n] += a[k]*b[n];

    if(t!=c)
	{
		memcpy(c, t, bufsize);
		free(t);
	}
    return RES_OK;
}






/**************************************************************************************************
Complex vectors linear convolution 
***************************************************************************************************/
int conv_cmplx(complex_t* a, int na, complex_t* b, int nb, complex_t* c)
{
	int k;
	int n;

    complex_t *t;
	size_t bufsize;	    
	
    if(!a || !b || !c)
        return ERROR_PTR;
    if(na < 1 || nb < 1)
        return ERROR_SIZE;

    bufsize = (na + nb - 1) * sizeof(complex_t);	
	
    if((a != c) && (b != c))
		t = c;
	else
		t = (complex_t*)malloc(bufsize);

    memset(t, 0, bufsize);

	for(k = 0; k < na; k++)
    {
		for(n = 0; n < nb; n++)
        {
			RE(t[k+n]) += CMRE(a[k], b[n]);
            IM(t[k+n]) += CMIM(a[k], b[n]);
        }
    }

    if(t!=c)
	{
		memcpy(c, t, bufsize);
		free(t);
	}

    return RES_OK;
}





