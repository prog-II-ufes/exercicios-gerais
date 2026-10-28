#ifndef _conta
#define _conta

/**
 * @brief Tipo opaco que representa uma conta que possui pelo menos os seguintes atributos:
 * id (número da conta) e saldo.
 */
typedef struct Conta tConta;

/**
 * @brief Cria uma conta com o id informado e saldo zero.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @param id Id da conta.
 * @return tConta* Ponteiro para a conta criada.
 */
tConta* CriaConta(int id);

/**
 * @brief Libera a memória de uma conta.
 *
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta* conta);

/**
 * @brief Soma um valor ao saldo da conta (o valor é negativo nas operações de débito).
 *
 * @param conta Ponteiro para a conta.
 * @param valor Valor a ser somado ao saldo.
 */
void AlteraSaldoConta(tConta* conta, float valor);

/**
 * @brief Verifica se uma conta possui o id informado.
 *
 * @param conta Ponteiro para a conta.
 * @param id Id a ser comparado.
 * @return int 1 se a conta possui o id informado, 0 caso contrário.
 */
int ConfereIdConta(tConta* conta, int id);

/**
 * @brief Obtém o id de uma conta.
 *
 * @param conta Ponteiro para a conta.
 * @return int Id da conta.
 */
int ObtemIdConta(tConta* conta);

/**
 * @brief Obtém o saldo de uma conta.
 *
 * @param conta Ponteiro para a conta.
 * @return float Saldo da conta.
 */
float ObtemSaldoConta(tConta* conta);

#endif
