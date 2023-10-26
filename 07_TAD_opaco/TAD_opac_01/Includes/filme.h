#ifndef _FILME_H
#define _FILME_H

#define MAX_CARACTERES 20

typedef struct Filme tFilme;

/**
 * @brief Cria um novo filme.
 * @param nome Nome do filme.
 * @param codigo Código do filme.
 * @param valor Valor do filme.
 * @param quantidade Quantidade em estoque do filme.
 * @return Ponteiro para o novo filme criado se a alocacao foi bem sucedida, caso contrario o programa sera encerrado.
 */
tFilme* criarFilme (char* nome, int codigo, int valor, int quantidade);

/**
 * @brief Destrói um filme.
 * @param filme Ponteiro para o filme a ser destruído.
 */
void destruirFilme (tFilme* filme);

/**
 * @brief Obtém o código de um filme.
 * @param filme Ponteiro para o filme.
 * @return Código do filme.
 */
int obterCodigoFilme (tFilme* filme);

/**
 * @brief Imprime o nome de um filme.
 * @param filme Ponteiro para o filme.
 */
void imprimirNomeFilme (tFilme* filme);

/**
 * @brief Obtém o valor de um filme.
 * @param filme Ponteiro para o filme.
 * @return Valor do filme.
 */
int obterValorFilme (tFilme* filme);

/**
 * @brief Obtém a quantidade em estoque de um filme.
 * @param filme Ponteiro para o filme.
 * @return Quantidade em estoque do filme.
 */
int obterQtdEstoqueFilme (tFilme* filme);

/**
 * @brief Obtém a quantidade alugada de um filme.
 * @param filme Ponteiro para o filme.
 * @return Quantidade alugada do filme.
 */
int obterQtdAlugadaFilme (tFilme* filme);

/**
 * @brief Verifica se um filme tem o mesmo código que outro.
 * @param filme Ponteiro para o filme.
 * @param codigo Código a ser comparado.
 * @return 1 se os códigos são iguais, 0 caso contrário.
 */
int ehMesmoCodigoFilme (tFilme* filme, int codigo);

/**
 * @brief Aluga um filme.
 * @param filme Ponteiro para o filme a ser alugado.
 */
void alugarFilme (tFilme* filme);

/**
 * @brief Devolve um filme.
 * @param filme Ponteiro para o filme a ser devolvido.
 */
void devolverFilme (tFilme* filme);

/**
 * @brief Compara os nomes de dois filmes.
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return 1 se os nomes são iguais, 0 caso contrário.
 */
int compararNomesFilmes (tFilme* filme1, tFilme* filme2);

#endif