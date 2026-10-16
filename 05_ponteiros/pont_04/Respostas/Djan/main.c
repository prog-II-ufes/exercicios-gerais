#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    
    int tamanho;
    
    scanf("%d", &tamanho);
    
    int numeros[tamanho];
    
    LeNumeros(numeros, tamanho);
    
    int maior, menor;
    float media;

    EncontraMaiorMenorMedia(numeros, tamanho, &maior, &menor, &media);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media dos elementos: %.2f\n", media);

return 0;
}