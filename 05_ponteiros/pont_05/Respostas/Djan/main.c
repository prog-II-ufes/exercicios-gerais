#include <stdio.h>
#include "esfera_utils.h"

int main () {


    float R, volume, area;

    scanf("%f", &R);

    CalculaVolume(R, &volume);

    CalculaArea(R, &area);

    printf("Area: %.2f\n", area);

    printf("Volume: %.2f\n", volume);

    return 0;
}