#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    
    int linhas, colunas;
    int **matriz;

    scanf("%d %d", &linhas, &colunas);

    matriz = CriaMatriz(linhas, colunas);

    LeMatriz(matriz, linhas, colunas);

    ImprimeMatrizTransposta(matriz, linhas, colunas);

    LiberaMatriz(matriz, linhas);

    return 0;
}