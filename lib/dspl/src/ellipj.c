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
#include "common.h"


/**************************************************************************************************
inverse cd function
***************************************************************************************************/

int ellip_acd(double* w, int n, double k, double* u)
{
    double lnd[ELLIP_ITER], t;    
    int i, m;    

    if(!u || !w)
        return ERROR_PTR;
    if(n<1)
        return ERROR_SIZE;
    if(k < 0.0 || k>= 1.0)
        return ERROR_ELLIP_MODULE; 

    ellip_landen(k,ELLIP_ITER, lnd);
    

    for(m = 0; m < n; m++)
    {
        u[m] = w[m];
        for(i = 1; i < ELLIP_ITER; i++)
        {   
            t = lnd[i-1]*u[m];
            t *= t;
            t = 1.0 + sqrt(1.0 - t);
            u[m]  = 2.0 * u[m] / (t+t*lnd[i]);
        }
        u[m] = 2.0 * acos(u[m]) / M_PI;
    }
    return RES_OK;
}




/**************************************************************************************************
inverse sn function
***************************************************************************************************/
int ellip_asn(double* w, int n, double k, double* u)
{
    double lnd[ELLIP_ITER], t;    
    int i, m;    

    if(!u || !w)
        return ERROR_PTR;
    if(n<1)
        return ERROR_SIZE;
    if(k < 0.0 || k>= 1.0)
        return ERROR_ELLIP_MODULE; 

    ellip_landen(k,ELLIP_ITER, lnd);
    

    for(m = 0; m < n; m++)
    {
        u[m] = w[m];
        for(i = 1; i < ELLIP_ITER; i++)
        {   
            t = lnd[i-1]*u[m];
            t *= t;
            t = 1.0 + sqrt(1.0 - t);
            u[m]  = 2.0 * u[m] / (t+t*lnd[i]);
        }
        u[m] = 2.0 * asin(u[m]) / M_PI;
    }
    return RES_OK;
}




/**************************************************************************************************
Elliptic cd function
***************************************************************************************************/
int ellip_cd(double* u, int n, double k, double* y)
{
    double lnd[ELLIP_ITER];    
    int i, m;    

    if(!u || !y)
        return ERROR_PTR;
    if(n<1)
        return ERROR_SIZE;
    if(k < 0.0 || k>= 1.0)
        return ERROR_ELLIP_MODULE; 

    ellip_landen(k,ELLIP_ITER, lnd);
    

    for(m = 0; m < n; m++)
    {
        y[m] = cos(u[m] * M_PI * 0.5);
        for(i = ELLIP_ITER-1; i>0; i--)
        {
            y[m] = (1.0 + lnd[i]) / (1.0 / y[m] + lnd[i]*y[m]);
        }
    }
    return RES_OK;
}






/**************************************************************************************************
Landen transform
***************************************************************************************************/
int ellip_landen(double k, int n, double* y)
{
    int i;
    y[0] = k;

    if(!y)
        return ERROR_PTR;
    if(n < 1)
        return ERROR_SIZE;
    if(k < 0.0 || k>= 1.0)
        return ERROR_ELLIP_MODULE;

    for(i = 1; i < n; i++)
    {
        y[i] = y[i-1] / (1.0 + sqrt(1.0 - y[i-1] * y[i-1]));
        y[i] *= y[i];
    }

    return RES_OK;
}




/**************************************************************************************************
Elliptic sn function
***************************************************************************************************/
int ellip_sn(double* u, int n, double k, double* y)
{
    double lnd[ELLIP_ITER];    
    int i, m;    

    if(!u || !y)
        return ERROR_PTR;
    if(n<1)
        return ERROR_SIZE;
    if(k < 0.0 || k>= 1.0)
        return ERROR_ELLIP_MODULE; 

    ellip_landen(k,ELLIP_ITER, lnd);
    

    for(m = 0; m < n; m++)
    {
        y[m] = sin(u[m] * M_PI * 0.5);
        for(i = ELLIP_ITER-1; i>0; i--)
        {
            y[m] = (1.0 + lnd[i]) / (1.0 / y[m] + lnd[i]*y[m]);
        }
    }
    return RES_OK;
}





