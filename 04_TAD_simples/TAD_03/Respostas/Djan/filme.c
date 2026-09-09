#include <stdio.h>
#include <string.h>
#define MAX_CARACTERES 20 

typedef struct Filme {
    int codigo; 
    char nome[MAX_CARACTERES]; 
    int valor; 
    int qtdEstoque; 
    int qtdAlugada; 
} tFilme;

/**
 * @brief Cria um novo filme.
 * @param nome Nome do filme.
 * @param codigo Código do filme.
 * @param valor Valor do filme.
 * @param quantidade Quantidade em estoque do filme.
 * @return Filme criado.
 */
tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme f;

    strcpy(f.nome, nome);
    f.codigo = codigo;
    f.valor = valor;
    f.qtdEstoque = quantidade;

    return f;
}

/**
 * @brief Lê um filme.
 * @param codigo Código do filme.
 * @return Filme lido.
*/
tFilme leFilme(int codigo){
    tFilme filme;

    scanf("%d",&filme.codigo);

    filme.qtdAlugada = 0;

    return filme;
}

/**
 * @brief Obtém o código de um filme.
 * @param filme Filme a ser consultado.
 * @return Código do filme.
 */
int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

/**
 * @brief Imprime o nome de um filme.
 * @param filme Filme a ser impresso.
 */
void imprimirNomeFilme (tFilme filme){
    printf("%s\n",filme.nome);
}

/**
 * @brief Obtém o valor de um filme.
 * @param filme Filme a ser consultado.
 * @return Valor do filme.
 */
int obterValorFilme (tFilme filme){
    return filme.valor;
}

/**
 * @brief Obtém a quantidade em estoque de um filme.
 * @param filme Filme a ser consultado.
 * @return Quantidade em estoque do filme.
 */
int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

/**
 * @brief Obtém a quantidade alugada de um filme.
 * @param filme Filme a ser consultado.
 * @return Quantidade alugada do filme.
 */
int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada; 
}

/**
 * @brief Verifica se um filme possui um determinado código.
 * @param filme Filme a ser consultado.
 * @param codigo Código a ser verificado.
 * @return 1 se o filme possui o código, 0 caso contrário.
 */
int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(filme.codigo == codigo){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief Aluga um filme.
 * @param filme Filme a ser alugado.
 * @return Filme com a quantidade alugada atualizada.
 */
tFilme alugarFilme (tFilme filme){
    filme.qtdAlugada = filme.qtdAlugada + 1;
    return filme;
}

/**
 * @brief Devolve um filme.
 * @param filme Filme a ser devolvido.
 * @return Filme com a quantidade alugada atualizada.
 */
tFilme devolverFilme (tFilme filme){ 
    filme.qtdAlugada = filme.qtdAlugada - 1;
    return filme;
}

/**
 * @brief Compara os nomes de dois filmes.
 * @param filme1 Primeiro filme a ser comparado.
 * @param filme2 Segundo filme a ser comparado.
 * @return 0 se os nomes são iguais, um valor negativo se o nome do primeiro filme é menor que o do segundo, um valor positivo caso contrário.
 */
int compararNomesFilmes (tFilme filme1, tFilme filme2){
    if(strcmp(filme1.nome,filme2.nome) == 0){
        return 0; //valor negativo
    }else{
        return 1;//valor positivo
    }
}