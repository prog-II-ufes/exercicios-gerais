#ifndef _jogo
#define _jogo

#define MIN_N 1  /**< Menor valor aceito para n. */
#define MAX_N 10 /**< Maior valor aceito para n (o 10º primo de Fibonacci é o maior que cabe em um int). */

/**
 * @brief Tipo opaco que representa um jogo (uma rodada) que possui pelo menos os seguintes atributos:
 * o intervalo [min, max], o valor x a ser adivinhado e o número máximo de tentativas mc.
 */
typedef struct Jogo tJogo;

/**
 * @brief Cria um jogo "vazio".
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tJogo* Ponteiro para o jogo criado.
 */
tJogo* CriaJogo();

/**
 * @brief Libera a memória de um jogo.
 *
 * @param jogo Ponteiro para o jogo a ser destruído.
 */
void DestroiJogo(tJogo* jogo);

/**
 * @brief Define o valor máximo do intervalo do jogo.
 *
 * @param jogo Ponteiro para o jogo.
 * @param max O valor máximo do intervalo.
 */
void DefineMaximo(tJogo* jogo, int max);

/**
 * @brief Define o valor mínimo do intervalo do jogo.
 *
 * @param jogo Ponteiro para o jogo.
 * @param min O valor mínimo do intervalo.
 */
void DefineMinimo(tJogo* jogo, int min);

/**
 * @brief Calcula e guarda no jogo o valor x a ser adivinhado, como descrito no enunciado.
 * O intervalo já deve ter sido definido. Os primos da série de Fibonacci são contados a partir
 * de 1: o 1º é 2, o 2º é 3, o 3º é 5, o 4º é 13 e assim por diante.
 *
 * @param jogo Ponteiro para o jogo.
 * @param n A posição do primo de Fibonacci desejado (entre MIN_N e MAX_N).
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n);

/**
 * @brief Calcula e guarda no jogo o número máximo de tentativas, como descrito no enunciado.
 * O intervalo já deve ter sido definido.
 *
 * @param jogo Ponteiro para o jogo.
 */
void CalculaNumeroTentativas(tJogo *jogo);

/**
 * @brief Executa as tentativas do jogador. Primeiro imprime "Voce tem direito a <mc> tentativas\n".
 * Em seguida, para cada tentativa i (começando em 1), imprime "Tentativa <i>: \n" e lê um inteiro:
 * - fora do intervalo: imprime "A tentativa esta fora do intervalo. Tente novamente\n"
 *   e a tentativa NÃO é contada (a próxima leitura repete o mesmo número i);
 * - igual a x: imprime "Parabens, voce ganhou!\n" e o jogo termina;
 * - maior que x: imprime "Alta\n";
 * - menor que x: imprime "Baixa\n".
 * Se as mc tentativas acabarem sem acerto, imprime "Voce perdeu! O numero escolhido foi <x>\n".
 *
 * @param jogo Ponteiro para o jogo.
 * @return int 1 se o jogador venceu o jogo, 0 caso contrário.
 */
int ProcessaTentativas(tJogo* jogo);

#endif
