#include <stdio.h>
#include "conta.h"
#include "usuario.h"

int main(int argc, char const *argv[])
{
    int max_contas;

    scanf("%d", &max_contas);

    tConta contas[max_contas];

    while (1) {
        int options;

        scanf("%d", &options);

        switch (options) {
            int id;
            float valor;
            char nome[50], cpf[12];

            case 0:
                return 0;
            case 1:
                scanf("%d %f", &id, &valor);
                contas[id - 1] = saque(contas[id - 1], valor);

                break;
            case 2:
                scanf("%d %f", &id, &valor);
                contas[id - 1] = deposito(contas[id - 1], valor);

                break;
            case 3:
                scanf("%s %s %d", nome, cpf, &id);

                contas[id - 1] = criar_conta(id, criar_usuario(nome, cpf));

                break;
            case 4:
                printf("===| Imprimindo Relatorio |===\n");

                for (int i = 0; i < max_contas; i++) {
                    imprime_conta(contas[i]);
                    printf("\n");
                }

                break;
            default:
                break;
        }
    }
    

    return 0;
}
