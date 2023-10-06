#ifndef _empresa
#define _empresa
#include "funcionario.h"

typedef struct empresa {
    int id;
    tFuncionario** funcionarios; //Ponteiro duplo pois será um vetor (alocado dinamicamente) para ponteiros de Funcionarios
    int qtdFuncionarios;
} tEmpresa;

/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa();

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa);

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa);


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario);

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa);

#endif