#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>


void binary(uint8_t n)
{
    if (n > 1)
        binary(n / 2);

    printf("%d", n % 2);
}