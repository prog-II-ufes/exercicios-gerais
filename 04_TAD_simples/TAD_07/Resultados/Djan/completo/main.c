#include <stdio.h>
#include "data.h"

int main(){

    tData d1, d2;
    int totalDias = 0;

    scanf("%d/%d/%d",&d1.dia,&d1.mes,&d1.ano);
    scanf("%d/%d/%d",&d2.dia,&d2.mes,&d2.ano);

    if(VerificaDataValida(d1) && VerificaDataValida(d2)){

    printf("Primeira data: ");
    ImprimeDataExtenso(d1);
    printf("Segunda data: ");
    ImprimeDataExtenso(d2);
    if(ComparaData(d1,d2) == 1){
        printf("A segunda data eh mais antiga\n");
    }else if(ComparaData(d1,d2) == -1){
        printf("A primeira data eh mais antiga\n");
    }else{
        printf("As datas sao iguais\n");
    }

    totalDias = CalculaDiferencaDias(d1,d2);
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