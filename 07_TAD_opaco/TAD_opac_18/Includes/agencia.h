#ifndef _agencia
#define _agencia

#define LIMITE_SUSPEITA 20000.00 /**< Operações com valor (em módulo) acima deste são suspeitas */

/**
 * @brief Tipo opaco que representa uma agência que possui pelo menos os seguintes atributos:
 * a lista de contas e a lista de operações.
 */
typedef struct Agencia tAgencia;

/**
 * @brief Cria uma agência, ainda sem contas e sem operações.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tAgencia* Ponteiro para a agência criada.
 */
tAgencia* CriaAgencia();

/**
 * @brief Libera a memória de uma agência, inclusive a das suas contas e a das suas operações.
 *
 * @param agencia Ponteiro para a agência a ser destruída.
 */
void DestroiAgencia(tAgencia* agencia);

/**
 * @brief Lê da entrada padrão as contas e as operações da agência, no formato descrito no enunciado.
 * Cada conta lida é salva na lista de contas da agência.
 * Cada operação lida é guardada na agência e altera o saldo da sua conta.
 * Uma entrada inválida não é contada e deve ser repetida. Para cada um dos erros abaixo imprima sua respectiva mensagem:
 * - Se o id da conta for menor ou igual a zero: "Digite um id valido para a conta a ser cadastrada!\n";
 * - Se o id da conta já estiver cadastrado: "Este id ja esta cadastrado na agencia. Digite um id diferente!\n";
 * - Se a operação for em uma conta não cadastrada: "Conta Invalida! Repita a operacao, mas com uma conta valida!\n".
 *
 * @param agencia Ponteiro para a agência.
 */
void LeAgencia(tAgencia* agencia);

/**
 * @brief Imprime "A lista de operacoes suspeitas:\n" e, em seguida, as operações suspeitas
 * (utilizando sua função apropriada), na ordem em que foram lidas.
 * Uma operação é suspeita se o seu valor é maior que LIMITE_SUSPEITA ou menor que -LIMITE_SUSPEITA.
 *
 * @param agencia Ponteiro para a agência.
 */
void ImprimeOperacoesSuspeitas(tAgencia* agencia);

/**
 * @brief Imprime os dois correntistas com maior saldo, do maior para o menor:
 * "Os dois correntistas com maior saldo sao:\n" seguido de "Id: <id>, Saldo: <saldo>\n" para cada um,
 * com o saldo com 2 casas decimais. Em caso de empate, vem antes a conta cadastrada primeiro.
 * Se não houver contas, imprime "Nao ha correntistas cadastrados na agencia\n".
 * Se houver apenas uma, imprime "Ha apenas um correntista na agencia, com identificador <id> e saldo <saldo>\n".
 *
 * @param agencia Ponteiro para a agência.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia);

/**
 * @brief Imprime o saldo total da agência (a soma dos valores de todas as operações):
 * "O saldo total da agencia eh: <saldo>\n", com 2 casas decimais.
 *
 * @param agencia Ponteiro para a agência.
 */
void ImprimeSaldoTotal(tAgencia* agencia);

#endif
