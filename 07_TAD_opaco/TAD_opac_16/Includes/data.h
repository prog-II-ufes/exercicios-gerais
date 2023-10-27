#ifndef _data
#define _data

/*
  Esse .h foi adaptado do TAD_pont_07
*/

typedef struct Data tData;

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData();

/**
 * @brief Libera toda a memoria alocada dinamicamente para armazenar uma data
 * 
 * @param tData - Data que será liberada
 */
void DestroiData(tData* data);

/**
 * @brief Processa o dia, mês e ano da string str e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaDiaMesAno(tData* data, char* str);

/**
 * @brief Processa o dia da semana da string str e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaDiaDaSemana(tData* data, char* str);

/**
 * @brief Processa hora, minuto e segundo da string str e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaHorario(tData* data, char* str);

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data);


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
int ComparaDiaMesAno(tData* data1, tData* data2);

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data);

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2);

/**
 * @brief Calcula a diferença em horas entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return float número de horas entre as duas datas (2,5 horas = 2h30)
 */
float CalculaHorasEntreDatas(tData* data1, tData* data2);

/**
 * @brief Verifica se uma data corresponde a um sábado ou domingo
 * 
 * @param data1 Primeira data a ser comparada.
 * @return int 1 se é sábado ou domingo, 0 caso contrário
 */
int DataEhSabadoOuDomingo(tData* data);

/**
 * @brief Atualiza a data para a data do dia seguinte (esta data deve ser válida!)
 * 
 * @param data Data a ser modificada.
 * 
 */
void DataDiaSeguinte(tData* data);

/**
 * @brief Copia os dados de Dia/Mês/Ano de uma data src para uma data tgt.
 * 
 * @param src Data que terá seus dados copiados
 * @param tgt Data que armazenará a cópia
 */
void CopiaDiaMesAno(tData* src, tData* tgt);

#endif

