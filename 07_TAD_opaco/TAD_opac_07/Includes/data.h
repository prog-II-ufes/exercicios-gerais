#ifndef _data
#define _data

/**
 * @brief Tipo opaco que representa uma data (dia, mês e ano).
 */
typedef struct Data tData;

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Todos os campos da estrutura devem ser inicializados aqui.
 * 
 * @return tData* - Data "vazia"
 */
tData* CriaData();

/**
 * @brief Lê o dia, mês e ano, no formato dd/mm/aaaa, e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data);

/**
 * @brief Libera a memória de uma data.
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data);

/**
 * @brief Verifica se uma data é válida: o mês está entre 1 e 12, o ano é maior ou igual a 1
 * (não existe ano 0) e o dia está entre 1 e o limite de dias do mês.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data);

/**
 * @brief Imprime o mês de uma data por extenso, sem acentos e sem quebra de linha:
 * Se o mês for inválido, imprime "Mes nao valido".
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data);

/**
 * @brief Imprime uma data por extenso, no formato "<dia> de <mes> de <ano>\n", com o dia
 * sempre com dois dígitos e o mês por extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data);

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data);

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data);

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2);

/**
 * @brief Calcula quantos dias se passaram do início do ano até o início do mês da data,
 * ou seja, a soma dos dias dos meses anteriores.
 * Ex.: para qualquer data de março de um ano não bissexto, o resultado é 31 + 28 = 59.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias do início do ano até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data);

/**
 * @brief Calcula a diferença em dias entre duas datas válidas. O resultado nunca é
 * negativo, qualquer que seja a ordem das datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2);

#endif