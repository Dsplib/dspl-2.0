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
#include "dspl.h"
#include "plot.h"


#define N 2000
#define T   4.0


int main(int argc, char* argv[]) {

    double t[N], s[N];
    void* hplot;
    int i;

    linspace(-T, T, N, DSPL_SYMMETRIC, t);
    hplot = plot_create();

//    int signal_pimp(double* t, size_t n, double amp, double tau, double dt, double period, double* y)
    signal_pimp(t, N, 2.0, 1.0, 0.0, T, s);    
    plot(hplot, t, s, N, "tau = 1, dt = 0");

    signal_pimp(t, N, 2.0, 1.0, 1.6, T, s);    
    plot(hplot, t, s, N, "tau = 1, dt = 1.6");

    signal_pimp(t, N, 2.0, 1.0, -1.8, T, s);    
    plot(hplot, t, s, N, "tau = 1, dt = -1.8");

    signal_pimp(t, N, 2.0, 2.0, 0.0, 0.0, s);    
    plot(hplot, t, s, N, "tau = 1, dt = 0.0, T = 0");

   
    printf("Press any key...\n");

    getchar();


    plot_delete(hplot);
    return 0;
}
