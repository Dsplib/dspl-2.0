#include <stdio.h>
#include <stdlib.h>
#include "../dspl.h"


int main()
{
    double a[3] = {1.0, 1.0, 1.0};
    double x = 2.0;
    double y;

    int err = polyval_real(a, 2, &x, 1, &y);
    printf("err = %d, y = %f\n", err, y);

    return 0;
}

