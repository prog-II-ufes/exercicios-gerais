#ifndef LIVRO_H
#define LIVRO_H

#define MAX_TITULO 100 /**< Tamanho do vetor para ler o título: até 99 caracteres (+1 para o '\0'), uma única palavra. */
#define MAX_AUTOR 50   /**< Tamanho do vetor para ler o autor: até 49 caracteres (+1 para o '\0'), uma única palavra. */

/**
 * @brief Tipo opaco que representa um livro que possui pelo menos os seguintes atributos:
 * título, autor e ano de publicação.
 */
typedef struct Livro tLivro;


/**
 * @brief Cria um livro "vazio".
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tLivro* Ponteiro para o livro criado.
 */
tLivro* CriaLivro();

/**
 * @brief Lê os dados de um livro da entrada padrão: o título, o autor e o ano de publicação,
 * separados por espaço ou quebra de linha. O título e o autor são uma única palavra cada.
 *
 * @param livro Ponteiro para o livro que terá seus dados preenchidos.
 */
void LerLivro(tLivro* livro);

/**
 * @brief Imprime os dados do livro, um por linha, seguidos de uma linha em branco:
 * "Titulo: <titulo>\n", "Autor: <autor>\n", "Ano de Publicacao: <ano>\n" e "\n".
 *
 * @param livro Ponteiro para o livro a ser impresso.
 */
void ImprimeLivro(tLivro* livro);

/**
 * @brief Verifica se o livro tem o título informado.
 *
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título procurado.
 * @return int 1 se o título do livro for igual ao título informado, 0 caso contrário.
 */
int EhMesmoTituloLivro(tLivro* livro, char* titulo);

/**
 * @brief Libera a memória de um livro.
 *
 * @param livro Ponteiro para o livro a ser apagado.
 */
void ApagaLivro(tLivro* livro);

#endif
