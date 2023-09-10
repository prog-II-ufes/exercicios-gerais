#include "usuario.h"
#include <stdio.h>
#include <string.h>

tUsuario criar_usuario(char nome[20], char cpf[15]) {
    tUsuario user;

    strcpy(user.nome, nome);
    strcpy(user.cpf, cpf);

    return user;
}

void imprime_usuario(tUsuario user) {
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}