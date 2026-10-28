#ifndef _BANCO_H_
#define _BANCO_H_

/**
 * @brief Tipo opaco que representa um banco com pelo menos os seguintes atributos: 
 * a lista de contas abertas. Não há limite para a quantidade de contas 
 * (a lista deve crescer conforme a necessidade).
 */
typedef struct Banco tBanco;

/**
 * @brief Cria um novo banco, sem nenhuma conta aberta. Se não for possível alocar memória, o programa é encerrado.
 * Todos os campos da estrutura devem ser inicializados aqui.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco();

/**
 * @brief Libera a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco);

/**
 * @brief Abre uma nova conta no banco: cria a conta, lê os seus dados (ambos com suas respectivas funções)
 * e a adiciona ao final da lista de contas.
 * Pode-se assumir que o número da conta e o usuário ainda não existem no banco.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco);

/**
 * @brief Realiza um saque em uma conta (utilizando sua função apropriada) do banco 
 * se ela existir. Nessa função é necessário ler o número da conta e o valor do saque.
 * Se a conta não existir, nada acontece. 
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco);

/**
 * @brief Realiza um depósito em uma conta (utilizando sua função apropriada) do banco 
 * se ela existir. Nessa função é necessário ler o número da conta e o valor do depósito.
 * Se a conta não existir, nada acontece.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco);

/**
 * @brief Realiza uma transferência entre duas contas (utilizando sua função apropriada) do banco se elas existirem.
 * Nessa função é necessário ler, NESTA ORDEM, o número da conta de DESTINO, o número da conta de
 * ORIGEM e o valor da transferência.
 * Se alguma das contas não existir, nada acontece.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco);

/**
 * @brief Imprime o relatório do banco: primeiro a linha "===| Imprimindo Relatorio |===\n" e, em
 * seguida, todas as contas (utilizando sua função apropriada) na ordem de abertura.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco);

#endif