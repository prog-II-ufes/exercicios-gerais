#ifndef _JOGADA_H
#define _JOGADA_H

/**
 * @brief Tipo opaco que representa uma jogada que possui pelo menos os seguintes atributos:
 * as coordenadas x e y e se a leitura da jogada foi bem sucedida.
 */
typedef struct Jogada tJogada;


/**
 * @brief Cria uma jogada "vazia".
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tJogada* Ponteiro para a jogada criada.
 */
tJogada* CriaJogada();


/**
 * @brief Libera a memória de uma jogada.
 *
 * @param jogada Ponteiro para a jogada a ser destruída.
 */
void DestroiJogada(tJogada* jogada);


/**
 * @brief Imprime "Digite uma posicao (x e y):\n" e lê dois inteiros (x e y) da entrada padrão,
 * guardando também se a leitura foi bem sucedida (ou seja, se conseguiu ler os dois inteiros).
 * Esta função NÃO descarta o restante da linha quando o formato é inválido (isso é feito
 * na verificação da jogada, no jogador).
 *
 * @param jogada Ponteiro para a jogada a ser preenchida.
 */
void LeJogada(tJogada* jogada);


/**
 * @brief Obtém a coordenada X da jogada.
 *
 * @param jogada Ponteiro para a jogada.
 * @return int A coordenada X da jogada.
 */
int ObtemJogadaX(tJogada* jogada);


/**
 * @brief Obtém a coordenada Y da jogada.
 *
 * @param jogada Ponteiro para a jogada.
 * @return int A coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada* jogada);


/**
 * @brief Verifica se a leitura da jogada foi bem sucedida (se conseguiu ler os dois inteiros).
 *
 * @param jogada Ponteiro para a jogada.
 * @return int 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada* jogada);

#endif
