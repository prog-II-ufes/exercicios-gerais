#ifndef _ROLAGEM_H
#define _ROLAGEM_H

#define TAM_MAX_MSG 1000
#define NUM_MAX_MSGS 10

/**
 * @brief Ponteiro para função que recebe um array de mensagens e o número de mensagens para rolagem.
 * 
 * @param msg Array de mensagens.
 * @param numMsgs Número de mensagens.
 */
typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

/**
 * @brief Dispara a função de rolagem de mensagens.
 * 
 * @param FuncMsg Ponteiro para a função que recebe um array de mensagens e o número de mensagens.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem.
 */
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim);

#endif