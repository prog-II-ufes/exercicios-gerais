#ifndef _JOGO_H
#define _JOGO_H

#include "jogador.h"
#include "tabuleiro.h"

/**
 * @brief Tipo opaco que representa um jogo que possui pelo menos os seguintes atributos:
 * o tabuleiro e os dois jogadores.
 */
typedef struct Jogo tJogo;


/**
 * @brief Cria um jogo novo, com o tabuleiro vazio e os dois jogadores (utilizando suas funções apropriadas).
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tJogo* Ponteiro para o jogo criado.
 */
tJogo* CriaJogo();


/**
 * @brief Executa o jogo, alternando as jogadas entre os jogadores até que haja um vencedor ou
 * o jogo termine sem vencedor.
 * O jogador 1 começa. Depois de cada jogada, o tabuleiro é impresso (utilizando sua função apropriada).
 * No fim, imprime "JOGADOR 1 Venceu!\n", "JOGADOR 2 Venceu!\n" ou "Sem vencedor!\n".
 *
 * @param jogo Ponteiro para o jogo a ser executado.
 */
void ExecutaJogo(tJogo* jogo);


/**
 * @brief Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo Ponteiro para o jogo atual.
 * @return int 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo);


/**
 * @brief Verifica se o usuário deseja jogar novamente.
 * Imprime "Jogar novamente? (s,n)\n" e lê a entrada padrão ignorando todos os caracteres
 * que não forem 's' ou 'n' (por exemplo, números que sobraram depois do fim da partida).
 * Ao encontrar 's' ou 'n', descarta o restante daquela linha. Se a entrada acabar,
 * considera 'n'.
 *
 * @return int 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo();


/**
 * @brief Libera a memória de um jogo, inclusive a do tabuleiro e a dos jogadores
 * (utilizando suas funções apropriadas).
 *
 * @param jogo Ponteiro para o jogo a ser destruído.
 */
void DestroiJogo(tJogo* jogo);

#endif
