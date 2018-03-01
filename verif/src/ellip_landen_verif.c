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


#define N 16

int main(int argc, char* argv[]) 
{

    double    k, lnd[N];
    randu(&k, 1);
   
    ellip_landen(k, N, lnd);
   

    writebin(&k,  1, DAT_DOUBLE,  "dat/ellip_landen_in.bin");
    writebin(lnd, N, DAT_DOUBLE,  "dat/ellip_landen_out.bin");
        
    return 0;
}
