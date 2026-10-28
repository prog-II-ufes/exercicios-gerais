#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_

#define MAX_NOME_VENDEDOR 50 /**< Tamanho do vetor para ler o nome: até 49 caracteres (+1 para o '\0'), uma única palavra. */

/**
 * @brief Tipo opaco que representa um vendedor que possui pelo menos os seguintes atributos:
 * nome, total vendido, salário e porcentagem de comissão.
 */
typedef struct Vendedor tVendedor;


/**
 * @brief Cria um novo vendedor, ainda sem vendas.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @param nome Nome do vendedor (o vendedor deve guardar a sua própria cópia do nome).
 * @param salario Salário base do vendedor.
 * @param prct_comissao Porcentagem de comissão do vendedor.
 * @return tVendedor* Ponteiro para o vendedor criado.
 */
tVendedor* CriaVendedor(char* nome, float salario, float prct_comissao);

/**
 * @brief Libera a memória de um vendedor.
 *
 * @param vendedor Ponteiro para o vendedor a ser apagado.
 */
void ApagaVendedor(tVendedor* vendedor);

/**
 * @brief Verifica se o nome de um vendedor é igual a outro.
 *
 * @param vendedor Ponteiro para o vendedor a ser verificado.
 * @param nome Nome do vendedor a ser comparado.
 * @return int 1 se o nome do vendedor é igual ao nome passado como parâmetro, 0 caso contrário.
 */
int VerificaNomeVendedor(tVendedor* vendedor, char* nome);

/**
 * @brief Contabiliza uma venda para um vendedor (soma o valor ao total vendido).
 *
 * @param vendedor Ponteiro para o vendedor.
 * @param valor Valor da venda a ser contabilizada.
 */
void ContabilizaVenda(tVendedor* vendedor, float valor);

/**
 * @brief Obtém o salário de um vendedor.
 *
 * @param vendedor Ponteiro para o vendedor.
 * @return float O salário do vendedor.
 */
float ObtemSalarioVendedor(tVendedor* vendedor);

/**
 * @brief Obtém o valor da comissão de um vendedor.
 *
 * @param vendedor Ponteiro para o vendedor.
 * @return float O valor da comissão do vendedor.
 */
float ObtemComissaoVendedor(tVendedor* vendedor);

/**
 * @brief Obtém o total vendido por um vendedor.
 *
 * @param vendedor Ponteiro para o vendedor.
 * @return float O total vendido pelo vendedor.
 */
float ObtemTotalVendidoVendedor(tVendedor* vendedor);

/**
 * @brief Obtém o total recebido por um vendedor.
 *
 * @param vendedor Ponteiro para o vendedor.
 * @return float O total recebido pelo vendedor.
 */
float ObtemTotalRecebidoVendedor(tVendedor* vendedor);

/**
 * @brief Imprime o relatório de um vendedor, em duas linhas (valores com 2 casas decimais):
 * "\t<nome>: Total vendido: R$ <total vendido>\n" e
 * "\t\tTotal recebido: R$ <total recebido>\n".
 *
 * @param vendedor Ponteiro para o vendedor a ser impresso.
 */
void ImprimeRelatorioVendedor(tVendedor* vendedor);

#endif
