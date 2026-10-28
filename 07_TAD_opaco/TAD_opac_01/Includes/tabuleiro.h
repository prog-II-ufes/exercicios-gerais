#ifndef _TABULEIRO_H
#define _TABULEIRO_H


#define TAM_TABULEIRO 3 /**< Quantidade de linhas e de colunas do tabuleiro. */
#define PECA_1 1 /**< Peça do jogador 1, impressa como 'X' (xis maiúsculo). */
#define PECA_2 2 /**< Peça do jogador 2, impressa como '0' (o algarismo zero). */

/**
 * @brief Tipo opaco que representa um tabuleiro que possui pelo menos os seguintes atributos:
 * as posições do tabuleiro (TAM_TABULEIRO x TAM_TABULEIRO).
 * Coordenadas: x é a COLUNA e y é a LINHA. A posição (0,0) é o canto superior esquerdo,
 * e x e y vão de 0 a TAM_TABULEIRO-1. Ex.: a jogada [2,0] fica na primeira linha, última coluna.
 */
typedef struct Tabuleiro tTabuleiro;


/**
 * @brief Cria um tabuleiro com todas as posições livres.
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tTabuleiro* Ponteiro para o tabuleiro criado.
 */
tTabuleiro* CriaTabuleiro();


/**
 * @brief Libera a memória de um tabuleiro.
 *
 * @param tabuleiro Ponteiro para o tabuleiro a ser destruído.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro);


/**
 * @brief Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 * @param peca A peça do jogador (PECA_1 ou PECA_2).
 * @param x A coordenada X da posição.
 * @param y A coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y);


/**
 * @brief Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 * @return int 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro);


/**
 * @brief Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 * @param x A coordenada X da posição.
 * @param y A coordenada Y da posição.
 * @param peca A peça do jogador (PECA_1 ou PECA_2).
 * @return int 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca);


/**
 * @brief Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro Ponteiro para o tabuleiro atual.
 * @param x A coordenada X da posição.
 * @param y A coordenada Y da posição.
 * @return int 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y);


/**
 * @brief Verifica se a posição está dentro do tabuleiro.
 *
 * @param x A coordenada X da posição.
 * @param y A coordenada Y da posição.
 * @return int 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y);


/**
 * @brief Imprime o tabuleiro, uma linha do tabuleiro por linha da saída. Cada linha começa com
 * um caractere de tabulação ('\t') seguido de 3 caracteres que representam as posições daquela
 * linha, sem espaços entre eles, que podem ser: 'X' para PECA_1, '0' para PECA_2 e '-' para posição livre.
 * Uma linha do tabuleiro que possui apenas um 'X' na posição central é representada como: "\t-X-\n".
 *
 * @param tabuleiro Ponteiro para o tabuleiro a ser impresso.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro);


#endif
