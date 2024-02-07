#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"
#include "usuario.h"

struct Conta{
    int numero;
    float saldo;
    tUsuario *user;
};

tConta *CriaConta() {
    tConta *conta = (tConta *) malloc(sizeof(tConta));
    if (conta == NULL) {
        printf("Erro ao alocar conta\n");
        exit(1);
    }
    return conta;
}

void DestroiConta(tConta *conta) {
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta) {
    conta->user = CriaUsuario();
    LeUsuario(conta->user);
    scanf("%d ", &conta->numero);
    conta->saldo = 0;
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    return (conta->numero == numero);
}

void SaqueConta(tConta *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
    } else {
        printf("\nSaldo Insuficiente!\n");
    }
}

void DepositoConta(tConta *conta, float valor) {
    if (valor > 0) 
        conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if (valor <= origem->saldo) {
        origem->saldo -= valor;
        destino->saldo += valor;
    } else {
        printf("\nSaldo Insuficiente para realizar a transferência!\n");
    }
}
