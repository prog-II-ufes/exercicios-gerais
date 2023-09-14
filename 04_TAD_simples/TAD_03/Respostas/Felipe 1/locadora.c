#include "locadora.h"
#include <stdio.h>
#include <string.h>

tLocadora criarLocadora () {
    tLocadora locadora = {0};

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo) {

    for (int i = 0; i < locadora.numFilmes; i++) {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
            return 1;
        }
    }

    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade) {
    locadora.filme[locadora.numFilmes] = criarFilme(nome, codigo, valor, quantidade);
    locadora.numFilmes++;

    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora) {
    tFilme filme = lerFilme();

    if (!verificarFilmeCadastrado(locadora, filme.codigo)) {
        locadora = cadastrarFilmeLocadora(locadora, filme.nome, filme.codigo, filme.valor, filme.qtdEstoque);
    }

    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

    for (int i = 0; i < quantidadeCodigos; i++) {
        int codigo = codigos[i];

        for (int j = 0; j < locadora.numFilmes; j++) {
            tFilme filme = locadora.filme[j];

            if (ehMesmoCodigoFilme(filme, codigo)) {
                locadora.filme[j] = alugarFilme(filme);
                locadora.lucro += obterValorFilme(filme);
                break;
            }
        }
    }

    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora) {
    int quantidadeCodigos = 0;
    int codigos[MAX_FILMES];

    while (scanf("%d\n", &codigos[quantidadeCodigos])) {
        quantidadeCodigos++;
    }

    locadora = alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);

    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

    for (int i = 0; i < quantidadeCodigos; i++) {
        int codigo = codigos[i];

        for (int j = 0; j < locadora.numFilmes; j++) {
            tFilme filme = locadora.filme[j];

            if (ehMesmoCodigoFilme(filme, codigo)) {
                locadora.filme[j] = devolverFilme(filme);
                break;
            }
        }
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora) {
    int quantidadeCodigos = 0;
    int codigos[MAX_FILMES];
    
    while (scanf("%d\n", &codigos[quantidadeCodigos])) {
        quantidadeCodigos++;
    }

    locadora = devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);

    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora) {

    for (int i = 0; i < locadora.numFilmes - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < locadora.numFilmes; j++) {
            if (strcmp(locadora.filme[i].nome, locadora.filme[j].nome) > 0) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            tFilme aux = locadora.filme[i];
            locadora.filme[i] = locadora.filme[min_idx];
            locadora.filme[min_idx] = aux;
        }
    }

    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora) {
    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora.numFilmes; i++) {
        tFilme filme = locadora.filme[i];

        printf("%d - %s Fitas em estoque: %d\n", filme.codigo, filme.nome, filme.qtdEstoque);
    }
}

void consultarLucroLocadora (tLocadora locadora) {
    printf("Lucro total R$%d\n", locadora.lucro);
}