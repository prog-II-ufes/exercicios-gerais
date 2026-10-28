#ifndef _CONTA_H_
#define _CONTA_H_

/**
 * @brief Tipo opaco que representa uma conta que possui pelo menos os seguintes atributos: 
 * número, saldo e o usuário dono da conta.
 */
typedef struct Conta tConta;

/**
 * @brief Cria uma nova conta "vazia", ainda sem usuário e com saldo zero.
 * Todos os campos da estrutura devem ser inicializados aqui
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para a nova conta criada.
 */
tConta *CriaConta();

/**
 * @brief Libera a memória de uma conta, inclusive a do seu usuário (se houver) utilizando sua função apropriada.
 * 
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta *conta);

/**
 * @brief Lê os dados de uma conta e do usuário (utilizando sua função apropriada) através da entrada padrão: 
 * o nome e o CPF do usuário e, em seguida, o número da conta. O saldo começa em zero.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta);

/**
*  @brief Imprime os dados de uma conta: "Conta: <numero>\n", "Saldo: R$ <saldo com 2 casas decimais>\n"
*  e, em seguida, os dados do proprietário (utilizando sua função apropriada).

 * 
 * @param conta Ponteiro para a conta a ser impressa.
 */
void ImprimeConta(tConta *conta);

/**
 * @brief Verifica se uma conta possui o numero especificado.
 * 
 * @param conta Ponteiro para a conta a ser verificada.
 * @param numero Número da conta a ser verificado.
 * @return 1 se a conta possui o número especificado, 0 caso contrário.
 */
int VerificaConta(tConta *conta, int numero);

/**
 * @brief Realiza um saque em uma conta caso o valor seja positivo e o saldo seja suficiente.
 * Se o valor for maior que o saldo, não altera a conta e imprime "Saldo Insuficiente!\n".
 * Se o valor for menor ou igual a zero, não faz nada.
 * 
 * @param conta Ponteiro para a conta a ser sacada.
 * @param valor Valor a ser sacado.
 */
void SaqueConta(tConta *conta, float valor);

/**
 * @brief Realiza um depósito em uma conta. Se o valor for menor ou igual a zero, não faz nada.
 * 
 * @param conta Ponteiro para a conta a ser depositada.
 * @param valor Valor a ser depositado.
 */
void DepositoConta(tConta *conta, float valor);

/**
 * @brief Realiza uma transferência entre duas contas, caso o valor seja positivo e o saldo da
 * conta de origem seja suficiente.
 * Se o valor for maior que o saldo da origem, não altera as contas e imprime
 * "Saldo Insuficiente para realizar a transferencia!\n". Se o valor for menor ou igual a zero, não faz nada.
 * 
 * @param destino Ponteiro para a conta de destino.
 * @param origem Ponteiro para a conta de origem.
 * @param valor Valor a ser transferido.
*/
void TransferenciaConta(tConta *destino, tConta *origem, float valor);

#endif