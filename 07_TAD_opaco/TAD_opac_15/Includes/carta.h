#ifndef _cartas
#define _cartas

#include <stdbool.h>

/**
 * @brief Tamanho do vetor usado para ler o nome de uma carta: até 50 caracteres
 * (+1 para o '\0').
 */
#define MAX_NOME 51

/**
 * @brief Tipo opaco que representa uma carta: identificador, nome, poderes de magia,
 * força e fogo, e número de vitórias.
 */
typedef struct Carta tCarta;

/**
 * @brief Lê uma carta da entrada padrão e retorna um ponteiro para ela.
 *
 * Assuma que o caractere 'C' já foi lido. Esta função lê o restante das informações da carta,
 * que ocupa três linhas: o identificador, o nome (pode conter espaços) e os poderes de magia, força e fogo, nesta ordem. 
 * A carta começa com zero vitórias.
 *
 * @return Ponteiro para a carta lida.
 */
tCarta* LeCarta();

/**
 * @brief Libera a memória alocada para uma carta.
 * @param c Ponteiro para a carta a ser liberada.
 */
void LiberaCarta(tCarta* c);

/**
 * @brief Retorna o ID de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o ID da carta.
 */
int ObtemIdCarta(tCarta* c);

/**
 * @brief Retorna o nome de uma carta.
 * @param c Ponteiro para a carta.
 * @return O nome da carta (a string pertence à carta; não a libere).
 */
char * ObtemNomeCarta(tCarta* c);

/**
 * @brief Retorna o número de vitórias de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o número de vitórias da carta.
 */
int ObtemNumVitCarta(tCarta* c);

/**
 * @brief Retorna o valor de magia de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de magia da carta.
 */
int ObtemMagiaCarta(tCarta* c);

/**
 * @brief Retorna o valor de força de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de força da carta.
 */
int ObtemForcaCarta(tCarta* c);

/**
 * @brief Retorna o valor de fogo de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de fogo da carta.
 */
int ObtemFogoCarta(tCarta* c);

/**
 * @brief Verifica se uma carta é válida: nenhum dos três poderes é maior que 30 e a
 * soma dos três não é maior que 80.
 * @param c Ponteiro para a carta.
 * @return Retorna true se a carta é válida e false caso contrário.
 */
bool EhCartaValida(tCarta* c);

/**
 * @brief Verifica se duas cartas possuem o mesmo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna true se as cartas possuem o mesmo ID e false caso contrário.
 */
bool EhMesmoIdCarta(tCarta* c1, tCarta* c2);

/*
 * As funções Compara*Carta abaixo comparam um valor inteiro das duas cartas e retornam
 * exatamente: -1 se o valor de c1 for menor que o de c2, 0 se forem iguais e 1 se o
 * valor de c1 for maior que o de c2.
 */

/**
 * @brief Compara duas cartas pelo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return -1 se o ID de c1 for menor que o de c2, 0 se forem iguais
 *         e 1 se o ID de c1 for maior que o de c2.
 */
int ComparaIdCarta(tCarta* c1, tCarta* c2);

/**
 * @brief Compara duas cartas pelo valor de magia.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return -1 se a magia de c1 for menor que a de c2, 0 se forem iguais
 *         e 1 se a magia de c1 for maior que a de c2.
 */
int ComparaMagiaCarta(tCarta* c1, tCarta* c2);

/**
 * @brief Compara duas cartas pelo valor de força.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return -1 se a força de c1 for menor que a de c2, 0 se forem iguais
 *         e 1 se a força de c1 for maior que a de c2.
 */
int ComparaForcaCarta(tCarta* c1, tCarta* c2);

/**
 * @brief Compara duas cartas pelo valor de fogo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return -1 se o fogo de c1 for menor que o de c2, 0 se forem iguais
 *         e 1 se o fogo de c1 for maior que o de c2.
 */
int ComparaFogoCarta(tCarta* c1, tCarta* c2);

/**
 * @brief Adiciona uma vitória para uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o novo número de vitórias da carta.
 */
int AdicionaVitoriaCarta(tCarta* c);

#endif
