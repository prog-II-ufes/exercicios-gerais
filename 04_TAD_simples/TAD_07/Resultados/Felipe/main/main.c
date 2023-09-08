#include <stdio.h>
#include "data.h"

int main(int argc, char const *argv[])
{
    int dia, mes, ano;

    scanf("%d/%d/%d\n", &dia, &mes, &ano);
    tData data1 = criaData(dia, mes, ano);

    scanf("%d/%d/%d", &dia, &mes, &ano);
    tData data2 = criaData(dia, mes, ano);

    if (!verificaDataValida(data1) || !verificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(data1);

    printf("Segunda data: ");
    imprimeDataExtenso(data2);

    if (comparaData(data1, data2) == 1) {
        printf("A primeira data eh mais antiga\n");
    } else if (comparaData(data1, data2) == -1) {
        printf("A segunda data eh mais antiga\n");
    } else {
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(data1, data2));

    return 0;
}
