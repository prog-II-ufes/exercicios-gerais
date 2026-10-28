#ifndef _LESAO_H
#define _LESAO_H

#define MAX_CARTAO_LES 19  /**< Tamanho do vetor do cartão SUS, no padrão 000-0000-0000-0000: 18 caracteres (+1 para o '\0'). */
#define MAX_ID_LES 11      /**< Tamanho do vetor do identificador: até 10 caracteres (+1 para o '\0'). */
#define MAX_DIAG_LES 101   /**< Tamanho do vetor do diagnóstico: até 100 caracteres (+1 para o '\0'), pode ter espaços. */
#define MAX_REG_LES 101    /**< Tamanho do vetor da região do corpo: até 100 caracteres (+1 para o '\0'), pode ter espaços. */

/**
 * @brief Tipo opaco que representa uma lesão que possui pelo menos os seguintes atributos:
 * cartão SUS do paciente, identificador, diagnóstico, região do corpo e porcentagem de malignidade.
 */
typedef struct Lesao tLesao;

/**
 * @brief Cria uma lesão a partir dos dados fornecidos.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @param cartaoSus Cartão SUS do paciente associado à lesão.
 * @param id Identificador único da lesão.
 * @param diagnostico Diagnóstico da lesão.
 * @param regiao Região do corpo onde a lesão está localizada.
 * @param malignidade Porcentagem de malignidade da lesão (inteiro de 0 a 100).
 * @return tLesao* Ponteiro para a lesão criada.
 */
tLesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade);

/**
 * @brief Lê os dados de uma lesão da entrada padrão.
 * Assuma que o caractere 'L' já foi lido. Esta função lê as 5 linhas seguintes: cartão SUS,
 * identificador, diagnóstico, região e porcentagem de malignidade, inclusive a quebra de linha da última.
 *
 * @return tLesao* Ponteiro para a lesão lida.
 */
tLesao *lerLesao();

/**
 * @brief Obtém o cartão SUS associado a uma lesão.
 *
 * @param l Ponteiro para a lesão.
 * @return char* O cartão SUS da lesão (a string pertence à lesão; não a libere).
 */
char *obtemCartaoSusLesao(tLesao *l);

/**
 * @brief Verifica se uma lesão é cirúrgica, ou seja, se a porcentagem de malignidade é maior que 50.
 *
 * @param l Ponteiro para a lesão a ser verificada.
 * @return int 1 se a lesão for cirúrgica, 0 caso contrário.
 */
int verificaCirurgicaLesao(tLesao *l);

/**
 * @brief Imprime o identificador de uma lesão seguido de UM espaço, sem quebra de linha.
 * Ex.: para a lesão L8, imprime "L8 ".
 *
 * @param l Ponteiro para a lesão cujo identificador será impresso.
 */
void imprimeIdLesao(tLesao *l);

/**
 * @brief Libera a memória de uma lesão.
 *
 * @param l Ponteiro para a lesão a ser liberada.
 */
void liberaLesao(tLesao *l);

#endif
