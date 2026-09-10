#include <stdio.h>
#include "data.h"

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano){
    tData d;

    d.dia = dia;
    d.mes = mes;
    d.ano = ano;

    return d;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data){

       
    if(data.ano < 0){
        return 0;
    }

    if((data.mes == 10 || data.mes == 12 || data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8) && (data.dia >= 1 && data.dia <= 31)){
        return 1;
    }else if((data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) && (data.dia >= 1 && data.dia <= 30)){
        return 1;
    }else if(data.mes == 2){
        if(VerificaBissexto(data) == 1 && data.dia >= 1 && data.dia <= 29){
            return 1;
    }else if(VerificaBissexto(data) != 1 && data.dia >= 1 && data.dia <= 28){
            return 1;
    }
    return 0;
    }else{
        return 0;
    }

}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data){
    
    switch (data.mes){
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;                          
    }

}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data){
    printf("%02d de ",data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n",data.ano);

}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data){
    
    if((data.ano%4 == 0 && data.ano%100 != 0) || (data.ano%400 == 0)){
        return 1;
    }else{
        return 0;
    }

}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data){

    switch(data.mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
            if(data.mes == 2 && VerificaBissexto(data) == 1){
                return 29;
            }else{
                return 28;
            }
    }

    return 0;

}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2){
    
    if(data1.ano > data2.ano){
        return 1;
    }else if(data1.ano < data2.ano){
        return -1;
    }
    
    if(data1.mes > data2.mes){ 
        return 1;
    }
    if(data1.mes < data2.mes){
        return -1;
    }
    
    if(data1.dia > data2.dia){
        return 1;
    }else if(data1.dia < data2.dia){ 
        return -1;
    }

    return 0;
    
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data){

    int i, total = 0;
    tData dataAuxiliar = data;
    
    for(i = 1; i < data.mes; i++){
        dataAuxiliar.mes = i;
        total += NumeroDiasMes(dataAuxiliar);
    }

    return total;

}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2){
    
    int diasData1 = 0, mesesData1 = 0, anosData1 = 0;
    int diasData2 = 0, mesesData2 = 0, anosData2 = 0;
    int diferencaDias = 0;

    anosData1 = (data1.ano - 1)*365 + (data1.ano - 1)/4 - (data1.ano - 1)/100 + (data1.ano - 1)/400;
    anosData2 = (data2.ano - 1)*365 + (data2.ano - 1)/4 - (data2.ano - 1)/100 + (data2.ano - 1)/400;

    mesesData1 = CalculaDiasAteMes(data1);
    mesesData2 = CalculaDiasAteMes(data2);

    diasData1 = anosData1 + mesesData1 + data1.dia;
    diasData2 = anosData2 + mesesData2 + data2.dia;

    diferencaDias = diasData2 - diasData1;
    if(diferencaDias < 0){
        return -diferencaDias;
    }else{
        return diferencaDias;
    }

}