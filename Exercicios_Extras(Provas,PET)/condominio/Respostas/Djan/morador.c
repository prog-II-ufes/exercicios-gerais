#include <stdio.h>
#include <string.h>
#include "data.h"

#define MAX_TAM_NOME 100
#define MAX_TAM_RESIDENCIA 10
#define MAX_TAM_CPF 15

typedef struct
{
    char nome[MAX_TAM_NOME];
    char cpf[MAX_TAM_CPF];
    Data dataNasc;
    char idResidencia[MAX_TAM_RESIDENCIA];

} Morador;

/*
 *  Função que lê um morador de acordo com o formato de entrada descrito na
 *  especificação
 *  Retorna o Morador lido
 */
Morador lerMorador(){
    Morador m;

    scanf("%s",m.nome);
    scanf("%s",m.cpf);
    lerData();
    scanf("%s",m.idResidencia);

    return m;
}

/**
 * Função que imprime todas as informações de uma Morador conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeMorador(Morador m){
    printf("Morador:\n");
    printf("Nome: %s\n",m.nome);
    printf("CPF: %s\n",m.cpf);
    imprimeData(m.dataNasc);
    printf("Residência: %s\n",m.idResidencia);
}

/**
 * Verifica se dois moradores são iguais. A comparação é feita usando apenas o CPF.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int comparaMorador(Morador m1, Morador m2){
    if(strcmp(m1.cpf,m2.cpf) == 0){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Verifica se um dado CPF pertence ao morador.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int verificaCPFMorador(Morador m1, char *cpf){
    if(strcmp(m1.cpf, cpf) == 0){
        return 1;
    }else{
        return 0;
    }
}

/*
 *  Função que calcula a idade de um morador em relação a uma data de referência
 *  Retorna a idade do morador em anos
 */
int calculaIdadeMorador(Morador m, Data dataRef){
    return calcularDiffAnosData(m.dataNasc,dataRef);
}