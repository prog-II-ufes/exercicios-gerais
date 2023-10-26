#ifndef _franquia
#define _franquia

/**
 * @brief Estrutura que representa uma franquia.
 * 
 * A estrutura franquia contém informações sobre o nome da franquia, sua conferência e seu desempenho em casa e fora.
 * 
 */
typedef struct franquia * tFranquia;

#define MAX_NOME 32

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 * 
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia();

/**
 * @brief Libera a memória alocada para uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f);

/**
 * @brief Imprime as informações de uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f);

/**
 * @brief Retorna o nome da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char * GetNomeFranquia(tFranquia f);

/**
 * @brief Retorna a conferência da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char * GetConferenciaFranquia(tFranquia f);

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f);

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f);

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f);

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f);

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f);

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f);

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f);

#endif