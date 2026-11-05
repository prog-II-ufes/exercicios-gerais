#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

/**
 * Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com "_"
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetor(int tamanho){
    char *vetor = malloc(tamanho * sizeof(char));

    if(vetor == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
}

/**
 * Lê uma string do tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(char *vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        scanf("%c", &vetor[i]);
    }
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
void ImprimeString(char *vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf("_");
    }
    printf("\n");

    for(i = 0; i < tamanho; i++){
        if(){
            
        }
        printf("%c",vetor[i]);
    }
    printf("\n");

}   

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor){
    free(vetor);
}