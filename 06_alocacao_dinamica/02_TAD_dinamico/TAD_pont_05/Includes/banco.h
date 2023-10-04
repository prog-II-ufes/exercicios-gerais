#ifndef _BANCO_H_
#define _BANCO_H_

#include "conta.h"

typedef struct Banco {
    tConta **contas;
    int qtdContas;
    int contasAlocadas;
} tBanco;

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco();

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco);

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco);

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco);

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco);

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco);

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco);

#endif