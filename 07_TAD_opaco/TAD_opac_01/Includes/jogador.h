#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"
#include "jogada.h"

#define ID_JOGADOR_1 1 /**< ID do jogador 1. */
#define ID_JOGADOR_2 2 /**< ID do jogador 2. */

/**
 * @brief Tipo opaco que representa um jogador que possui pelo menos os seguintes atributos:
 * o seu ID.
 */
typedef struct Jogador tJogador;


/**
 * @brief Cria um jogador.
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @param idJogador O ID do jogador (ID_JOGADOR_1 ou ID_JOGADOR_2).
 * @return tJogador* Ponteiro para o jogador criado.
 */
tJogador* CriaJogador(int idJogador);


/**
 * @brief Libera a memória de um jogador.
 *
 * @param jogador Ponteiro para o jogador a ser destruído.
 */
void DestroiJogador(tJogador* jogador);

/**
 * @brief Verifica, nesta ordem, se a jogada foi lida corretamente, se a posição informada
 * é válida e se está livre no tabuleiro (utilizando suas funções apropriadas).
 * Se a jogada for inválida, imprime o motivo (onde x e y são as coordenadas da jogada):
 * - formato inválido: descarta o restante da linha da entrada padrão (até o '\n',
 *   inclusive) e imprime "Formato invalido!\n";
 * - fora do tabuleiro: "Posicao invalida (FORA DO TABULEIRO - [x,y] )!\n";
 * - posição ocupada:   "Posicao invalida (OCUPADA - [x,y] )!\n".
 *
 * @param jogada Ponteiro para a jogada a ser verificada.
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 * @return int 1 se a jogada for válida, 0 caso contrário.
 */
int EhJogadaValida(tJogada* jogada, tTabuleiro* tabuleiro);

/**
 * @brief Realiza uma jogada do jogador, repetindo a leitura até que seja informada uma
 * posição válida e livre no tabuleiro.
 * A cada tentativa, imprime "Jogador <id>\n" e lê a jogada (utilizando sua função apropriada).
 * Quando a jogada for válida, imprime "Jogada [x,y]!\n" e marca a posição no tabuleiro com a
 * peça do jogador (o jogador 1 usa PECA_1 e o jogador 2 usa PECA_2).
 *
 * @param jogador Ponteiro para o jogador atual.
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro);


/**
 * @brief Verifica se o jogador venceu o jogo (completou uma linha, uma coluna ou uma diagonal
 * com a sua peça).
 *
 * @param jogador Ponteiro para o jogador atual.
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 * @return int 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro);

#endif
