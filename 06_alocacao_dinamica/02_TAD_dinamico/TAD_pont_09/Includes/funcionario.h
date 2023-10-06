#ifndef _funcionario
#define _funcionario

typedef struct funcionario {
    int id;
    float salario;
} tFuncionario;

/**
 * @brief Cria um funcionario "vazio" 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TFuncionario Ponteiro para Funcionario criado a partir do nome e salario fornecidos.
 */
tFuncionario* CriaFuncionario();

/**
 * @brief Libera a memória alocada dinamicamente por um funcionário
 * @param funcionario Ponteiro para Funcionario que terá sua memória liberada
 */
void ApagaFuncionario(tFuncionario* funcionario);

/**
 * @brief Le os dados de um funcionario da entrada padrao.
 * 
 * @param funcionario Funcionario criado a partir dos dados lidos.
 */
void LeFuncionario(tFuncionario* funcionario);

/**
 * @brief Obtem o Id de um funcionario.
 * 
 * @param funcionario Funcionario que deseja obter o id.
 * @return int representando o id do funcionario fornecido.
 */
int GetIdFuncionario(tFuncionario* funcionario);

/**
 * @brief Imprime todos os dados de um funcionario.
 * 
 * @param funcionario Funcionario a ser impresso no terminal.
 */
void ImprimeFuncionario(tFuncionario* funcionario);

#endif