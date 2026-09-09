#include <stdio.h>
#include <string.h>
#include "usuario.h"
//pronto
/**
 * @struct tUsuario
 * @brief Estrutura que representa um usuário do sistema bancário.
 */

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario u;
    strcpy(u.nome,nome);
    strcpy(u.cpf,cpf);
    return u;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}
