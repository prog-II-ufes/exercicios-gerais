#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main(int argc, char const *argv[])
{
    char operacao[20];
    tLocadora locadora = criarLocadora();

    while (1) {
        scanf("%s\n", operacao);

        if (strcmp(operacao, "Cadastrar")) {
            while (!scanf("#\n")) {
                locadora = lerCadastroLocadora(locadora);
            }
        } else if (strcmp(operacao, "Alugar")) {
            locadora = lerAluguelLocadora(locadora);
        } else if (strcmp(operacao, "Devolver")) {
            locadora = lerDevolucaoLocadora(locadora);
        } else if (strcmp(operacao, "Estoque")) {
           consultarEstoqueLocadora(locadora);
           printf("\n");
           break;
        }

        printf("\n");
    }

    consultarLucroLocadora(locadora);
    
    return 0;
}
