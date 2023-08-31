#include "matrix_utils.h"
#include <stdio.h>

void print_menu() {
    printf("1 - Soma matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}

int main() {
    int rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0, acao;
    int matrix1[rows1][cols1], matrix2[rows2][cols2];

    matrix_read(rows1, cols1, matrix1);
    matrix_read(rows2, cols2, matrix2);

    while (scanf("%d", &acao) == 1) {
        if(acao == 6) break;
        else if(acao == 1) {
            matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, matrix1);

        } else if(acao == 2) {
            matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, matrix1);

        } else if(acao == 3) {
            matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, matrix1);

        } else if(acao == 4) {
            

        } else if(acao == 5) {

        } else {

        }

    }
    

    return 0;
}