#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int main() {
    tBanco *banco = CriaBanco();
    char opcao;

    while(1) {
        scanf("%c ", &opcao);
        
        if(opcao == 'A') {
            AbreContaBanco(banco);
        } else if (opcao == 'D') {
            DepositoContaBanco(banco);
        } else if (opcao == 'S') {
            SaqueContaBanco(banco);
        } else if (opcao == 'T') {
            TransferenciaContaBanco(banco);
        } else if (opcao == 'R') {
            ImprimeRelatorioBanco(banco);
        } else if (opcao == 'F') {
            DestroiBanco(banco);
            break;
        } else {
            printf("Opcao invalida\n");
        }
    }

    return 0;
}
