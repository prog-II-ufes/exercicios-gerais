#include <stdio.h>
#include "matrix_utils.h"

int main(int argc, char const *argv[])
{
    int rows, cols;
    tMatrix matrix1, matrix2;

    scanf("%d %d", &rows, &cols);
    matrix1 = matrix_create(rows, cols);
    matrix1 = matrix_read(matrix1);

    scanf("%d %d", &rows, &cols);
    matrix2 = matrix_create(rows, cols);
    matrix2 = matrix_read(matrix2);

    while (1) {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        int option;
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                if (possible_matrix_sum(matrix1, matrix2)) {
                    matrix_print(matrix_add(matrix1, matrix2));
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                }

                break;
            case 2:
                if (possible_matrix_sub(matrix1, matrix2)) {
                    matrix_print(matrix_sub(matrix1, matrix2));
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                }

                break;
            case 3:
                if (possible_matrix_multiply(matrix1, matrix2)) {
                    matrix_print(matrix_multiply(matrix1, matrix2));
                } else {
                    printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                }

                break;
            case 4:
                int scalar, matrix_option;
                
                scanf("%d %d", &scalar, &matrix_option);

                if (matrix_option == 1) {
                    matrix1 = matrix_multiply_by_scalar(matrix1, scalar); 
                    matrix_print(matrix1);
                } else if (matrix_option == 2) {
                    matrix2 = matrix_multiply_by_scalar(matrix2, scalar); 
                    matrix_print(matrix2);
                } 

                break;
            case 5:
                matrix_print(transpose_matrix(matrix1));
                matrix_print(transpose_matrix(matrix2));

                break;
            case 6:
                return 0;
            default:
                break;
        }
    }
    
    return 0;
}
