#include <stdio.h>
#include "matrix_utils.h"

int main(int argc, char const *argv[])
{
    int rows1, cols1, rows2, cols2;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    int opcao = -1;

    while (1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
            if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        } else if (opcao == 2) {
            if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        } else if (opcao == 3) {
            if (possible_matrix_multiply(cols1, rows2)) {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        } else if (opcao == 4) {
            int escalar, escolha;
            scanf("%d %d", &escalar, &escolha);

            if (escolha == 1) {
                scalar_multiply(rows1, cols1, matrix1, escalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else if (escolha == 2) {
                scalar_multiply(rows2, cols2, matrix2, escalar);
                matrix_print(rows2, cols2, matrix2);
            }
        } else if (opcao == 5) {
            int result[cols1][rows1];
            transpose_matrix(rows1, cols1, matrix1, result);
            matrix_print(cols1, rows1, result);

            printf("\n");

            transpose_matrix(rows2, cols2, matrix2, result);
            matrix_print(cols2, rows2, result);

        } else if (opcao == 6) {
            break;
        }

        printf("\n");
    }
    
    return 0;
}
