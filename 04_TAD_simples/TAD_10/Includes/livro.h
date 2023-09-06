#ifndef LIVRO_H
#define LIVRO_H

// Estrutura que representa um livro
typedef struct {
    char titulo[100]; // Título do livro
    char autor[50];   // Autor do livro
    int anoPublicacao; // Ano de publicação do livro
} tLivros;

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro();

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro);

#endif
