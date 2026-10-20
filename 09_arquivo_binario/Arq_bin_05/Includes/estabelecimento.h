#if !defined(_ESTABELECIMENTO_H_)
#define _ESTABELECIMENTO_H_
#include <stdio.h>
#include "produto.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
typedef struct Estabelecimento tEstabelecimento;

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento();

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento);

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto);

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento);

/**
 * @brief Função para imprimir os produtos que estão em falta (sem estoque) em um estabelecimento.
 * A saída começa com as linhas "Produtos em falta:" e "Codigo;Nome;Preco" (cada mensagem em uma linha), seguidas de um produto por linha
 * no formato Codigo;Nome;Preco. Se não houver produtos em falta, imprime "Nao ha produtos em falta!" após essas duas linhas.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento);

#endif // _ESTABELECIMENTO_H_