#include <stdio.h>
#include "esfera_utils.h"

int main(int argc, char const *argv[])
{
    float r;

    scanf("%f", &r);

    printf("Area: %.2f\n", calcula_area(r));
    printf("Volume: %.2f\n", calcula_volume(r));

    return 0;
}
