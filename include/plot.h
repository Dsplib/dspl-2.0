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



#ifndef PLOT_H
#define PLOT_H

/* Error codes 									*/
/* A									0x01xxxxxx*/
/* B									0x02xxxxxx*/
/* C									0x03xxxxxx*/
/* D									0x04xxxxxx*/
/* E									0x05xxxxxx*/
/* F									0x06xxxxxx*/
/* G									0x07xxxxxx*/
/* H									0x08xxxxxx*/
#define ERROR_PLOT_HANDLE               0x08011404
/* I									0x09xxxxxx*/
/* J									0x10xxxxxx*/
/* K									0x11xxxxxx*/
/* L									0x12xxxxxx*/
/* M									0x13xxxxxx*/
/* N									0x14xxxxxx*/
/* O									0x15xxxxxx*/
/* P									0x16xxxxxx*/
/* Q									0x17xxxxxx*/
/* R									0x18xxxxxx*/
/* S									0x19xxxxxx*/
/* T									0x20xxxxxx*/
/* U									0x21xxxxxx*/
/* V									0x22xxxxxx*/
/* W									0x23xxxxxx*/
/* X									0x24xxxxxx*/
/* Y									0x25xxxxxx*/
/* Z									0x26xxxxxx*/


int plot(void* hplot, double* x, double* y, int n, char* legend);
int plot_logx(void* hplot, double* x, double* y, int n, char* legend);

void* plot_create();


void plot_delete(void* hplot);


#endif

