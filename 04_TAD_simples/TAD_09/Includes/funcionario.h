#ifndef _funcionario
#define _funcionario

typedef struct funcionario {
    int id;
    float salario;
} tFuncionario;

/**
 * @brief Cria um funcionario a partir de valores de nome e salario.
 * 
 * @param id Id do funcionario a ser criado.
 * @param salario Salario do funcionario a ser criado.
 * @return TFuncionario Funcionario criado a partir do nome e salario fornecidos.
 */
tFuncionario criaFuncionario(int id, float salario);

/**
 * @brief Obtem o Id de um funcionario.
 * 
 * @param funcionario Funcionario que deseja obter o id.
 * @return int representando o id do funcionario fornecido.
 */
int getIdFuncionario(tFuncionario funcionario);

/**
 * @brief Imprime todos os dados de um funcionario.
 * 
 * @param funcionario Funcionario a ser impresso no terminal.
 */
void imprimeFuncionario(tFuncionario funcionario);

#endif