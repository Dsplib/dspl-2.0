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


#include <stdio.h>
#include <stdlib.h>
#include "common.h"


/**************************************************************************************************
convert double array to a complex array 
***************************************************************************************************/
int re2cmplx(double* x, int n, complex_t **y)
{
    int k;
    if(!x || !y)
        return ERROR_PTR;
    if(n < 1)
        return ERROR_SIZE;

    (*y) = (complex_t*) realloc(*y, n*sizeof(complex_t));

    for(k = 0; k < n; k++)
    {
        RE((*y)[k]) = x[k];
        IM((*y)[k]) = 0.0;
    }    
    return RES_OK;
}





/**************************************************************************************************
convert complex array to a re and im arrays 
***************************************************************************************************/
int cmplx2re(complex_t* x, int n, double **re, double **im)
{
    int k;
    if(!x)
        return ERROR_PTR;
    if(n < 1)
        return ERROR_SIZE;

    if(re)
    {
        (*re) = (double*) realloc(*re, n*sizeof(double));
        for(k = 0; k < n; k++)
            (*re)[k] = RE(x[k]);
    }
    if(im)
    {
        (*im) = (double*) realloc(*im, n*sizeof(double));
        for(k = 0; k < n; k++)
            (*im)[k] = IM(x[k]);
    }
    return RES_OK;
}
