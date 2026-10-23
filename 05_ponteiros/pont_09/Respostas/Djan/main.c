#include <stdio.h>
#include "pessoa.h"

int main(){

    // 1. Declarar a quantidade de pessoas
    int N, i;
    
    // 2. Ler a quantidade
    scanf("%d", &N);

    // 3. Criar o vetor de pessoas
    tPessoa pessoas[N];

    // 4. Laço para inicializar e ler cada pessoa
    
    for(i = 0; i < N; i++){
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    // 5. Chamar AssociaFamiliasGruposPessoas
     AssociaFamiliasGruposPessoas(pessoas);

    // 6. Laço para imprimir cada pessoa
    for (i = 0; i < N; i++) {
        ImprimePessoa(&pessoas[i]);
    }


    return 0;
}