#include <stdio.h>
#include "utils.h"

int main(){

    int tamanho;
    int *vetor;
    float media;

    scanf("%d", &tamanho);

    vetor = CriaVetor(tamanho);

    LeVetor(vetor, tamanho);

    media = CalculaMedia(vetor, tamanho);

    printf("%.2f\n", media);

    LiberaVetor(vetor);

    return 0;
}

//Ler o tamanho, CriaVetor — reservar memória
//LeVetor — ler os valores
//CalculaMedia — calcular a média
//Imprimir o resultado
//LiberaVetor — liberar memória