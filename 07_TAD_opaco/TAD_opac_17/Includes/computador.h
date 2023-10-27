#ifndef _computador
#define _computador

#include "jogo.h"

typedef struct Computador tComputador; 

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tComputador
 * 
 * @return A variável do tipo Computador inicializada.
 */
tComputador* CriaComputador();

/**
 * @brief Libera toda a memória alocada para uma variável do tipo computador.
 * 
 * @param comp - A variável do tipo Computador que terá sua memória liberada
 */
void DestroiComputador(tComputador* comp);

/**
 * @brief Função que gerencia o jogo. Recebe os dados da entrada padrão, os processa e "lida" com as funções necessárias de jogo.
 * 
 * @param computador - Variável computador que salvará o "log" das jogadas, para mostrar o relatório final (apresentado no roteiro)
 */
void GerenciaJogo(tComputador *computador);

/**
 * @brief Imprime o relatório "da rodada", mostrado quandoDefine o valor máximo do intervalo que o jogo deve considerar o jogador não deseja jogar novamente, como mostra o roteiro.
 * 
 * @param computador - A variável do tipo computador que terá seus dados apresentados em tela.
 */
void ImprimeRelatorio (tComputador* computador);

#endif
