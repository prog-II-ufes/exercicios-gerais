#include <stdio.h>
#include "esfera_utils.h"

int main(){
    float R, volume=0, area=0;

    scanf("%f", &R);

    volume=calcula_volume(R);
    area=calcula_area(R);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
    
    return 0;
}
