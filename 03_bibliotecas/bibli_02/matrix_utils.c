#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]) {
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]) {
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {

            if(j == 0) printf("|");

            printf("%d", matrix[i][j]);

            if(j != cols - 1) printf(" ");
            
            if(j == cols - 1) printf("|\n");
        }
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2) {
    if(rows1 == rows2 && cols1 == cols2) return 1;
    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2) {
    if(rows1 == rows2 && cols1 == cols2) return 1;
    return 0;
}

int possible_matrix_multiply(int cols1, int rows2) {
    if(cols1 == rows2) return 1;
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {
    int i, j;

    if(possible_matrix_sum(rows1, cols1, rows2, cols2)) {
        for(i = 0; i < rows1; i++) {
            for(j = 0; j < cols1; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    } else printf("Erro: as dimensoes da matriz nao correspondem\n");
        
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]) {
    int i, j;

    if(possible_matrix_sub(rows1, cols1, rows2, cols2)) {
        for(i = 0; i < rows1; i++) {
            for(j = 0; j < cols1; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    } else printf("Erro: as dimensoes da matriz nao correspondem\n");
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    int i, j, k, soma = 0;

    if(possible_matrix_multiply(cols1, rows2)) {
        for(i = 0; i < rows1; i++) {
            for(j = 0; j < cols2; j++) {
                soma = 0;
                for(k = 0; k < cols1; k++) {
                    soma += matrix1[i][k] * matrix2[k][j];
                }
                result[i][j] = soma;
            }
        }

    } else printf("Erro: as dimensoes da matriz nao correspondem\n");
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {

}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar) {

}
