#include <stdio.h>
#include <ctype.h>
#include "temperature_conversor.h"

int main(){

    char escalaAtual,escalaDesejada;
    float temperatura, resultado = 0;

    scanf("%f %c %c",&temperatura,&escalaAtual,&escalaDesejada);

    escalaDesejada = toupper(escalaDesejada);
    if(escalaAtual == 'c'){
        if(escalaDesejada == 'K'){
            resultado = convert_temperature(temperatura,convert_celsius_to_kelvin);
            printf("Temperature: %.2f%c",resultado,escalaDesejada);
        }else if(escalaDesejada == 'F'){
            resultado = convert_temperature(temperatura,convert_celsius_to_fahrenheit);
            printf("Temperature: %.2f%cº",resultado,escalaDesejada);
        }
    }else if(escalaAtual == 'k'){
        if(escalaDesejada == 'C'){
            resultado = convert_temperature(temperatura,convert_kelvin_to_celsius);
            printf("Temperature: %.2f%cº",resultado,escalaDesejada);
        }else if(escalaDesejada == 'F'){
            resultado = convert_temperature(temperatura,convert_kelvin_to_fahrenheit);
            printf("Temperature: %.2f%cº",resultado,escalaDesejada);
        }
    }else if(escalaAtual == 'f'){
        if(escalaDesejada == 'C'){
            resultado = convert_temperature(temperatura,convert_fahrenheit_to_celsius);
            printf("Temperature: %.2f%cº",resultado,escalaDesejada);
        }else if(escalaDesejada == 'K'){
            resultado = convert_temperature(temperatura,convert_fahrenheit_to_kelvin);
            printf("Temperature: %.2f%c",resultado,escalaDesejada);
        }
    }

    return 0;
}