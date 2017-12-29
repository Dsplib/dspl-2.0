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


#include "plot.h"
#include "gnuplot_i.h"
#include "common.h"



/**************************************************************************************************
PLOT XY
***************************************************************************************************/
int plot(void* hplot, double* x, double* y, int n, char* legend)
{
    if(!y)
        return ERROR_PTR;
    if(n<1)
        return ERROR_SIZE;
    if(!hplot)
        return ERROR_PLOT_HANDLE;

    gnuplot_setstyle((gnuplot_ctrl*)hplot, "lines");

    if(x)
        gnuplot_plot_xy((gnuplot_ctrl*)hplot, x, y, n, legend);
    else
        gnuplot_plot_x((gnuplot_ctrl*)hplot, y, n, legend);    
    return RES_OK;
}





/**************************************************************************************************
Create Plot
***************************************************************************************************/
void* plot_create(void)
{
    return (void*) gnuplot_init();   
}









/**************************************************************************************************
Delete Plot
***************************************************************************************************/
void plot_delete(void* hplot)
{
    gnuplot_close((gnuplot_ctrl*)hplot);
}

