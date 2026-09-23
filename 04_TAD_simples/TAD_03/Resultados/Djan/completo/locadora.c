#include <stdio.h>
#include "locadora.h"
#include "filme.h"

#define MAX_FILMES 100

/*typedef struct Locadora {
    tFilme filme[MAX_FILMES];
    int numFilmes;
    int lucro;
} tLocadora;
*/

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora(){
    tLocadora l;

    l.numFilmes = 0;
    l.lucro = 0;

    return l;
}


/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo){
    int i;

    for(i = 0; i < locadora.numFilmes; i++){
        if(ehMesmoCodigoFilme(locadora.filme[i], codigo)){
            return 1;
        }
    }

    return 0;
}


/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme){

    if(verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))){
        printf("Filme ja cadastrado no estoque\n");
        return locadora;
    }

    if(locadora.numFilmes < MAX_FILMES){
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;

        printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
        printf("\n");
    }

    return locadora;
}


/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora){
    char entrada[10];
    int codigo;

    scanf("%s", entrada);

    while(scanf("%s", entrada) == 1){
        if(entrada[0] == '#'){
            break;
        }

        sscanf(entrada, "%d", &codigo);

        locadora = cadastrarFilmeLocadora(
            locadora,
            leFilme(codigo)
        );
    }

    return locadora;
}


/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(
    tLocadora locadora,
    int* codigos,
    int quantidadeCodigos
){
    int i, j;
    int totalAlugados = 0;
    int custoTotal = 0;

    for(i = 0; i < quantidadeCodigos; i++){

        for(j = 0; j < locadora.numFilmes; j++){

            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                break;
            }
        }

        /* Filme não cadastrado */
        if(j == locadora.numFilmes){
            printf("Filme %d nao cadastrado\n", codigos[i]);
            continue;
        }

        /* Sem estoque */
        if(obterQtdEstoqueFilme(locadora.filme[j]) == 0){
            printf(
                "Filme %d - ",
                obterCodigoFilme(locadora.filme[j])
            );
            imprimirNomeFilme(locadora.filme[j]);
            printf(" nao disponivel no estoque. Volte mais tarde.\n");
            continue;
        }

        /* Aluguel realizado */
        locadora.filme[j] = alugarFilme(locadora.filme[j]);

        totalAlugados++;
        custoTotal += obterValorFilme(locadora.filme[j]);
    }

    printf(
        "Total de filmes alugados %d com custo de R$%d\n",
        totalAlugados,
        custoTotal
    );

    return locadora;
}


/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora){
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;
    char entrada[20];

    while(scanf("%s", entrada) == 1){

        if(entrada[0] == '#'){
            break;
        }

        sscanf(entrada, "%d", &codigos[quantidadeCodigos]);
        quantidadeCodigos++;
    }

    return alugarFilmesLocadora(
        locadora,
        codigos,
        quantidadeCodigos
    );
}


/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(
    tLocadora locadora,
    int* codigos,
    int quantidadeCodigos
){
    int i, j;

    for(i = 0; i < quantidadeCodigos; i++){

        for(j = 0; j < locadora.numFilmes; j++){

            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                break;
            }
        }

        /* Filme não cadastrado */
        if(j == locadora.numFilmes){
            printf("Filme %d nao cadastrado\n", codigos[i]);
            continue;
        }

        /* Não há filme alugado */
        if(obterQtdAlugadaFilme(locadora.filme[j]) == 0){
            printf(
                "Nao e possivel devolver o filme %d - ",
                obterCodigoFilme(locadora.filme[j])
            );
            imprimirNomeFilme(locadora.filme[j]);
            printf("\n");
            continue;
        }

        /* Estoque já está completo */
        if(obterQtdEstoqueFilme(locadora.filme[j]) >=
           obterQtdEstoqueFilme(locadora.filme[j]) +
           obterQtdAlugadaFilme(locadora.filme[j])){
            printf(
                "Nao e possivel devolver o filme %d - ",
                obterCodigoFilme(locadora.filme[j])
            );
            imprimirNomeFilme(locadora.filme[j]);
            printf("\n");
            continue;
        }

        locadora.filme[j] = devolverFilme(locadora.filme[j]);

        locadora.lucro += obterValorFilme(locadora.filme[j]);

        printf(
            "Filme %d - ",
            obterCodigoFilme(locadora.filme[j])
        );
        imprimirNomeFilme(locadora.filme[j]);
        printf(" Devolvido!\n");

        /*
         * Atualiza o estoque depois da devolução.
         */
        locadora.filme[j] = criarFilme(
            /* nome */
            "",
            /* código */
            obterCodigoFilme(locadora.filme[j]),
            /* valor */
            obterValorFilme(locadora.filme[j]),
            /* quantidade */
            obterQtdEstoqueFilme(locadora.filme[j]) + 1
        );
    }

    return locadora;
}


/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora){
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;
    char entrada[20];

    while(scanf("%s", entrada) == 1){

        if(entrada[0] == '#'){
            break;
        }

        sscanf(entrada, "%d", &codigos[quantidadeCodigos]);
        quantidadeCodigos++;
    }

    return devolverFilmesLocadora(
        locadora,
        codigos,
        quantidadeCodigos
    );
}


/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora){
    int i, j;
    tFilme aux;

    for(i = 0; i < locadora.numFilmes - 1; i++){
        for(j = 0; j < locadora.numFilmes - 1 - i; j++){

            if(compararNomesFilmes(
                locadora.filme[j],
                locadora.filme[j + 1]
            ) > 0){

                aux = locadora.filme[j];
                locadora.filme[j] = locadora.filme[j + 1];
                locadora.filme[j + 1] = aux;
            }
        }
    }

    return locadora;
}


/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora){
    int i;

    locadora = ordenarFilmesLocadora(locadora);

    printf("~ESTOQUE~\n");

    for(i = 0; i < locadora.numFilmes; i++){

        if(obterQtdEstoqueFilme(locadora.filme[i]) > 0){

            printf(
                "%d - ",
                obterCodigoFilme(locadora.filme[i])
            );

            imprimirNomeFilme(locadora.filme[i]);

            printf(
                " Fitas em estoque: %d\n",
                obterQtdEstoqueFilme(locadora.filme[i])
            );
        }
    }

    printf("\n");
}


/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora){
    printf("Lucro total R$%d\n", locadora.lucro);
}
