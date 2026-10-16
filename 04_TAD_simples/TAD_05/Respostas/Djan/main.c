#include <stdio.h>
#include "usuario.h"
#include "conta.h"

#define MAX_CONTAS 100
//PROnto
int main(){

    int maxContas;
    int qtdContas = 0;
    int operacao;
    int i;

    tConta contas[MAX_CONTAS];

    scanf("%d", &maxContas);

    scanf("%d", &operacao);

    while(operacao != 0){

        if(operacao == 3){

            char nome[20];
            char cpf[15];
            int numero;
            tUsuario usuario;

            scanf("%s %s %d", nome, cpf, &numero);

            /* Verifica se o CPF já está cadastrado */
            int usuarioCadastrado = 0;

            for(i = 0; i < qtdContas; i++){
                /*
                 * Comparamos o CPF diretamente porque
                 * o tUsuario possui esse campo.
                 */
                if(strcmp(contas[i].user.cpf, cpf) == 0){
                    usuarioCadastrado = 1;
                    break;
                }
            }

            if(!usuarioCadastrado && qtdContas < maxContas){

                usuario = CriaUsuario(nome, cpf);

                contas[qtdContas] = CriaConta(numero, usuario);

                qtdContas++;
            }

        }else if(operacao == 2){

            int numero;
            float valor;

            scanf("%d %f", &numero, &valor);

            for(i = 0; i < qtdContas; i++){

                if(VerificaConta(contas[i], numero)){
                    contas[i] = DepositoConta(contas[i], valor);
                    break;
                }
            }
        }else if(operacao == 1){

            int numero;
            float valor;

            scanf("%d %f", &numero, &valor);

            for(i = 0; i < qtdContas; i++){

                if(VerificaConta(contas[i], numero)){
                    contas[i] = SaqueConta(contas[i], valor);
                    break;
                }
            }
        }else if(operacao == 4){

            printf("===| Imprimindo Relatorio |===\n");

            for(i = 0; i < qtdContas; i++){
                ImprimeConta(contas[i]);
            }
        }

        scanf("%d", &operacao);
    }

    return 0;
}