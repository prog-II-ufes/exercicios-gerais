#ifndef _operacao
#define _operacao

#include "conta.h"

/**
 * @brief Tipo opaco que representa uma operação que possui pelo menos os seguintes atributos:
 * a conta em que foi realizada e o valor (positivo para crédito e negativo para débito).
 */
typedef struct Operacao tOperacao;

/**
 * @brief Cria uma operação com a conta e o valor informados. A operação apenas referencia a conta,
 * ou seja, não altera o saldo da conta.
 *
 * @param conta Ponteiro para a conta em que a operação foi realizada.
 * @param valor Valor da operação.
 * @return tOperacao* Ponteiro para a operação criada.
 */
tOperacao* CriaOperacao(tConta* conta, float valor);

/**
 * @brief Libera a memória de uma operação (mas não a da sua conta).
 *
 * @param op Ponteiro para a operação a ser destruída.
 */
void DestroiOperacao(tOperacao* op);

/**
 * @brief Obtém o valor de uma operação.
 *
 * @param op Ponteiro para a operação.
 * @return float Valor da operação.
 */
float ObtemValorOperacao(tOperacao* op);

/**
 * @brief Imprime uma operação: "Operacao na conta <id> com valor <valor>\n", com o valor com 2 casas decimais.
 * Ex.: "Operacao na conta 456 com valor -35431.00\n".
 *
 * @param op Ponteiro para a operação.
 */
void ImprimeOperacao(tOperacao* op);

#endif
