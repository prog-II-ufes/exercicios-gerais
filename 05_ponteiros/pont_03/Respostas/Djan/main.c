#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
int main(int argc, char * argv[]){

    int casos;

    scanf("%d", &casos);

    while(casos){

        int tam;

        scanf("%d", &tam);

        int vet[tam];

        LeDadosParaVetor(vet, tam);

        OrdeneCrescente(vet, tam);

        ImprimeDadosDoVetor(vet, tam);

        casos--;

    }

    return 0;
}