#ifndef _HISTOGRAMA_H
#define _HISTOGRAMA_H

#include "imagem.h"

typedef struct tHistograma Histograma;

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos);

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma);

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma);

#endif