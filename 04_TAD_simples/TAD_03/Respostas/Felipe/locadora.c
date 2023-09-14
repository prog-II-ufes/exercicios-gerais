#include "locadora.h"
#include <stdio.h>
#include <string.h>

tLocadora criarLocadora () {
    tLocadora locadora = {0};

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    int i;

    for (i = 0; i < locadora.numFilmes; i++) {
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
    int i, j;

    for (i = 0; i < quantidadeCodigos; i++) {
        for (j = 0; j < locadora.numFilmes; j++) {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                locadora.lucro += obterValorFilme(locadora.filme[j]);
            }
        }
    }

    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora) {
    int i, quantidadeCodigos;
    int codigos[MAX_FILMES], codigo;

    while (1)
    {
        scanf("%d\n", &codigos[i]);
        i++;
    }
    

    locadora = alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);

    return locadora;
}