#ifndef _duelo
#define _duelo

#include <stdbool.h>
#include "carta.h"
/**
 * @brief Estrutura de dados que representa um duelo entre duas cartas.
 */
typedef struct duelo *tDuelo;

#define MAGIA 'M' /**< Opção para duelo de magia. */
#define FORCA 'F' /**< Opção para duelo de força. */
#define FOGO 'G' /**< Opção para duelo de fogo. */

/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo LeDuelo();

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo d);

/**
 * @brief Imprime as informações de um duelo.
 * @param d Ponteiro para o duelo a ser impresso.
 */
void ImprimeDuelo(tDuelo d);

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2);

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int GetC1Duelo(tDuelo d);

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int GetC2Duelo(tDuelo d);

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool GetDesempateDuelo(tDuelo d);

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int GetDiferencaDuelo(tDuelo d);

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int GetIdDuelo(tDuelo d);

#endif