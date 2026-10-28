#ifndef _PACIENTE_H
#define _PACIENTE_H

#define MAX_NOME_PAC 101   /**< Tamanho do vetor do nome: até 100 caracteres (+1 para o '\0'), pode ter espaços. */
#define MAX_CARTAO_SUS 19  /**< Tamanho do vetor do cartão SUS, no padrão 000-0000-0000-0000: 18 caracteres (+1 para o '\0'). */

#include "data.h"
#include "lesao.h"

/**
 * @brief Tipo opaco que representa um paciente que possui pelo menos os seguintes atributos:
 * nome, cartão SUS, gênero, data de nascimento e a lista de lesões. Não há limite para a
 * quantidade de lesões de um paciente (a lista deve crescer conforme a necessidade).
 */
typedef struct Paciente tPaciente;

/**
 * @brief Cria um paciente a partir dos dados fornecidos, ainda sem lesões.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @param nome Nome do paciente.
 * @param cartaoSus Cartão SUS do paciente.
 * @param genero Gênero do paciente.
 * @param dataNasc Ponteiro para a data de nascimento do paciente.
 * @return tPaciente* Ponteiro para o paciente criado.
 */
tPaciente *criaPaciente(char *nome, char *cartaoSus, char genero, tData *dataNasc);

/**
 * @brief Lê os dados de um paciente da entrada padrão.
 * Assuma que o caractere 'P' já foi lido. Esta função lê as 4 linhas seguintes: nome, data de
 * nascimento (utilizando sua função apropriada), cartão SUS e gênero, inclusive a quebra de linha da última.
 *
 * @return tPaciente* Ponteiro para o paciente lido.
 */
tPaciente *lerPaciente();

/**
 * @brief Adiciona uma lesão ao final da lista de lesões do paciente.
 *
 * @param p Ponteiro para o paciente ao qual a lesão será vinculada.
 * @param l Ponteiro para a lesão a ser vinculada ao paciente.
 */
void adicionaLesaoPaciente(tPaciente *p, tLesao *l);

/**
 * @brief Calcula a idade do paciente em anos completos com base em uma data de referência
 * (utilizando sua função apropriada).
 *
 * @param p Ponteiro para o paciente cuja idade será calculada.
 * @param dataBase Ponteiro para a data de referência para o cálculo da idade.
 * @return int A idade do paciente em anos completos.
 */
int calculaIdadePaciente(tPaciente *p, tData *dataBase);

/**
 * @brief Obtém o cartão SUS de um paciente.
 *
 * @param p Ponteiro para o paciente.
 * @return char* O cartão SUS do paciente (a string pertence ao paciente; não a libere).
 */
char *obtemCartaoSusPaciente(tPaciente *p);

/**
 * @brief Obtém o número de lesões associadas a um paciente.
 *
 * @param p Ponteiro para o paciente.
 * @return int O número de lesões do paciente.
 */
int obtemNumLesoesPaciente(tPaciente *p);

/**
 * @brief Calcula a quantidade de lesões cirúrgicas associadas a um paciente
 * (utilizando sua função apropriada).
 *
 * @param p Ponteiro para o paciente.
 * @return int A quantidade de lesões cirúrgicas do paciente.
 */
int qtdLesoesCirurgicasPaciente(tPaciente *p);

/**
 * @brief Imprime o nome do paciente e o identificador das suas lesões: primeiro "- <nome> - ",
 * em seguida o identificador de cada lesão (utilizando sua função apropriada) na ordem de
 * cadastro e, por fim, uma quebra de linha. Ex.: "- SON GOKU - L1 L3 \n".
 * Se o paciente não tiver lesões, não imprime nada.
 *
 * @param p Ponteiro para o paciente a ser impresso.
 */
void imprimePaciente(tPaciente *p);

/**
 * @brief Libera a memória de um paciente, inclusive a da data de nascimento e a das lesões
 * (utilizando suas funções apropriadas).
 *
 * @param p Ponteiro para o paciente a ser liberado.
 */
void liberaPaciente(tPaciente *p);

#endif
