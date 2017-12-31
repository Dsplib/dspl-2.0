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



int freqs(double* b, double* a, int ord, double* w, int n, complex_t *h)
{

	complex_t jw;
    complex_t *bc = NULL; 
    complex_t *ac = NULL;	
	complex_t num, den;
	double mag;
	int k;
	int res;
	
	if(!b || !a || !w || !h)
		return ERROR_PTR;
	if(ord<0)
		return ERROR_FILTER_ORD;
	if(n<1)
		return ERROR_SIZE;

    RE(jw) = 0.0;
    
    res = re2cmplx(b, ord+1, &bc);
    if( res!=RES_OK )
        goto exit_label;
 
    res = re2cmplx(a, ord+1, &ac); 
    if( res!=RES_OK )
        goto exit_label;

	for(k = 0; k < n; k++)
	{
        IM(jw) = w[k];
		res = polyval_cmplx(bc, ord, &jw, 1, &num);	
		if(res != RES_OK)
			goto exit_label;
		res = polyval_cmplx(ac, ord, &jw, 1, &den);
		if(res != RES_OK)
			goto exit_label;
        mag = ABSSQR(den);
        if(mag == 0.0)
        {
            res = ERROR_DIV_ZERO;
            goto exit_label;
        }
		mag = 1.0 / mag;
		RE(h[k]) = CMCONJRE(num, den) * mag;
		IM(h[k]) = CMCONJIM(num, den) * mag;
 
	}	
	res = RES_OK;		
exit_label:
    if(bc)
        free(bc);
    if(ac)
        free(ac);
	return res;
} 
