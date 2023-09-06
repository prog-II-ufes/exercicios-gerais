#ifndef _empresa
#define _empresa
#include "funcionario.h"

typedef struct empresa {
    int id;
    tFuncionario funcionarios[20];
    int qtdFuncionarios;
} tEmpresa;

/**
 * @brief Cria uma empresa a partir de valores de nome e salario.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criado a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id);

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario);

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa);

#endif