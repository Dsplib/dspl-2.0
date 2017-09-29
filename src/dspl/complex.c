/*
*   DSPL-2.0 Digital Signal Processing Library
*   Copyright (C) 2017  Sergey Bakhurin [http://dsplib.org]
*
*   This file is part of DSPL-2.0
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version. 
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include <stdlib.h>
#include <string.h>
#include "../dspl.h"



int r2c_err_proc(void *x, int n, void** y)
{
	if(!x || !y || x==(*y))
		return DSPL_ERROR_PTR;
	if(n<1)
		return DSPL_ERROR_SIZE;
	return DSPL_OK;
}






int r64_to_c128(double* x, int n, complex128** y)
{
	int k;
	int err = r2c_err_proc((void*)x,n,(void**)y);
	if(err!=DSPL_OK)
		goto exit_label;
	if(*y)
		*y = (complex128*)realloc(*y, n*sizeof(complex128));
	else
		*y = (complex128*)malloc( n*sizeof(complex128));
	memset(*y, 0, n*sizeof(complex128));
	for(k = 0; k < n; k++)
		(*y)[k][0] = x[k];
	
exit_label:	
	return err;
}







int r32_to_c64(float* x, int n, complex64** y)
{
	int k;
	int err = r2c_err_proc((void*)x,n,(void**)y);
	if(err!=DSPL_OK)
		goto exit_label;
	if(*y)
		*y = (complex64*)realloc(*y, n*sizeof(complex64));
	else
		*y = (complex64*)malloc( n*sizeof(complex64));
	memset(*y, 0, n*sizeof(complex64));

	for(k = 0; k < n; k++)
		(*y)[k][0] = x[k];

exit_label:	
	return err;
}




