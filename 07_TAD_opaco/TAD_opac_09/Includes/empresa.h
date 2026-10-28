#ifndef _empresa
#define _empresa
#include "funcionario.h"

/**
 * @brief Tipo opaco que representa uma empresa que possui pelo menos os seguintes atributos:
 * o seu id e a lista de funcionários contratados.
 */
typedef struct Empresa tEmpresa;


/**
 * @brief Cria uma empresa "vazia" (sem funcionários).
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tEmpresa* Ponteiro para a empresa criada.
 */
tEmpresa* CriaEmpresa();

/**
 * @brief Lê os dados de uma empresa da entrada padrão: o id da empresa, a quantidade N de
 * funcionários e, em seguida, lê os N funcionários (utilizando sua função apropriada).
 * Cada funcionário deve ser contratado (utilizando sua função apropriada) assim que é lido.
 *
 * @param empresa Ponteiro para a empresa que terá seus dados preenchidos.
 */
void LeEmpresa(tEmpresa* empresa);

/**
 * @brief Libera a memória de uma empresa, inclusive a dos funcionários contratados.
 *
 * @param empresa Ponteiro para a empresa a ser apagada.
 */
void ApagaEmpresa(tEmpresa* empresa);


/**
 * @brief Adiciona um funcionário ao final da lista de funcionários da empresa, caso o id do
 * funcionário ainda não esteja registrado na empresa.
 * Se a empresa já tiver um funcionário com o mesmo id, não o adiciona, imprime
 * "A empresa <id da empresa> ja possui um funcionario com o id <id do funcionario>\n"
 * e libera a memória do funcionário recebido.
 *
 * @param empresa Ponteiro para a empresa em que o funcionário deve ser adicionado.
 * @param funcionario Ponteiro para o funcionário que deve ser adicionado à empresa.
 */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario);

/**
 * @brief Imprime todos os dados de uma empresa: primeiro a linha "Empresa <id>:\n", em seguida
 * os funcionários (utilizando sua função apropriada) na ordem em que foram contratados e,
 * por fim, uma linha em branco.
 *
 * @param empresa Ponteiro para a empresa a ser impressa.
 */
void ImprimeEmpresa(tEmpresa *empresa);

#endif
