#include <stdio.h>
#include "esfera_utils.h"

int main(){

    float R;

    scanf("%f",&R);

    calcula_area(R);
    calcula_volume(R);

    printf("Area: %.2f\nVolume: %.2f\n",calcula_area(R),calcula_volume(R));

    return 0;
}