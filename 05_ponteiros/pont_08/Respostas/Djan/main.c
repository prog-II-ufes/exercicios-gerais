#include <stdio.h>
#include "tDepartamento.h"

int main(){

    int N, i;
    tDepartamento departamentos[STRING_MAX];

    scanf("%d",&N);

    for(i = 0; i < N; i++){
        
    }

    OrdenaDepartamentosPorMedia(departamentos, N);

    for (int i = 0; i < N; i++) {
        ImprimeAtributosDepartamento(departamentos[i]);
        printf("\n");
    }

    return 0;
}