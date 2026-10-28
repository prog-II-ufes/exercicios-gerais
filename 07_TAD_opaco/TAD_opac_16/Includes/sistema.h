#ifndef _sistema
#define _sistema

#include "data.h"

/**
 * @brief Tipo opaco que representa o sistema do estacionamento que possui pelo menos os seguintes
 * atributos: o faturamento e os preços da hora em dia útil e no fim de semana.
 */
typedef struct Sistema tSistema;

/**
 * @brief Cria um sistema, ainda sem faturamento. A hora custa R$ 1,00 nos dias úteis e
 * R$ 2,00 aos sábados e domingos.
 * Todos os campos da estrutura devem ser inicializados aqui.
 *
 * @return tSistema* Ponteiro para o sistema criado.
 */
tSistema* CriaSistema();

/**
 * @brief Libera a memória de um sistema.
 *
 * @param sys Ponteiro para o sistema a ser destruído.
 */
void DestroiSistema(tSistema* sys);

/**
 * @brief Lê um tíquete (uma linha) da entrada padrão e guarda seus dados nas datas de entrada e de saída.
 * A linha tem o formato "<dia da semana>; DD/MM/AAAA; HH:MM; DD/MM/AAAA; HH:MM" (dia da semana,
 * data e horário de entrada, data e horário de saída). Pode-se assumir que a saída não é anterior à entrada.
 *
 * @param dataEntrada Ponteiro para a data que receberá a entrada do carro.
 * @param dataSaida Ponteiro para a data que receberá a saída do carro.
 * @return int 1 se um tíquete foi lido, 0 se a linha lida é vazia ou se a entrada terminou.
 */
int LeTiquete(tData* dataEntrada, tData* dataSaida);

/**
 * @brief Lê todos os tíquetes da entrada padrão (utilizando sua função apropriada) até uma linha vazia
 * ou o fim da entrada. Para cada tíquete, calcula o seu preço como descrito no enunciado, soma-o ao
 * faturamento e imprime "O tiquete processado tem valor: <preço> reais\n", com o preço com 2 casas decimais.
 *
 * @param sys Ponteiro para o sistema.
 */
void ProcessaTiquetes(tSistema* sys);

/**
 * @brief Imprime o faturamento do sistema: "O sistema faturou: <faturamento> reais\n",
 * com 2 casas decimais.
 *
 * @param sys Ponteiro para o sistema.
 */
void ImprimeFaturamentoSistema(tSistema *sys);


#endif
