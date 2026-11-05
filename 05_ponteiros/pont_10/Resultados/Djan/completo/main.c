#include <stdio.h>
#include "pessoa.h"

int main() {
    int N, i;

    scanf("%d", &N);

    tPessoa pessoas[N];

    for (i = 0; i < N; i++) {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas, N);

    for (i = 0; i < N; i++) {
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}