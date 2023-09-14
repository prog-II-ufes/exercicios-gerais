#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main(int argc, char const *argv[])
{
    char operacao[20];
    tLocadora locadora = criarLocadora();

    while (scanf("%s", operacao) != EOF) {

        if (strcmp(operacao, "Cadastrar") == 0) {
            while (!scanf("#%c", operacao)) {
                locadora = lerCadastroLocadora(locadora);
            }
        } else if (strcmp(operacao, "Alugar") == 0) {
            locadora = lerAluguelLocadora(locadora);
        } else if (strcmp(operacao, "Devolver") == 0) {
            locadora = lerDevolucaoLocadora(locadora);
        } else if (strcmp(operacao, "Estoque") == 0) {
           consultarEstoqueLocadora(locadora);
        }

        printf("\n");
    }

    consultarLucroLocadora(locadora);
    
    return 0;
}
