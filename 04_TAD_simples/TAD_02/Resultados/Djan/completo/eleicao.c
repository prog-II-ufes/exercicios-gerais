#include <stdio.h>
#include "candidato.h"
#include "eleitor.h"


#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;

    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor eleitores[MAX_ELEITORES];
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    tEleicao t;
    tCandidato c;
    int qtdTotalCandidatos;
    int i;

    t.votosBrancosPresidente = 0;
    t.votosNulosPresidente = 0;
    t.votosBrancosGovernador = 0;
    t.votosNulosGovernador = 0;

    scanf("%d",&qtdTotalCandidatos);

    for(i = 0; i < qtdTotalCandidatos; i++){
        c = LeCandidato();
    }

    if (ObtemCargo(c) == 'P') {
        t.presidentes[t.totalPresidentes] = c;
        t.totalPresidentes++;
    } else if (ObtemCargo(c) == 'G') {
        t.governadores[t.totalGovernadores] = c;
        t.totalGovernadores++;
    }

    return t;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao){
    int i;
    int qtdEleitoresParaLer;

    scanf("%d", &qtdEleitoresParaLer);

    for(i = 0; i < qtdEleitoresParaLer; i++){
        if (eleicao.totalEleitores < MAX_ELEITORES) {
    
            eleicao.eleitores[eleicao.totalEleitores] = LeEleitor();
            
            eleicao.totalEleitores++;
        } else {
            LeEleitor(); 
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao){
}