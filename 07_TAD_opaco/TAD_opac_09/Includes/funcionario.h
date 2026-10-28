#ifndef _funcionario
#define _funcionario

/**
 * @brief Tipo opaco que representa um funcionário que possui pelo menos os seguintes atributos:
 * o seu id e o seu salário.
 */
typedef struct Funcionario tFuncionario;

/**
 * @brief Cria um funcionário "vazio".
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tFuncionario* Ponteiro para o funcionário criado.
 */
tFuncionario* CriaFuncionario();

/**
 * @brief Libera a memória de um funcionário.
 *
 * @param funcionario Ponteiro para o funcionário a ser apagado.
 */
void ApagaFuncionario(tFuncionario* funcionario);

/**
 * @brief Lê os dados de um funcionário da entrada padrão: o id (inteiro) e o salário (real).
 *
 * @param funcionario Ponteiro para o funcionário que terá seus dados preenchidos.
 */
void LeFuncionario(tFuncionario* funcionario);

/**
 * @brief Obtém o id de um funcionário.
 *
 * @param funcionario Ponteiro para o funcionário.
 * @return int O id do funcionário.
 */
int ObtemIdFuncionario(tFuncionario* funcionario);

/**
 * @brief Imprime os dados de um funcionário no formato "- Funcionario <id>: R$ <salario>\n",
 * com o salário com duas casas decimais.
 *
 * @param funcionario Ponteiro para o funcionário a ser impresso.
 */
void ImprimeFuncionario(tFuncionario* funcionario);

#endif
