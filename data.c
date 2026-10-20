#include "data.h"

/**
 * @file data.h
 * @brief Biblioteca para manipulação de datas.
 * 
 * Esta biblioteca contém funções para verificar a validade de uma data, imprimir uma data por extenso,
 * verificar se um ano é bissexto, calcular o número de dias de um mês, comparar duas datas e calcular a
 * diferença em dias entre duas datas.
 * 
 */


/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){
    
    if(ano > 0 && (mes == 10 || mes == 12 || mes == 1 || mes == 3 || mes == 5 || (mes >= 7 && mes <= 8)) && (dia >= 1 && dia <= 31)){
        return 1;
    }else if(ano > 0 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia >= 1 && dia <= 30)){
        return 1;
    }else if((verificaBissexto(ano) == 1 && (dia >= 1 && dia <= 29) && mes == 2) || (verificaBissexto(ano) != 1 && (dia >= 1 && dia <= 28) && mes == 2)){
        return 1;
    }else{
        return 0;
    }

}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){
    
    switch (mes){
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
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    
    

}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){

    if((ano%4 == 0 && ano%100 != 0) || (ano%400 == 0)){
        return 1;
    }else{
        return 0;
    }

}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){

    switch(mes){
    case 2:
            if(mes == 2 && verificaBissexto(ano) == 1){
                return 29;
            }else{
                return 28;
            }
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
    }
    
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    if(ano1 > ano2){
        return 1;
    }else if(ano1 < ano2){
        return -1;
    }
    
    if(mes1 > mes2){ 
        return 1;
    }
    if(mes1 < mes2){
        return -1;
    }
    
    if(dia1 > dia2){
        return 1;
    }else if(dia1 < dia2){ 
        return -1;
    }

    return 0;
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    
    int i, total = 0;

    if(verificaBissexto(mes) == 1 && mes == 2){
        total += numeroDiasMes(mes,ano);
    }else{
        total += numeroDiasMes(mes,ano);
    }

    
    for(i = 0; i < mes; i++){
        total += numeroDiasMes(mes,ano);
    }

    return total;

}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    int diasData1 = 0, mesesData1 = 0, anosData1 = 0;
    int diasData2 = 0, mesesData2 = 0, anosData2 = 0;
    int diferencaDias = 0;

    anosData1 = (ano1 - 1)*365 + (ano1 - 1)/4 - (ano1 - 1)/100 + (ano1 - 1)/400;
    anosData2 = (ano2 - 1)*365 + (ano2 - 1)/4 - (ano2 - 1)/100 + (ano2 - 1)/400;

    mesesData1 = calculaDiasAteMes(mes1, ano1);
    mesesData2 = calculaDiasAteMes(mes2, ano2);

    diasData1 = anosData1 + mesesData1 + dia1;
    diasData2 = anosData2 + mesesData2 + dia2;

    diferencaDias = diasData2 - diasData1;
    if(diferencaDias < 0){
        return diferencaDias = -diferencaDias;
    }else{
        return diferencaDias;
    }
}