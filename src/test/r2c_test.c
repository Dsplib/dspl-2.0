#include <stdio.h>
#include <stdlib.h>
#include "../dspl.h"


int main()
{
    double x64[3] = {1.0, -1.0, 2.0};
    complex128* y128 = NULL;
    float x32[3] = {1.0, -1.0, 2.0};
    complex64* y64 = NULL;
    int err, k;
    
    err =  r64_to_c128(x64, 3, &y128);
    printf("r64_to_c128 = %d\n", err);

    err =  r32_to_c64(x32, 3, &y64);
    printf("r32_to_c64 = %d\n", err);

    for(k = 0; k < 3; k++)
    {
        printf("y128 = %5.1f%+5.1f", y128[k][0], y128[k][1]);
        printf("y64 = %5.1f%+5.1f\n", y64[k][0], y64[k][1]);
    }

    return 0;
}

