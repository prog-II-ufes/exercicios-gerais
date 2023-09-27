#ifndef _VETOR_H_
#define _VETOR_H_

#define TAMANHO_MAXIMO 10

/**
 * @brief Ponteiro para função que recebe dois inteiros e realiza uma operação matemática.
 * 
 * return int Resultado da operação matemática.
*/
typedef int (*Operation)(int, int);

typedef struct vetor {
    int elementos[TAMANHO_MAXIMO];
    int tamanhoUtilizado;
} Vetor;


/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor);

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op);


#endif