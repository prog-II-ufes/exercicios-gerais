#include <stdio.h>
#include "data.h"

int main(){

    int dia1, dia2, mes1, mes2, ano1, ano2, totalDias = 0;

    scanf("%d/%d/%d",&dia1,&mes1,&ano1);
    scanf("%d/%d/%d",&dia2,&mes2,&ano2);

    if(verificaDataValida(dia1,mes1,ano1) && verificaDataValida(dia2,mes2,ano2)){

        printf("Primeira ");
        imprimeDataExtenso(dia1,mes1,ano1);
        printf("Segunda ");
        imprimeDataExtenso(dia2,mes2,ano2);
        if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == 1){
            printf("A segunda data eh mais antiga\n");
        }else if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == -1){
            printf("A primeira data eh mais antiga\n");
        }else{
            printf("As datas sao iguais\n");
        }

        totalDias = calculaDiferencaDias(dia1,mes1,ano1,dia2,mes2,ano2);
        if(totalDias == 0){
            printf("A diferenca em dias entre as datas eh: 00 dias\n");
        }else{
            printf("A diferenca em dias entre as datas eh: %02d dias\n",totalDias);
        }
    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}