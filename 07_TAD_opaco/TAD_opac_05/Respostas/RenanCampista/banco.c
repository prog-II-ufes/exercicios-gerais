#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "conta.h"

struct Banco{
    tConta **contas;
    int qtdContas;
    int contasAlocadas;
};

tBanco *CriaBanco() {
    tBanco *banco = (tBanco *) malloc(sizeof(tBanco));
    if (banco == NULL) {
        printf("Erro ao alocar banco\n");
        exit(1);
    }

    banco->contasAlocadas = 5;
    banco->contas = (tConta **) malloc(sizeof(tConta *) * banco->contasAlocadas);
    banco->qtdContas = 0;

    return banco;
}

void DestroiBanco(tBanco *banco) {
    for (int i = 0; i < banco->qtdContas; i++) {
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

void AbreContaBanco(tBanco *banco) {
    if (banco->qtdContas == banco->contasAlocadas) {
        banco->contasAlocadas *= 2;
        banco->contas = (tConta **) realloc(banco->contas, sizeof(tConta *) * banco->contasAlocadas);
    }
    tConta *c = CriaConta();
    LeConta(c);
    banco->contas[banco->qtdContas] = c;
    banco->qtdContas++;
}

void SaqueContaBanco(tBanco *banco) {
    int numConta;
    float valor;
    scanf("%d %f ", &numConta, &valor);
    for (int i = 0; i < banco->qtdContas; i++) {
        if (VerificaConta(banco->contas[i], numConta)) {
            SaqueConta(banco->contas[i], valor);
        }
    }
}

void DepositoContaBanco(tBanco *banco) {
    int numConta;
    float valor;
    scanf("%d %f ", &numConta, &valor);
    for (int i = 0; i < banco->qtdContas; i++) {
        if (VerificaConta(banco->contas[i], numConta)) {
            DepositoConta(banco->contas[i], valor);
        }
    }
}

void TransferenciaContaBanco(tBanco *banco) {
    int numContaOrigem, numContaDestino;
    float valor;
    scanf("%d %d %f ", &numContaDestino, &numContaOrigem, &valor);
    tConta *contaOrigem = NULL;
    tConta *contaDestino = NULL;
    for (int i = 0; i < banco->qtdContas; i++) {
        if (VerificaConta(banco->contas[i], numContaOrigem)) {
            contaOrigem = banco->contas[i];
        }
        if (VerificaConta(banco->contas[i], numContaDestino)) {
            contaDestino = banco->contas[i];
        }
    }
    if (contaOrigem != NULL && contaDestino != NULL) {
        TransferenciaConta(contaDestino, contaOrigem, valor);
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContas; i++) {
        ImprimeConta(banco->contas[i]);
    }
}