#ifndef _data
#define _data

/**
 * @brief Tipo opaco que representa uma data com horário que possui pelo menos os seguintes atributos:
 * dia, mês, ano, horas, minutos e dia da semana (0 = domingo, 1 = segunda, ..., 6 = sábado).
 */
typedef struct Data tData;

/**
 * @brief Cria uma data "vazia".
 * Todos os campos da estrutura devem ser inicializados aqui com 0.
 *
 * @return tData* Ponteiro para a data criada.
 */
tData* CriaData();

/**
 * @brief Libera a memória de uma data.
 *
 * @param data Ponteiro para a data a ser destruída.
 */
void DestroiData(tData* data);

/**
 * @brief Lê o dia, o mês e o ano de uma string no formato "DD/MM/AAAA" e os guarda na data.
 * A string vinda da entrada padrão pode começar com espaços.
 *
 * @param data Ponteiro para a data.
 * @param str String a ser lida.
 */
void LeDiaMesAno(tData* data, char* str);

/**
 * @brief Lê o dia da semana (inteiro de 0 a 6) de uma string e o guarda na data.
 * A string pode começar com espaços. Os demais campos da data não são alterados.
 *
 * @param data Ponteiro para a data.
 * @param str String a ser lida.
 */
void LeDiaDaSemana(tData* data, char* str);

/**
 * @brief Lê as horas e os minutos de uma string no formato "HH:MM" e os guarda na data.
 * A string pode começar com espaços. Os demais campos da data não são alterados.
 *
 * @param data Ponteiro para a data.
 * @param str String a ser lida.
 */
void LeHorario(tData* data, char* str);

/**
 * @brief Compara somente o dia, o mês e o ano de duas datas, ignorando o horário e o dia da semana.
 *
 * @param data1 Ponteiro para a primeira data.
 * @param data2 Ponteiro para a segunda data.
 * @return int 1 se data1 é posterior a data2, -1 se data1 é anterior a data2 e 0 se são o mesmo dia.
 */
int ComparaDiaMesAno(tData* data1, tData* data2);

/**
 * @brief Calcula quantos minutos se passaram de data1 até data2, considerando dia, mês, ano,
 * horas e minutos (o dia da semana é ignorado). O resultado é negativo se data2 for anterior a data1.
 * Ex.: de 23/10/2023 23:50 até 24/10/2023 00:10 se passaram 20 minutos.
 *
 * @param data1 Ponteiro para a data inicial.
 * @param data2 Ponteiro para a data final.
 * @return int Número de minutos de data1 até data2.
 */
int CalculaMinutosEntreDatas(tData* data1, tData* data2);

/**
 * @brief Verifica se uma data corresponde a um sábado ou a um domingo, de acordo com o seu dia da semana.
 *
 * @param data Ponteiro para a data.
 * @return int 1 se é sábado ou domingo, 0 caso contrário.
 */
int DataEhSabadoOuDomingo(tData* data);

/**
 * @brief Avança a data para o dia seguinte, atualizando também o dia da semana
 * (depois do sábado vem o domingo). O horário não é alterado. Considera os anos bissextos.
 *
 * @param data Ponteiro para a data a ser modificada.
 */
void DataDiaSeguinte(tData* data);

/**
 * @brief Copia o dia, o mês, o ano e o dia da semana da data src para a data tgt.
 * O horário de tgt não é alterado, e src não é modificada.
 *
 * @param src Ponteiro para a data que terá seus dados copiados.
 * @param tgt Ponteiro para a data que receberá a cópia.
 */
void CopiaDiaMesAno(tData* src, tData* tgt);

#endif
