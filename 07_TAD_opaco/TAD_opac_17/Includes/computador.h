#ifndef _computador
#define _computador


#define MAX_INTERVALO 1000000000 /**< O max do intervalo deve ser menor que este valor. */

/**
 * @brief Tipo opaco que representa o computador que possui pelo menos os seguintes atributos:
 * o número de jogos jogados, o número de vitórias e o número de derrotas do jogador.
 */
typedef struct Computador tComputador;

/**
 * @brief Cria um computador, ainda sem nenhum jogo jogado.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tComputador* Ponteiro para o computador criado.
 */
tComputador* CriaComputador();

/**
 * @brief Libera a memória de um computador.
 *
 * @param comp Ponteiro para o computador a ser destruído.
 */
void DestroiComputador(tComputador* comp);

/**
 * @brief Gerencia os jogos, como descrito no enunciado, até o jogador não desejar mais jogar.
 * Mensagens impressas por esta função:
 * - no início: "Jogo de adivinhacao\n";
 * - pedido de n: "Forneca um numero no intervalo entre 1 e 10: \n";
 * - pedido do intervalo: "Forneca um intervalo de numeros naturais: \n";
 * - caso o intervalo seja inválido, imprime um dos erros abaixo (se houver mais de um erro, vale o primeiro erro seguindo a ordem abaixo):
 *     "O intervalo deve ser composto de numeros naturais!\n"
 *     "O segundo numero do intervalo deve ser menor que 1.000.000.000\n"
 *     "O primeiro numero do intervalo deve ser inferior ao segundo\n";
 * - pergunta de continuação: "Deseja continuar a jogar (s/n): \n";
 * - resposta diferente de 's' e 'n' para a continuação, imprime: "Voce deve digitar s ou n!\n".
 * Sempre que um valor lido for inválido, a mesma pergunta é repetida. Para n fora do
 * intervalo, nenhuma mensagem de erro é impressa.
 *
 * @param computador Ponteiro para o computador, que guarda o resultado dos jogos.
 */
void GerenciaJogo(tComputador *computador);

/**
 * @brief Imprime o relatório final, mostrado quando o jogador não deseja mais jogar:
 * "Obrigado por jogar comigo. Desta vez, voce jogou <jogos> jogo(s), ganhou <vitorias> jogo(s)
 * e perdeu <derrotas> jogo(s). Ate a proxima!\n" (em uma única linha).
 *
 * @param computador Ponteiro para o computador.
 */
void ImprimeRelatorio (tComputador* computador);

#endif
