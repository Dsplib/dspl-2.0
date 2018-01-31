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
int re2cmplx(double* x, int n, complex_t *y)
{
    int k;
    if(!x || !y)
        return ERROR_PTR;
    if(n < 1)
        return ERROR_SIZE;

    for(k = 0; k < n; k++)
    {
        RE(y[k]) = x[k];
        IM(y[k]) = 0.0;
    }    
    return RES_OK;
}





/**************************************************************************************************
convert complex array to a re and im arrays 
***************************************************************************************************/
int cmplx2re(complex_t* x, int n, double *re, double *im)
{
    int k;
    if(!x)
        return ERROR_PTR;
    if(n < 1)
        return ERROR_SIZE;

    if(re)
    {
        for(k = 0; k < n; k++)
            re[k] = RE(x[k]);
    }
    if(im)
    {
        for(k = 0; k < n; k++)
            im[k] = IM(x[k]);
    }
    return RES_OK;
}






/**************************************************************************************************
Complex cosine
***************************************************************************************************/
int cos_cmplx(complex_t* x, int n, complex_t *y)
{
    int k;
    double ep, em, sx, cx;
    if(!x || !y)
        return ERROR_PTR;
    if(n < 1) 
        return ERROR_SIZE;
    
    for(k = 0; k < n; k++)
    {
        ep = exp( IM(x[k]));
        em = exp(-IM(x[k]));
        sx = 0.5 * sin(RE(x[k]));
        cx = 0.5 * cos(RE(x[k]));
        RE(y[k]) = cx * (em + ep);
        IM(y[k]) = sx * (em - ep);
    } 
    return RES_OK;
}




/**************************************************************************************************
Complex cosine
***************************************************************************************************/
int sin_cmplx(complex_t* x, int n, complex_t *y)
{
    int k;
    double ep, em, sx, cx;
    if(!x || !y)
        return ERROR_PTR;
    if(n < 1) 
        return ERROR_SIZE;
    
    for(k = 0; k < n; k++)
    {
        ep = exp( IM(x[k]));
        em = exp(-IM(x[k]));
        sx = 0.5 * sin(RE(x[k]));
        cx = 0.5 * cos(RE(x[k]));
        RE(y[k]) = sx * (em + ep);
        IM(y[k]) = cx * (ep - em);
   } 
    return RES_OK;
}




/**************************************************************************************************
SQRT complex
***************************************************************************************************/
int sqrt_cmplx(complex_t* x, int n, complex_t *y)
{
    int k;
    double r, zr;
    complex_t t;
    if(!x || !y)
        return ERROR_PTR;
    if(n < 1) 
        return ERROR_SIZE;
    
    for(k = 0; k < n; k++)
    {
        r = ABS(x[k]);
        RE(t) = RE(x[k]) + r;
        IM(t) = IM(x[k]);
        zr = 1.0 / ABS(t);
        r = sqrt(r);
        RE(y[k]) = RE(t) * zr * r;
        IM(y[k]) = IM(t) * zr * r;
        
   } 
    return RES_OK;
}




