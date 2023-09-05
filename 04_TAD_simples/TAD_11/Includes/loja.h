#ifndef _LOJA_H_
#define _LOJA_H_

#include "vendedor.h"

#define MAX_VENDEDORES 10 /**< Número máximo de vendedores que uma loja pode ter */

typedef struct Loja {
    int id; /**< ID da loja */
    int total_vendedores; /**< Número total de vendedores da loja */
    float aluguel; /**< Valor do aluguel da loja */
    float lucro; /**< Lucro da loja */
    tVendedor vendedores[MAX_VENDEDORES]; /**< Vetor de vendedores da loja */
} tLoja;

/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja abrir_loja(int id, float aluguel);

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int verifica_id_loja(tLoja loja, int id);

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
tLoja contratar_vendedor(tLoja loja, tVendedor vendedor);

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
tLoja registrar_venda(tLoja loja, char nome[50], float valor);

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
tLoja calcular_lucro(tLoja loja);

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void imprimir_relatorio_loja(tLoja loja);

#endif