#ifndef _FILME_H
#define _FILME_H

#define MAX_CARACTERES 20 /**< Tamanho do vetor do nome do filme: até 19 caracteres (+1 para o '\0') */

/**
 * @brief Tipo opaco que representa um filme que possui pelo menos os seguintes atributos:
 * código, nome, valor, quantidade de fitas em estoque e quantidade de fitas alugadas.
 */
typedef struct Filme tFilme;

/**
 * @brief Lê da entrada padrão a linha de cadastro de um filme, no formato "<código>,<nome>,<valor>,<quantidade de fitas>",
 * e cria um filme com esses dados, ainda sem fitas alugadas. Todos os campos da estrutura devem ser inicializados aqui.
 * Se a próxima entrada for o '#' que encerra o bloco, consome o '#' e retorna NULL.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tFilme* Ponteiro para o filme criado, ou NULL se o bloco terminou.
 */
tFilme* LeFilme();

/**
 * @brief Lê da entrada padrão o código de um filme (um por linha).
 * Se a próxima entrada for o '#' que encerra o bloco, consome o '#' e retorna -1.
 *
 * @return int Código lido, ou -1 se o bloco terminou.
 */
int LeCodigoFilme();

/**
 * @brief Libera a memória de um filme.
 *
 * @param filme Ponteiro para o filme a ser destruído.
 */
void DestroiFilme(tFilme* filme);

/**
 * @brief Obtém o código de um filme.
 *
 * @param filme Ponteiro para o filme.
 * @return int Código do filme.
 */
int ObtemCodigoFilme(tFilme* filme);

/**
 * @brief Imprime o nome de um filme, sem quebra de linha.
 *
 * @param filme Ponteiro para o filme.
 */
void ImprimeNomeFilme(tFilme* filme);

/**
 * @brief Obtém o valor de um filme.
 *
 * @param filme Ponteiro para o filme.
 * @return int Valor do filme.
 */
int ObtemValorFilme(tFilme* filme);

/**
 * @brief Obtém a quantidade de fitas de um filme em estoque.
 *
 * @param filme Ponteiro para o filme.
 * @return int Quantidade de fitas em estoque.
 */
int ObtemQtdEstoqueFilme(tFilme* filme);

/**
 * @brief Obtém a quantidade de fitas de um filme que estão alugadas.
 *
 * @param filme Ponteiro para o filme.
 * @return int Quantidade de fitas alugadas.
 */
int ObtemQtdAlugadaFilme(tFilme* filme);

/**
 * @brief Aluga uma fita do filme: uma fita sai do estoque e passa a estar alugada.
 *
 * @param filme Ponteiro para o filme.
 */
void AlugaFilme(tFilme* filme);

/**
 * @brief Devolve uma fita do filme: uma fita alugada volta para o estoque.
 *
 * @param filme Ponteiro para o filme.
 */
void DevolveFilme(tFilme* filme);

/**
 * @brief Compara os nomes de dois filmes em ordem alfabética.
 *
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return int Valor negativo se o nome de filme1 vem antes, positivo se vem depois e 0 se os nomes são iguais.
 */
int ComparaNomesFilmes(tFilme* filme1, tFilme* filme2);

#endif
