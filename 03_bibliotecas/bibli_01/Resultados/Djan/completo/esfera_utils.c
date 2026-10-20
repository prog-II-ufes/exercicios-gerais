#include "esfera_utils.h"
#include <math.h>
#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @return O volume da esfera.
 */
float calcula_volume (float R){
    return (4*PI*(pow(R,3)))/3;
}

/**
 * @brief Calcula a área de superfície de uma esfera com raio R.
 * @param R O raio da esfera.
 * @return A área de superfície da esfera.
 */
float calcula_area (float R){
    return 4*PI*(pow(R,2));
}