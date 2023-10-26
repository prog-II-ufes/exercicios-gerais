#ifndef _cartas
#define _cartas

#include <stdbool.h>

#define MAX_NOME 100

typedef struct carta * tCarta;

/**
 * @brief Lê uma carta do usuário e retorna um ponteiro para ela.
 * @return Retorna um ponteiro para a carta lida.
 */
tCarta LeCarta();

/**
 * @brief Libera a memória alocada para uma carta.
 * @param c Ponteiro para a carta a ser liberada.
 */
void LiberaCarta(tCarta c);

/**
 * @brief Imprime as informações de uma carta.
 * @param c Ponteiro para a carta a ser impressa.
 */
void ImprimeCarta(tCarta c);

/**
 * @brief Retorna o ID de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o ID da carta.
 */
int GetIdCarta(tCarta c);

/**
 * @brief Retorna o nome de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o nome da carta.
 */
char * GetNomeCarta(tCarta c);

/**
 * @brief Retorna o número de vitórias de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o número de vitórias da carta.
 */
int GetNumVitCarta(tCarta c);

/**
 * @brief Retorna o valor de magia de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de magia da carta.
 */
int GetMagiaCarta(tCarta c);

/**
 * @brief Retorna o valor de ataque de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de ataque da carta.
 */
int GetAtaqueCarta(tCarta c);

/**
 * @brief Retorna o valor de fogo de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de fogo da carta.
 */
int GetFogoCarta(tCarta c);

/**
 * @brief Verifica se uma carta é válida.
 * @param c Ponteiro para a carta.
 * @return Retorna true se a carta é válida e false caso contrário.
 */
bool EhCartaValida(tCarta c);

/**
 * @brief Verifica se duas cartas possuem o mesmo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna true se as cartas possuem o mesmo ID e false caso contrário.
 */
bool EhMesmoIdCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara duas cartas pelo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaIdCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara duas cartas pelo valor de magia.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaMagiaCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara duas cartas pelo valor de ataque.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaAtaqueCarta(tCarta c1, tCarta c2);

/**
 * @brief Compara duas cartas pelo valor de fogo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaFogoCarta(tCarta c1, tCarta c2);

/**
 * @brief Adiciona uma vitória para uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o novo número de vitórias da carta.
 */
int AdicionaVitoriaCarta(tCarta c);

#endif