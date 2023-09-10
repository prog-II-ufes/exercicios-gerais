#ifndef _USUARIO_H_
#define _USUARIO_H_

/**
 * @struct tUsuario
 * @brief Estrutura que representa um usuário do sistema bancário.
 */
typedef struct Usuario {
    char nome[50]; /**< Nome do usuário. */
    char cpf[15]; /**< CPF do usuário. */
} tUsuario;

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario criar_usuario(char nome[20], char cpf[15]);

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void imprime_usuario(tUsuario user);

#endif