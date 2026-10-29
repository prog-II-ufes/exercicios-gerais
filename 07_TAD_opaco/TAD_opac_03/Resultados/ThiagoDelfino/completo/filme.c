#include<stdio.h>
#include<stdlib.h>
#include"filme.h"
#include<string.h>

struct Filme{
    int cod;
    char *nome;
    int valor;
    int qntdEstoque;
    int qntdAlugada;
};
/**
 * @brief Cria um novo filme e define a quantidade alugada como 0.
 * 
 * @return Ponteiro para o filme criado ou encerra caso não seja possível alocar memória.
 */
tFilme* CriarFilme(){
    tFilme *f=(tFilme*) calloc(1,sizeof(tFilme));
    if(f==NULL)
        exit(1);
    f->nome=(char*) calloc(MAX_CARACTERES,sizeof(char));
    return f;
}

/**
 * @brief Lê um filme do arquivo de entrada e define o código do filme.
 * 
 * @param filme Ponteiro para o filme a ser lido.
*/
void LeFilme(tFilme *filme, int codigo){
    //filme=CriarFilme();
    filme->cod=codigo;
    scanf("%[^,],%d,%d",filme->nome,filme->valor,filme->qntdEstoque);
}

/**
 * @brief Libera a memória alocada para o filme.
 * 
 * @param filme Ponteiro para o filme a ser destruído.
*/
void DestruirFilme (tFilme* filme){
    if(filme!=NULL){
        free(filme->nome);
        free(filme);
    }
}

/**
 * @brief Retorna o código do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Código do filme.
*/
int ObterCodigoFilme (tFilme* filme){
    return filme->cod;
}

/**
 * @brief Imprime o nome do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void ImprimirNomeFilme (tFilme* filme){
    printf("%s",filme->nome);
}

/**
 * @brief Retorna o valor do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Valor do filme.
*/
int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

/**
 * @brief Retorna a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Quantidade em estoque do filme.
*/
int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qntdEstoque;
}

/**
 * @brief Retorna a quantidade alugada do filme.
 * 
 * @param filme Ponteiro para o filme.
 * @return Quantidade alugada do filme.
*/
int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qntdAlugada;
}

/**
 * @brief Verifica se o filme possui o código passado como parâmetro.
 * 
 * @param filme Ponteiro para o filme.
 * @param codigo Código a ser comparado.
 * @return 1 se o filme possui o código passado como parâmetro, 0 caso contrário.
*/
int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    if(filme->cod==codigo)
        return 1;
    return 0;
}

/**
 * @brief Incrementa a quantidade alugada e decrementa a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void AlugarFilme (tFilme* filme){
    filme->qntdAlugada++;
    filme->qntdEstoque--;
}

/**
 * @brief Decrementa a quantidade alugada e incrementa a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void DevolverFilme (tFilme* filme){
    filme->qntdAlugada--;
    filme->qntdEstoque++;
}

/**
 * @brief Compara dois filmes pelo nome.
 * 
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return 1 se o nome do primeiro filme for maior que o nome do segundo filme, -1 se o nome do primeiro filme for menor que o nome do segundo filme, 0 se os nomes forem iguais.
*/
int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    int tamF1=0, tamF2=0;
    while(filme1->nome[tamF1]!='\0'){
        tamF1++;
    }
    while(filme2->nome[tamF2]!='\0'){
        tamF2++;
    }
    if(tamF1>tamF2)
        return 1;
    if(tamF1<tamF2)
        return -1;
    return 0;
}