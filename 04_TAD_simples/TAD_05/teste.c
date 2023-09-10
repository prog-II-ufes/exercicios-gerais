#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "usuario.h"
#include "conta.h"

void testUsuario() {
    char nome1[20] = "Joao";
    char cpf1[15] = "123.456.789-00";
    tUsuario user1 = criar_usuario(nome1, cpf1);

    assert(strcmp(user1.nome, nome1) == 0);
    assert(strcmp(user1.cpf, cpf1) == 0);
    
    char nome2[20] = "Maria";
    char cpf2[15] = "987.654.321-00";
    tUsuario user2 = criar_usuario(nome2, cpf2);

    assert(strcmp(user2.nome, nome2) == 0);
    assert(strcmp(user2.cpf, cpf2) == 0);
    
    printf("Teste de impressao de usuario:\n");
    imprime_usuario(user1);
    imprime_usuario(user2);
}

void testConta() {
    char nome[20] = "Joao";
    char cpf[15] = "123.456.789-00";

    tUsuario user = criar_usuario(nome, cpf);
    tConta conta = criar_conta(123, user);

    assert(conta.numero == 123);
    assert(conta.saldo == 0);
    assert(strcmp(conta.user.nome, nome) == 0);
    assert(strcmp(conta.user.cpf, cpf) == 0);

    assert(comparar_numero_conta(conta, 123) == 1);
    assert(comparar_numero_conta(conta, 456) == 0);
    
    conta = deposito(conta, 100);
    assert(conta.saldo == 100);
    
    conta = saque(conta, 50);
    assert(conta.saldo == 50);
    
    printf("Teste de impressao de conta:\n");
    imprime_conta(conta);
}

int main(int argc, char const *argv[])
{
    testUsuario();
    printf("\n");
    
    testConta();
    printf("\n");

    return 0;
}
