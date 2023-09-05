#ifndef _VENDEDOR_H_
#define _VENDEDOR_H_


typedef struct Vendedor {
    char nome[50]; /**< Nome do vendedor */
    float valor_vendido; /**< Valor total vendido pelo vendedor */
    float salario; /**< Salário base do vendedor */
    float prct_comissao; /**< Porcentagem de comissão do vendedor */
} tVendedor;

/**
 * @brief Registra um novo vendedor.
 * 
 * @param nome Nome do vendedor.
 * @param salario Salário base do vendedor.
 * @param prct_comissao Porcentagem de comissão do vendedor.
 * @return tVendedor Retorna a estrutura do tipo tVendedor com os dados do vendedor registrado.
 */
tVendedor registrar_vendedor(char nome[50], float salario, float prct_comissao);

/**
 * @brief Verifica se o nome de um vendedor é igual a outro.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser verificado.
 * @param nome Nome do vendedor a ser comparado.
 * @return int Retorna 1 se o nome do vendedor é igual ao nome passado como parâmetro, ou 0 caso contrário.
 */
int verifica_nome_vendedor(tVendedor vendedor, char nome[50]);

/**
 * @brief Contabiliza uma venda para um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @param valor Valor da venda a ser contabilizada.
 * @return tVendedor Retorna a estrutura do tipo tVendedor atualizada com o valor da venda contabilizada.
 */
tVendedor contabilizar_venda(tVendedor vendedor, float valor);

/**
 * @brief Obtém o salário de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o salário do vendedor.
 */
float obter_salario(tVendedor vendedor);

/**
 * @brief Obtém a comissão de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna a comissão do vendedor.
 */
float obter_comissao(tVendedor vendedor);

/**
 * @brief Obtém o total vendido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total vendido pelo vendedor.
 */
float obter_total_vendido(tVendedor vendedor);

/**
 * @brief Obtém o total recebido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total recebido pelo vendedor (salário + comissão).
 */
float obter_total_recebido(tVendedor vendedor);

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void imprimir_relatorio_vendedor(tVendedor vendedor);

#endif