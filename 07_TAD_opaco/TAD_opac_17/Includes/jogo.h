#ifndef _jogo
#define _jogo

#include <math.h> // compilar com -lm

typedef struct Jogo tJogo;

/**
 * @brief Cria uma variável do tipo jogo
 * 
 * @return Uma variável do tipo jogo inicializada.
 */
tJogo* CriaJogo();

/**
 * @brief Libera toda a memória alocada para um jogo.
 * 
 * @param jogo - A variável do tipo jogo que será liberada.
 */
void DestroiJogo(tJogo* jogo);

/**
 * @brief Define o valor máximo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param max - o valor máximo do intervalo do jogo.
 */
void DefineMaximo(tJogo* jogo, int max);

/**
 * @brief Define o valor mínimo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param min - o valor mínimo do intervalo do jogo.
 */
void DefineMinimo(tJogo* jogo, int min);

/**
 * @brief Calcula o número a ser adivinhado pelo jogador
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n);

/**
 * @brief Calcula o número de tentativas que o usuário irá ter para acertar o número. 
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaNumeroTentativas(tJogo *jogo);

/**
 * @brief Executa o jogo. Calcula o que for necessário e lê as tentativas, fazendo as devidas verificações.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados.
 * @return int 1 se o usuário venceu o jogo ou 0 caso contrário
 */
int ProcessaTentativas(tJogo* jogo);

#endif
