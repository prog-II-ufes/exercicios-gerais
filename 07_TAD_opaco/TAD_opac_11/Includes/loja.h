#ifndef _LOJA_H_
#define _LOJA_H_

#include "vendedor.h"

/**
 * @brief Tipo opaco que representa uma loja que possui pelo menos os seguintes atributos:
 * ID, valor do aluguel e a lista de vendedores contratados. Não há limite para a quantidade
 * de vendedores (a lista deve crescer conforme a necessidade).
 */
typedef struct Loja tLoja;

/**
 * @brief Abre uma nova loja, ainda sem vendedores.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja* Ponteiro para a loja aberta.
 */
tLoja* AbreLoja(int id, float aluguel);

/**
 * @brief Libera a memória de uma loja, inclusive a dos seus vendedores (utilizando sua função apropriada).
 *
 * @param loja Ponteiro para a loja a ser apagada.
 */
void ApagaLoja(tLoja* loja);

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 *
 * @param loja Ponteiro para a loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int 1 se o ID da loja é igual ao ID passado como parâmetro, 0 caso contrário.
 */
int VerificaIdLoja(tLoja* loja, int id);

/**
 * @brief Contrata um novo vendedor para a loja, adicionando-o ao final da lista de vendedores.
 *
 * @param loja Ponteiro para a loja.
 * @param vendedor Ponteiro para o vendedor a ser contratado.
 */
void ContrataVendedor(tLoja* loja, tVendedor* vendedor);

/**
 * @brief Registra uma nova venda para um vendedor da loja (utilizando sua função apropriada).
 * Se a loja não tiver um vendedor com esse nome, nada acontece. Pode-se assumir que não há
 * dois vendedores com o mesmo nome na mesma loja.
 *
 * @param loja Ponteiro para a loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 */
void RegistraVenda(tLoja* loja, char* nome, float valor);

/**
 * @brief Imprime o relatório da loja: primeiro a linha "Loja <id>: Lucro total: R$ <lucro>\n" e,
 * em seguida, o relatório de cada vendedor (utilizando sua função apropriada) na ordem de contratação.
 * Todos os valores numéricos são impressos com 2 casas decimais.
 *
 * @param loja Ponteiro para a loja a ser impressa.
 */
void ImprimeRelatorioLoja(tLoja* loja);

#endif
