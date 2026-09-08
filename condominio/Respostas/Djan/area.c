#include <stdio.h>
#include <string.h>

#define MAX_TAM_NOME 100
#define MAX_TAM_ID 5

typedef struct
{
    char nome[MAX_TAM_NOME];
    char id[MAX_TAM_ID];
    int capacidade;
} Area;

/**
 * Função que lê uma área comum de acordo com o formato de entrada descrito na
 * especificação e retorna a Area lida.
 */
Area lerArea(){
    Area a;
    
    scanf("%s",a.nome);
    scanf("%s",a.id);
    scanf("%d",&a.capacidade);

    return a;
}

/**
 * Função que imprime todas as informações de uma Area conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeArea(Area a){
    printf("Area reservada:\nNome: %s\nId: %s\nCapacidade: %d convidados(s)\nData da reserva: ",a.nome,a.id,a.capacidade);
}

/*
 * Função que compara se duas áreas são iguais através do
 * id delas.
 * Retorna 1 se forem iguais e 0 caso contrário
 */
int comparaArea(Area a1, Area a2){
    if(strcmp(a1.id,a2.id) == 0){
        return 1;
    }else{
        return 0;
    }
}

/*
 * Função que verifica se o id passado é igual ao id da área passada
 * Retorna 1 se for igual e 0 caso contrário
 */
int verificaIdArea(Area a, char *id){
    if(strcmp(a.id, id)){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Função que retorna a capacidade de uma área comum.
 */
int getCapacidadeArea(Area a){
    return a.capacidade;
}