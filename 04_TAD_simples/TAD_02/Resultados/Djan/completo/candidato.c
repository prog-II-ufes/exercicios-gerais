#include <stdio.h>
#include <string.h>
#include "candidato.h"

/**
 * @brief Cria um candidato com os dados informados.
 * @param nome Nome do candidato.
 * @param partido Partido do candidato.
 * @param cargo Cargo do candidato.
 * @param id Identificador do candidato.
 * @return Candidato criado.
 */
tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato c;
    strcpy(c.nome, nome);
    strcpy(c.partido, partido);
    c.cargo = cargo;
    c.id = id;

    return c;
}

/**
 * @brief Lê um candidato.
 * @return Candidato lido.
 */
tCandidato LeCandidato(){
   
    tCandidato c;

    scanf("%s, %s, %c, %d",c.nome,c.partido,&c.cargo,&c.id);
    c.votos = 0;
    return c;
}

/**
 * @brief Verifica se o identificador do candidato é igual ao informado.
 * @param candidato Candidato a ser verificado.
 * @param id Identificador a ser comparado.
 * @return 1 se o identificador é igual, 0 caso contrário.
 */
int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id == id){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief Verifica se dois candidatos são iguais (dica: utilize para verificar se houve empate).
 * @param candidato1 Primeiro candidato a ser comparado.
 * @param candidato2 Segundo candidato a ser comparado.
 * @return 1 se os candidatos são iguais, 0 caso contrário.
 */
int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if(candidato1.id == candidato2.id){
        return 1;
    }else{
        return 0;
    }

}

/**
 * @brief Obtém o cargo do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Cargo do candidato.
 */
char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

/**
 * @brief Incrementa 1 voto ao candidato.
 * @param candidato Candidato a ter os votos incrementados.
 * @return Candidato com a quantidade de votos incrementada.
 */
tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;

    return candidato;
}

/**
 * @brief Obtém a quantidade de votos do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Quantidade de votos do candidato.
 */
int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    
    int votosCandidato;

    if (totalVotos == 0) {
        return 0.0;
    }
    
    votosCandidato = candidato.votos; 
    
    return ((float)votosCandidato / totalVotos) * 100.0;
}

/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato (tCandidato candidato, float percentualVotos){
        // 1. Verifica primeiro se o candidato é uma indicação de que não houve eleito
    if (strcmp(candidato.nome, "SEM DECISAO") == 0) {
        if (candidato.cargo == 'P') {
            printf("PRESIDENTE ELEITO: SEM DECISAO\n");
        } else if (candidato.cargo == 'G') {
            printf("GOVERNADOR ELEITO: SEM DECISAO\n");
        }
        return; // Finaliza a função aqui para não executar o código de baixo
    }

    // 2. Se houver um candidato eleito de verdade, imprime com os votos e percentual
    if (candidato.cargo == 'P') {
        printf("PRESIDENTE ELEITO: %s, %d voto(s), %.2f%%\n", candidato.nome, candidato.votos, percentualVotos);
    } else if (candidato.cargo == 'G') {
        printf("GOVERNADOR ELEITO: %s, %d voto(s), %.2f%%\n", candidato.nome, candidato.votos, percentualVotos);
    }
}
