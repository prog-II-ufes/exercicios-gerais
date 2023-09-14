#ifndef _LOCADORA_H
#define _LOCADORA_H

#include "filme.h"

#define MAX_FILMES 100


typedef struct Locadora {
    tFilme filme[MAX_FILMES]; 
    int numFilmes; 
    int lucro; 
} tLocadora;

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora ();

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo);

/**
 * @brief Cadastra um novo filme na locadora.
 * @param locadora Locadora a ser atualizada.
 * @param nome Nome do filme.
 * @param codigo Código do filme.
 * @param valor Valor do filme.
 * @param quantidade Quantidade em estoque do filme.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade);

/**
 * @brief Lê o cadastro de um filme a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora);

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora);

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora);

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora);

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora);

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora);

#endif