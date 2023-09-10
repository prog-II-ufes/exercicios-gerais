#include <stdio.h>
#include "matrix_utils.h"

tMatrix matrix_create(int rows, int cols) {
    tMatrix matrix;

    matrix.rows = rows;
    matrix.cols = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            matrix.data[i][j] = 0;
    }

    return matrix;
}

tMatrix matrix_read(tMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++)
            scanf("%d", &matrix.data[i][j]);
    }

    return matrix;
}

void matrix_print(tMatrix matrix) {

    for (int i = 0; i < matrix.rows; i++) {
        printf("|");
        for (int j = 0; j < matrix.cols; j++) {
            if (j == matrix.cols - 1)
                printf("%d", matrix.data[i][j]);
            else
                printf("%d ", matrix.data[i][j]);
        }
        printf("|\n");
    }

    printf("\n");
}

int possible_matrix_sum(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols;
}

int possible_matrix_sub(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols;
}

int possible_matrix_multiply(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.cols == matrix2.rows;
}

tMatrix matrix_add(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = matrix_create(matrix1.rows, matrix1.cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++)
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
    }

    return result;
}

tMatrix matrix_sub(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = matrix_create(matrix1.rows, matrix1.cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++)
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
    }

    return result;
}

tMatrix matrix_multiply(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = matrix_create(matrix1.rows, matrix2.cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            for (int k = 0; k < matrix1.cols; k++)
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
        }
    }

    return result;
}

tMatrix matrix_multiply_by_scalar(tMatrix matrix, int scalar) {
    tMatrix result = matrix_create(matrix.rows, matrix.cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++)
            result.data[i][j] = matrix.data[i][j] * scalar;
    }

    return result;
}

tMatrix transpose_matrix(tMatrix matrix) {
    tMatrix result = matrix_create(matrix.cols, matrix.rows);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++)
            result.data[i][j] = matrix.data[j][i];
    }

    return result;
}
