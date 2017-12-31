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
#include <math.h>
#include "dspl.h"
#include "plot.h"


#define ORD 4
#define N 500

int main(int argc, char* argv[]) {

    double b[ORD+1], a[ORD+1];
    void* hplot;
    complex_t h[N];
    double w[N];
    double H[N];

    int i;

    logspace(-2, 2, N, DSPL_SYMMETRIC, w);
    hplot = plot_create();

    butter_ap(3.0, ORD, b, a);
    freqs(b,a,ORD, w, N, h);
    for( i= 0; i < N; i++)
        H[i] = 10.0*log10(ABSSQR(h[i]));
    plot_logx(hplot, w, H, N, "Butter");

    cheby1_ap(3.0, ORD, b, a);
    freqs(b,a,ORD, w, N, h);
    for( i= 0; i < N; i++)
        H[i] = 10.0*log10(ABSSQR(h[i]));
    plot_logx(hplot, w, H, N, "Cheby1");

    cheby2_ap(50.0, ORD, b, a);
    freqs(b,a,ORD, w, N, h);
    for( i= 0; i < N; i++)
        H[i] = 10.0*log10(ABSSQR(h[i]));
    plot_logx(hplot, w, H, N, "Cheby2");    




   
    printf("Press any key...\n");

    getchar();


    plot_delete(hplot);
    return 0;
}
