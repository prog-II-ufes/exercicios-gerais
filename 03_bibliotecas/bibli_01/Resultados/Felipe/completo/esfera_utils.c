#include "esfera_utils.h"
#include <math.h>

float calcula_volume(float R) {
    return (4.0 / 3) * PI * pow(R, 3);
}

float calcula_area(float R) {
    return 4 * PI * pow(R, 2);
}