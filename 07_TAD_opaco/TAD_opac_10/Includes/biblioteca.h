#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"

/**
 * @brief Tipo opaco que representa uma biblioteca que possui pelo menos os seguintes atributos:
 * a lista de livros cadastrados. Não há limite para a quantidade de livros
 * (a lista deve crescer conforme a necessidade).
 */
typedef struct Biblioteca tBiblioteca;


/**
 * @brief Cria uma biblioteca vazia (sem livros).
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tBiblioteca* Ponteiro para a biblioteca criada.
 */
tBiblioteca* InicializarBiblioteca();

/**
 * @brief Libera a memória de uma biblioteca, inclusive a dos seus livros (utilizando sua função apropriada).
 *
 * @param biblioteca Ponteiro para a biblioteca a ser apagada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca);

/**
 * @brief Adiciona um livro ao final da lista de livros da biblioteca e imprime
 * "Livro adicionado com sucesso!\n".
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivro* livro);

/**
 * @brief Remove um livro da biblioteca pelo título (o primeiro com esse título, na ordem de
 * cadastro), mantendo a ordem dos demais livros.
 * Se o título for encontrado, libera o livro (utilizando sua função apropriada) e imprime
 * "Livro removido com sucesso!\n". Senão, imprime "Livro nao encontrado na biblioteca.\n".
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo);

/**
 * @brief Lista todos os livros da biblioteca: primeiro a linha "Lista de Livros na Biblioteca:\n"
 * e, em seguida, os livros (utilizando sua função apropriada) na ordem de cadastro.
 * Se não houver livros na biblioteca, imprime apenas "A biblioteca esta vazia!\n".
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca);

#endif
