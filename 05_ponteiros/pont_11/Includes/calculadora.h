#ifndef _CALCULADORA_H
#define _CALCULADORA_H

/**
 * @brief Ponteiro para função que recebe dois float e realiza uma operação matemática.
 * 
 * @param float resultado da operacao matematica.
 */
typedef float (*CalculatoraCallback)(float, float);

/**
 * @brief Função que realiza uma operação matemática entre dois númeross.
 * 
 * @param num1 Primeiro número.
 * @param num2 Segundo número.
 * @param operacao Ponteiro para a função que realiza a operação matemática.
 * @return float Resultado da operação matemática.
 */
float Calcular(float num1, float num2, CalculatoraCallback operacao);

#endif