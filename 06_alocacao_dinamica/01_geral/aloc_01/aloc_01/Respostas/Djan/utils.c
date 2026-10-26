#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * Cria um vetor de inteiros de tamanho especificado, alocado dinamicamente.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
int *CriaVetor(int tamanho){

    //Ele pode guardar o endereço de um inteiro. Como um vetor dinâmico ocupa posições consecutivas de memória, esse ponteiro pode apontar para o primeiro elemento. *vetor

    //Imagine que tamanho = 5 e que cada int ocupa 4 bytes:
    //A expressão tamanho * sizeof(int) calcula quantos bytes precisamos. O malloc reserva esse espaço e devolve um endereço.
    int *vetor = malloc(tamanho * sizeof(int));


    //Se não houver memória disponível, malloc pode retornar NULL. Nesse caso, encerramos o programa com exit(1) para evitar usar um ponteiro inválido.
    if(vetor == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    return vetor;
}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
//Agora precisamos preencher as posições do vetor com os números digitados.
void LeVetor(int *vetor, int tamanho){
    int i;

    //O for percorre as posições de 0 até tamanho - 1. O &vetor[i] fornece o endereço da posição onde o scanf deve guardar o inteiro.
    for(i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho){
    int i;
    int soma = 0;

    for(i = 0; i < tamanho; i++){
        soma += vetor[i];
    }

    //O (float) transforma a soma em um número de ponto flutuante antes da divisão. Assim, evitamos perder a parte decimal.
    return (float)soma / tamanho;
}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor){
    free(vetor);
}