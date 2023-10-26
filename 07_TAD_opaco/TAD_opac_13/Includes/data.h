#ifndef _data
#define _data


typedef struct data tData;


/**
 * @brief Lê uma data da entrada padrão.
 * @return Um ponteiro para a data lida.
 */
tData* LeData();

/**
 * @brief Cria uma data com o dia, mês e ano fornecidos. Se a alocação falhar, o programa é encerrado.
 * @param dia O dia da data.
 * @param mes O mês da data.
 * @param ano O ano da data.
 * @return Um ponteiro para a data criada.
 */
tData* CriaData(int dia, int mes, int ano);

/**
 * @brief Libera a memória alocada para uma data.
 * @param d Um ponteiro para a data a ser liberada.
 */
void LiberaData(tData* d);

/**
 * @brief Calcula a idade de uma pessoa com base na data de nascimento e em uma data para calcular a idade.
 * @param nascimento Um ponteiro para a data de nascimento da pessoa.
 * @param diacalc Um ponteiro para a data para calcular a idade.
 * @return A idade da pessoa.
 */
int CalculaIdadeData(tData* nascimento, tData* diacalc);

/**
 * @brief Imprime uma data na saída padrão.
 * @param d Um ponteiro para a data a ser impressa.
 */
void ImprimeData(tData* d);

#endif