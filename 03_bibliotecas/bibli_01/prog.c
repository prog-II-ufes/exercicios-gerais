#include "esfera_utils.h"
#include <stdio.h>

int main () {
    float raio = 0.0, volume = 0.0, area = 0.0;

    scanf("%f", &raio);

    area = AreaDaEsfera(raio);
    volume = VolumeDaEsfera(raio);

    printf("Area: %.02f\nVolume: %.02f\n", area, volume);

    return 0;
}