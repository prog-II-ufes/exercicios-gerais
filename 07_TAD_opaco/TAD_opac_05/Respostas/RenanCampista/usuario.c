#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

struct Usuario{
    char nome[50]; /**< Nome do usuário. */
    char cpf[15]; /**< CPF do usuário. */
};

tUsuario *CriaUsuario() {
    tUsuario *user = (tUsuario *) malloc(sizeof(tUsuario));
    if (user == NULL) {
        printf("Erro ao alocar usuario\n");
        exit(1);
    }
    return user;
}

void DestroiUsuario(tUsuario *user) {
    free(user);
}

void LeUsuario(tUsuario *user) {
    scanf("%s %s ", user->nome, user->cpf);
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n\n", user->cpf);
}
