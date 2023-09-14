#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main(int argc, char const *argv[])
{
    char operacao[20];
    tLocadora locadora = criarLocadora();

    while (1) {
        scanf("%s", operacao);

        if (strcmp(operacao, "Cadastrar") == 0) {
            while (1) {
                scanf("#\n");
                locadora = lerCadastroLocadora(locadora);
            }
        } else if (strcmp(operacao, "Alugar") == 0) {
            locadora = lerAluguelLocadora(locadora);
        } else if (strcmp(operacao, "Devolver") == 0) {
            locadora = lerDevolucaoLocadora(locadora);
        } else if (strcmp(operacao, "Estoque") == 0) {
           consultarEstoqueLocadora(locadora);
           printf("\n");
           break;
        }

        printf("\n");
    }

    consultarLucroLocadora(locadora);
    
    return 0;
}
