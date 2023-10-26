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
 * @brief Estrutura que representa uma partida.
 * 
 * A estrutura partida contém informações sobre os times que jogaram e o vencedor da partida.
 * 
 */
typedef struct partida * tPartida;

/**
 * @brief Lê uma partida do teclado.
 * 
 * @return tPartida Retorna um ponteiro para a partida lida.
 */
tPartida LePartida();

/**
 * @brief Libera a memória alocada para uma partida.
 * 
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p);

/**
 * @brief Imprime as informações de uma partida.
 * 
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p);

/**
 * @brief Retorna o nome do time da casa.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char * GetTime1Partida(tPartida p);

/**
 * @brief Retorna o nome do time visitante.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char * GetTime2Partida(tPartida p);

/**
 * @brief Retorna o vencedor da partida.
 * 
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p);

#endif