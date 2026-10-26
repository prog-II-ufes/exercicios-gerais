#ifndef _partida
#define _partida

/**
 * @brief Constante que representa o time da casa.
 * 
 */
#define TIME_CASA 1

/**
 * @brief Constante que representa o time visitante.
 * 
 */
#define TIME_FORA 2

/**
 * @brief Tamanho dos vetores usados para ler nomes de times e de conferências:
 * até 32 caracteres (+1 para o '\0').
 */
#define MAX_NOME 33

/**
 * @brief Tipo opaco que representa uma partida: os dois times e os pontos de cada um.
 */
typedef struct Partida tPartida;

/**
 * @brief Lê uma partida da entrada padrão.
 *
 * Esta função lê apenas informações de uma partida: o time visitante (fora de casa), o caractere '@', 
 * o time da casa, os pontos do visitante e os pontos do time da casa.
 *
 * @return tPartida* Ponteiro para a partida lida (alocado dinamicamente).
 */
tPartida* LePartida();

/**
 * @brief Libera a memória alocada para uma partida.
 *
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida* p);

/**
 * @brief Retorna o nome do time da casa.
 *
 * @param p Ponteiro para a partida.
 * @return char* O nome do time da casa.
 */
char * GetTimeCasaPartida(tPartida* p);

/**
 * @brief Retorna o nome do time visitante.
 *
 * @param p Ponteiro para a partida.
 * @return char* O nome do time visitante.
 */
char * GetTimeForaPartida(tPartida* p);

/**
 * @brief Retorna o vencedor da partida (o time que fez mais pontos; não há empate).
 *
 * @param p Ponteiro para a partida.
 * @return int TIME_CASA se o time da casa venceu, TIME_FORA caso contrário.
 */
int GetVencedorPartida(tPartida* p);

#endif
