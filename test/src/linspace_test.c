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

int main(int argc, char* argv[]) {

    double x[5];
    int res, i;

    printf("linspace symmetric:\n");
    res = linspace(0.0, 5.0, 5, DSPL_SYMMETRIC, x);
    printf("res = %d x = [", res);
    for(i =0; i < 5; i++)
        printf("%12.3f", x[i]);
    printf("]\n");


    printf("linspace periodic:\n");
    res = linspace(0, 5.0, 5, DSPL_PERIODIC, x);
    printf("res = %d x = [", res);
    for(i =0; i < 5; i++)
        printf("%12.3f", x[i]);
    printf("]\n");


    printf("logspace symmetric:\n");
    res = logspace(-2.0, 2.0, 5, DSPL_SYMMETRIC, x);
    printf("res = %d x = [", res);
    for(i =0; i < 5; i++)
        printf("%12.3f", x[i]);
    printf("]\n");

    printf("logspace periodic:\n");
    res = logspace(-2.0, 2.0, 5, DSPL_PERIODIC, x);
    printf("res = %d x = [", res);
    for(i =0; i < 5; i++)
        printf("%12.3f", x[i]);
    printf("]\n");


    return 0;
}
