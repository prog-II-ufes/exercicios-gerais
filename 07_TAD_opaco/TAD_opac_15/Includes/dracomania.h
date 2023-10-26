#ifndef _dracomania
#define _dracomania

#define TAM_LISTA 1 /**< Tamanho da lista de cartas. */
#define CADASTRAR 'C' /**< Opção para cadastrar uma nova carta. */
#define LUTAR 'L' /**< Opção para iniciar uma luta entre duas cartas. */
#define FINALIZAR 'F' /**< Opção para finalizar o programa. */

typedef struct dracomania *tDracomania;


/**
 * @brief Cria uma nova instância do jogo Dracomania.
 * @return Retorna um ponteiro para a estrutura criada.
 */
tDracomania CriaDracomania();

/**
 * @brief Roda o jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 * @return Retorna um ponteiro para a instância do jogo atualizada.
 */
tDracomania RodaDracomania(tDracomania d);

/**
 * @brief Imprime o relatório final do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void ImprimeRelatorioDracomania(tDracomania d);

/**
 * @brief Libera a memória alocada para a instância do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void LiberaDracomania(tDracomania d);

#endif