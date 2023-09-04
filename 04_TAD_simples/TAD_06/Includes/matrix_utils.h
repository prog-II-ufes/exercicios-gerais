#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_MATRIX_SIZE 10

typedef struct Matrix{
    int rows;
    int cols;
    int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
} tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix matrix_create(int rows, int cols);

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix matrix_read(tMatrix matrix);

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void matrix_print(tMatrix matrix);

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int possible_matrix_sum(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int possible_matrix_sub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int possible_matrix_multiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix matrix_add(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix matrix_sub(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix matrix_multiply(tMatrix matrix1, tMatrix matrix2);

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix transpose_matrix(tMatrix matrix);

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix matrix_multiply_by_scalar(tMatrix matrix, int scalar);

#endif