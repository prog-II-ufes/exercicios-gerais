#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"


#define MAX_LIVROS 10

// Estrutura que representa uma biblioteca de livros
typedef struct {
    tLivros* livros[MAX_LIVROS]; // Array de livros (Neste exemplo, o máximo suportado será 10)
    int tamanho; // Número atual de livros na biblioteca
} tBiblioteca;

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca();

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca);

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro);

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo);

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo);

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca);



#endif
