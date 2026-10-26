#ifndef _dracomania
#define _dracomania

#define CADASTRAR 'C' /**< Opção para cadastrar uma nova carta. */
#define LUTAR 'L' /**< Opção para iniciar uma luta entre duas cartas. */
#define FINALIZAR 'F' /**< Opção para finalizar o programa. */

/**
 * @brief Tipo opaco que representa o jogo: as cartas cadastradas, os duelos realizados e
 * a quantidade de cartas descartadas. Não há limite para a quantidade de cartas ou de duelos 
 * (os vetores devem crescer conforme a necessidade).
 */
typedef struct Dracomania tDracomania;


/**
 * @brief Cria um jogo vazio (sem cartas, sem duelos e sem descartes).
 * Todos os campos da estrutura devem ser inicializados aqui. 
 * 
 * @return Ponteiro para o jogo criado.
 */
tDracomania* CriaDracomania();

/**
 * @brief Lê toda a entrada padrão até o caractere FINALIZAR, cadastrando cartas e
 * realizando duelos.
 *
 * Esta função lê o caractere de cada operação (CADASTRAR ou LUTAR) e chama LeCarta ou
 * LeDuelo para ler o restante. Regras:
 * - carta inválida: é descartada e conta como descartada;
 * - carta válida com um ID que já existe: substitui a carta antiga, na mesma posição
 *   da lista (a antiga é liberada);
 * - carta inválida com um ID que já existe: a carta antiga é mantida e a nova conta
 *   como descartada;
 * - os duelos sempre são entre duas cartas já cadastradas.
 * O jogo passa a ser responsável por liberar as cartas e os duelos guardados.
 *
 * @param d Ponteiro para o jogo.
 */
void RodaDracomania(tDracomania* d);

/**
 * @brief Imprime o relatório final do jogo, uma informação por linha:
 *     Quantidade de Cartas: <cartas cadastradas>
 *     Quantidade de descartadas: <cartas descartadas>
 *     Quantidade de lutas: <duelos realizados>
 * Se houve pelo menos um duelo, imprime também:
 *     Lutas que foram desempatadas: <duelos decididos pelo menor ID>
 *     Carta mais vitoriosa: <nome da carta com mais vitórias>
 *     Luta com Maior Diferenca: <ID do duelo com a maior diferença>
 * Empates: a carta mais vitoriosa é a primeira na ordem de cadastro e a luta com maior
 * diferença é a primeira na ordem em que os duelos foram realizados.
 * @param d Ponteiro para o jogo.
 */
void ImprimeRelatorioDracomania(tDracomania* d);

/**
 * @brief Libera a memória alocada para o jogo, inclusive as cartas e os duelos.
 * @param d Ponteiro para o jogo.
 */
void LiberaDracomania(tDracomania* d);

#endif
