#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

typedef struct Locadora tLocadora;

/**
 * @brief Cria uma nova locadora.
 * @return Ponteiro para a nova locadora criada se a criação foi bem sucedida, caso contrário o programa será encerrado.
 */
tLocadora* criarLocadora ();

/**
 * @brief Destrói uma locadora.
 * @param locadora Ponteiro para a locadora a ser destruída.
 */
void destruirLocadora (tLocadora* locadora);

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Ponteiro para a locadora.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora* locadora, int codigo);

/**
 * @brief Cadastra um novo filme na locadora.
 * @param locadora Ponteiro para a locadora.
 * @param nome Nome do filme.
 * @param codigo Código do filme.
 * @param valor Valor do filme.
 * @param quantidade Quantidade em estoque do filme.
 */
void cadastrarFilmeLocadora (tLocadora* locadora, char* nome, int codigo, int valor, int quantidade);

/**
 * @brief Lê o cadastro de um novo filme na locadora a partir do teclado.
 * @param locadora Ponteiro para a locadora.
 */
void lerCadastroLocadora (tLocadora* locadora);

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Ponteiro para a locadora.
 * @param codigos Vetor com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de filmes a serem alugados.
 */
void alugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê o aluguel de um conjunto de filmes da locadora a partir do teclado.
 * @param locadora Ponteiro para a locadora.
 */
void lerAluguelLocadora (tLocadora* locadora);

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Ponteiro para a locadora.
 * @param codigos Vetor com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de filmes a serem devolvidos.
 */
void devolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê a devolução de um conjunto de filmes alugados da locadora a partir do teclado.
 * @param locadora Ponteiro para a locadora.
 */
void lerDevolucaoLocadora (tLocadora* locadora);

/**
 * @brief Ordena os filmes cadastrados na locadora por nome.
 * @param locadora Ponteiro para a locadora.
 */
void ordenarFilmesLocadora (tLocadora* locadora);

/**
 * @brief Consulta o estoque de filmes da locadora.
 * @param locadora Ponteiro para a locadora.
 */
void consultarEstoqueLocadora (tLocadora* locadora);

/**
 * @brief Consulta o lucro total da locadora.
 * @param locadora Ponteiro para a locadora.
 */
void consultarLucroLocadora (tLocadora* locadora);

#endif