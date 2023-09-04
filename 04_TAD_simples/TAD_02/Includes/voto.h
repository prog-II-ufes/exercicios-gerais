#ifndef _VOTO_H
#define _VOTO_H

/**
 * @brief Constantes que representam os identificadores dos candidatos à presidência.
 */
#define DIJKSTRA 10
#define TURING 42
#define SHAW 26

/**
 * @brief Constantes que representam os identificadores dos candidatos a Primeiro Ministro.
 */
#define BERNERS 36
#define LINUS 64
#define LOVELACE 18

/**
 * @brief Constante que representa o identificador do voto em branco.
 */
#define BRANCO 0

/**
 * @brief Constantes que representam votacao com empate ou sem decisão.
 */
#define EMPATE 0
#define SEM_DECISAO -1

/**
 * @struct tVoto
 * @brief Estrutura que representa os votos de uma eleição.
 * @var tVoto::brancosP
 * Número de votos em branco para a presidência.
 * @var tVoto::nulosP
 * Número de votos nulos para a presidência.
 * @var tVoto::brancosM
 * Número de votos em branco para o Primeiro Ministro.
 * @var tVoto::nulosM
 * Número de votos nulos para o Primeiro Ministro.
 * @var tVoto::dij
 * Número de votos para Edsger Dijkstra.
 * @var tVoto::tur
 * Número de votos para Alan Turing.
 * @var tVoto::sha
 * Número de votos para Carol Shaw.
 * @var tVoto::ber
 * Número de votos para Tim Berners-Lee.
 * @var tVoto::lin
 * Número de votos para Linus Torvalds.
 * @var tVoto::lov
 * Número de votos para Ada Lovelace.
 */
typedef struct{
    int brancosP, nulosP; 
    int brancosM, nulosM; 
    int dij, tur, sha; 
    int ber, lin, lov;
} tVoto;

/**
 * @brief Inicializa a estrutura de votos com valores zerados.
 * @return Retorna uma estrutura tVoto com todos os campos zerados.
 */
tVoto inicializaVotos();

/**
 * @brief Calcula a porcentagem de um valor em relação a um total.
 * @param valor Valor a ser calculado a porcentagem.
 * @param total Total em relação ao qual será calculada a porcentagem.
 * @return Retorna o valor da porcentagem.
 */
float porcentagem(int valor, int total);

/**
 * @brief Contabiliza um voto para Presidente.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param votoP Identificador do candidato a Presidente.
 * @return Retorna a estrutura tVoto com o voto contabilizado.
 */
tVoto contabilizaVotoPrisidente(tVoto votos, int votoP);

/**
 * @brief Contabiliza um voto para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param votoM Identificador do candidato a Primeiro Ministro.
 * @return Retorna a estrutura tVoto com o voto contabilizado.
 */
tVoto contabilizaVotoPMinistro(tVoto votos, int votoM);

/**
 * @brief Verifica o vencedor da eleição para presidente.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o identificador do candidato vencedor, ou SEM DECISAO ou EMPATE em caso de empate.
 */
int vencedorPresidente(tVoto votos);

/**
 * @brief Verifica o vencedor da eleição para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o identificador do candidato vencedor, ou SEM DECISAO ou EMPATE em caso de empate.
 */
int vencedorPMinistro(tVoto votos);

/**
 * @brief Obtém o total de votos para a presidência.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o total de votos para a presidência.
 */
int obtemTotalVotosPresidente(tVoto votos);

/**
 * @brief Obtém o total de votos para Primeiro Ministro.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @return Retorna o total de votos para Primeiro Ministro.
 */
int obtemTotalVotosPMinistro(tVoto votos);

/**
 * @brief Imprime o resultado da eleição.
 * @param votos Estrutura tVoto contendo os votos da eleição.
 * @param totalP Total de votos para a presidência.
 * @param totalM Total de votos para Primeiro Ministro.
 * @param vencedorP Identificador do candidato vencedor para a presidência.
 * @param vencedorM Identificador do candidato vencedor para Primeiro Ministro.
 * @param counterQtd Contador de votos válidos.
 * @param qtd Quantidade de eleitores.
 */
void printaResultado(tVoto votos, int totalP, int totalM, int vencedorP, int vencedorM, int counterQtd, int qtd);

#endif