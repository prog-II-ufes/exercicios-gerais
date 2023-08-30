#include "esfera_utils.h"

float AreaDaEsfera(float raio){
    return 4 * 3.14 * raio * raio; 
}

float VolumeDaEsfera(float raio){
    return 4.0 / 3.0 * 3.14 * raio * raio * raio;
}