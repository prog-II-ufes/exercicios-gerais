#ifndef _USUARIO_H_
#define _USUARIO_H_

#define MAX_NOME 50 /**< Tamanho do vetor do nome: até 49 caracteres (+1 para o '\0'), uma única palavra. */
#define MAX_CPF 15  /**< Tamanho do vetor do CPF: até 14 caracteres (+1 para o '\0'), sem espaços. */

/**
 * @brief Tipo opaco que representa um usuário do banco que possui pelo menos os seguintes atributos:
 * nome e CPF.
 */
typedef struct Usuario tUsuario;

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario();

/**
 * @brief Libera a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user);

/**
 * @brief Lê os dados de um usuário da entrada padrão: o nome e o CPF, separados por espaço
 * (cada um é uma única palavra).
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user);

/**
 * @brief Imprime os dados de um usuário: "Nome: <nome>\n", "CPF: <cpf>\n" e uma linha em branco.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user);

#endif