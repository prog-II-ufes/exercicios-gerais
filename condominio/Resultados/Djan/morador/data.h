
#ifndef _DATA_H
#define _DATA_H

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

/*
 * Função que lê uma data no formato dd/mm/aaaa
 * e retorna a Data lida
 */
Data lerData();

/*
 * Função que imprime uma data no formato dd/mm/aaaa
 * Com \n no final.
 */
void imprimeData(Data d);

/*
 *   Função que compara se as duas datas são exatamente iguais
 *   Retorna 1 se verdadeiro e 0 caso contrário
 */
int comparaData(Data d1, Data d2);

/*
 *  Função que calcula a diferença de anos entre duas datas da mesma
 *  forma que calculamos aniversários.
 *  Exemplo: 25/12/1990 e 10/12/2025 = 34 anos
 *  Retorna a diferença de anos entre as duas datas
 */
int calcularDiffAnosData(Data inicio, Data fim);

#endif