#ifndef _CONTA_H_
#define _CONTA_H_

#include "usuario.h"

/**
 * @struct tConta
 * @brief Estrutura que representa uma conta bancária.
 */
typedef struct Conta {
    int numero; /**< Número da conta. */
    tUsuario user; /**< Usuário da conta. */
    float saldo; /**< Saldo da conta. */
} tConta;

/**
 * @brief Cria uma nova conta bancária.
 * @param numero Número da conta.
 * @param user Usuário da conta.
 * @return A nova conta criada.
 */
tConta criar_conta(int numero, tUsuario user);

/**
 * @brief Imprime os dados de uma conta bancária.
 * @param conta Conta bancária a ser impressa.
 */
void imprime_conta(tConta conta);

/**
 * @brief Compara o número de uma conta bancária com um número dado.
 * @param conta Conta bancária a ser comparada.
 * @param numero Número a ser comparado.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int comparar_numero_conta(tConta conta, int numero);

/**
 * @brief Realiza um saque em uma conta bancária.
 * @param conta Conta bancária a ser sacada.
 * @param valor Valor a ser sacado.
 * @return A conta com o novo saldo após o saque.
 */
tConta saque(tConta conta, float valor);

/**
 * @brief Realiza um depósito em uma conta bancária.
 * @param conta Conta bancária a ser depositada.
 * @param valor Valor a ser depositado.
 * @return A conta com o novo saldo após o depósito.
 */
tConta deposito(tConta conta, float valor);

#endif