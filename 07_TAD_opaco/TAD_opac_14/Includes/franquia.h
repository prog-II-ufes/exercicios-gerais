#ifndef _franquia
#define _franquia

/**
 * @brief Estrutura que representa uma franquia.
 * 
 * A estrutura franquia contém informações sobre o nome da franquia, sua conferência e seu desempenho em casa e fora.
 * 
 */
typedef struct Franquia tFranquia;

/**
 * @brief Tamanho dos vetores usados para ler nomes de times e de conferências:
 * até 32 caracteres (+1 para o '\0').
 */
#define MAX_NOME 33

/**
 * @brief Lê uma franquia da entrada padrão e retorna um ponteiro para ela.
 *
 * Esta função lê apenas as informaçoes de uma franquia: o nome do time e a conferência (LESTE ou OESTE). 
 * Ou seja, ela não é responsável por ler o caractere 'F' da entrada padrão.
 * A franquia começa sem vitórias e sem derrotas.
 *
 * @return tFranquia* Ponteiro para a franquia lida (alocada dinamicamente). 
 */
tFranquia* LeFranquia();

/**
 * @brief Libera a memória alocada para uma franquia.
 *
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia* f);

/**
 * @brief Imprime as informações de uma franquia em uma linha, no formato
 * "NOME [CL] V D APR VC VF\n", onde [CL] é a conferência leste ([CO] para a oeste),
 * V e D são o total de vitórias e de derrotas, APR é o aproveitamento em %, um número
 * inteiro calculado com divisão inteira, (V * 100) / (V + D), ou seja, a parte fracionária
 * é descartada (0 se não jogou), VC são as vitórias em casa e VF as vitórias fora.
 * Ex.: "CELTICS [CL] 5 5 50 3 2\n"; com 2 vitórias e 1 derrota, APR = 66.
 *
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia* f);

/**
 * @brief Retorna o nome da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* O nome da franquia.
 */
char * GetNomeFranquia(tFranquia* f);

/**
 * @brief Retorna a conferência da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* "LESTE" ou "OESTE".
 */
char * GetConferenciaFranquia(tFranquia* f);

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia* f);

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia* f);

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia* f);

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia* f);

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia* f);

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia* f);

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia* f);

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia* f);

#endif
