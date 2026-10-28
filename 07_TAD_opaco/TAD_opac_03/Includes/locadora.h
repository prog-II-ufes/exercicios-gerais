#ifndef _LOCADORA_H
#define _LOCADORA_H


/**
 * @brief Tipo opaco que representa uma locadora que possui pelo menos os seguintes atributos:
 * a lista de filmes cadastrados e o lucro. Não há limite para a quantidade de filmes
 * (a lista deve crescer conforme a necessidade).
 */
typedef struct Locadora tLocadora;

/**
 * @brief Cria uma locadora, ainda sem filmes e sem lucro.
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tLocadora* Ponteiro para a locadora criada.
 */
tLocadora* CriaLocadora();

/**
 * @brief Libera a memória de uma locadora, inclusive a dos seus filmes.
 *
 * @param locadora Ponteiro para a locadora a ser destruída.
 */
void DestroiLocadora(tLocadora* locadora);

/**
 * @brief Cadastra os filmes de um bloco de cadastro, lendo-os com LeFilme até que ela retorne NULL (fim do bloco).
 * Cada filme é adicionado ao final da lista de filmes, imprimindo "Filme cadastrado - <código> - <nome>\n".
 * Se já houver um filme com o mesmo código, o filme não é cadastrado e imprime "Filme ja cadastrado no estoque\n".
 *
 * @param locadora Ponteiro para a locadora.
 */
void CadastraFilmesLocadora(tLocadora* locadora);

/**
 * @brief Aluga uma fita de cada filme de um bloco de aluguel, lendo os códigos com LeCodigoFilme
 * até que ela retorne -1 (fim do bloco). Ao final do bloco, se pelo menos uma fita foi alugada, imprime
 * "Total de filmes alugados: <quantidade> com custo de R$<soma dos valores>\n".
 * 
 * Se o filme não estiver cadastrado, imprime "Filme <código> nao cadastrado\n";
 * Se não houver fitas em estoque, imprime "Filme <código> - <nome> nao disponivel no estoque. Volte mais tarde.\n".
 *
 * @param locadora Ponteiro para a locadora.
 */
void AlugaFilmesLocadora(tLocadora* locadora);

/**
 * @brief Devolve uma fita de cada filme de um bloco de devolução, lendo os códigos com LeCodigoFilme
 * até que ela retorne -1 (fim do bloco).
 * 
 * Se o filme não estiver cadastrado, imprime "Filme <código> nao cadastrado\n";
 * Se nenhuma fita do filme estiver alugada, imprime "Nao e possivel devolver o filme <código> - <nome>\n";
 * Caso contrário, imprime "Filme <código> - <nome> Devolvido!\n" e o valor do filme é somado ao lucro.
 *
 * @param locadora Ponteiro para a locadora.
 */
void DevolveFilmesLocadora(tLocadora* locadora);

/**
 * @brief Imprime "~ESTOQUE~\n" e, em seguida, todos os filmes cadastrados (inclusive os sem fitas em estoque)
 * em ordem alfabética do nome, no formato "<código> - <nome> - Fitas em estoque: <quantidade>\n".
 *
 * @param locadora Ponteiro para a locadora.
 */
void ImprimeEstoqueLocadora(tLocadora* locadora);

/**
 * @brief Imprime o lucro da locadora: "Lucro total R$<lucro>\n". Se o lucro for zero, não imprime nada.
 *
 * @param locadora Ponteiro para a locadora.
 */
void ImprimeLucroLocadora(tLocadora* locadora);

#endif
