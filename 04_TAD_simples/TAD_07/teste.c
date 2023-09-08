#include <stdio.h>
#include <assert.h>
#include "data.h"


void testVerificaDataValida() {
    tData data1 = {31, 1, 2022};
    tData data2 = {29, 2, 2021};
    tData data3 = {31, 4, 2021};
    tData data4 = {30, 6, 2021};
    tData data5 = {31, 12, 2021};
    tData data6 = {29, 2, 2020};
    tData data7 = {31, 6, 2021};
    tData data8 = {30, 4, 2021};
    tData data9 = {31, 9, 2021};
    tData data10 = {30, 11, 2021};
    
    assert(verificaDataValida(data1) == 1);
    assert(verificaDataValida(data2) == 0);
    assert(verificaDataValida(data3) == 0);
    assert(verificaDataValida(data4) == 1);
    assert(verificaDataValida(data5) == 1);
    assert(verificaDataValida(data6) == 1);
    assert(verificaDataValida(data7) == 0);
    assert(verificaDataValida(data8) == 1);
    assert(verificaDataValida(data9) == 0);
    assert(verificaDataValida(data10) == 1);
}

void testVerificaBissexto() {
    tData data1 = {1, 1, 2020};
    tData data2 = {1, 1, 2021};
    tData data3 = {1, 1, 2000};
    tData data4 = {1, 1, 1900};
    tData data5 = {1, 1, 1600};
    
    assert(verificaBissexto(data1) == 1);
    assert(verificaBissexto(data2) == 0);
    assert(verificaBissexto(data3) == 1);
    assert(verificaBissexto(data4) == 0);
    assert(verificaBissexto(data5) == 1);
}

void testNumeroDiasMes() {
    tData data1 = {1, 1, 2022};
    tData data2 = {1, 2, 2022};
    tData data3 = {1, 4, 2022};
    tData data4 = {1, 6, 2022};
    tData data5 = {1, 8, 2022};
    tData data6 = {1, 9, 2022};
    tData data7 = {1, 11, 2022};
    tData data8 = {1, 12, 2022};
    tData data9 = {1, 3, 2020};
    tData data10 = {1, 2, 2020};
    tData data11 = {1, 2, 2021};
    tData data12 = {1, 2, 1900};
    tData data13 = {1, 2, 2000};
    tData data14 = {1, 2, 1600};
    
    assert(numeroDiasMes(data1) == 31);
    assert(numeroDiasMes(data2) == 28);
    assert(numeroDiasMes(data3) == 30);
    assert(numeroDiasMes(data4) == 30);
    assert(numeroDiasMes(data5) == 31);
    assert(numeroDiasMes(data6) == 30);
    assert(numeroDiasMes(data7) == 30);
    assert(numeroDiasMes(data8) == 31);
    assert(numeroDiasMes(data9) == 31);
    assert(numeroDiasMes(data10) == 29);
    assert(numeroDiasMes(data11) == 28);
    assert(numeroDiasMes(data12) == 28);
    assert(numeroDiasMes(data13) == 29);
    assert(numeroDiasMes(data14) == 29);
}

void testComparaData() {
    tData data1 = {1, 1, 2022};
    tData data2 = {1, 1, 2022};
    tData data3 = {1, 2, 2022};
    tData data4 = {2, 1, 2022};
    tData data5 = {1, 1, 2021};
    tData data6 = {1, 2, 2021};
    tData data7 = {2, 1, 2021};
    
    assert(comparaData(data1, data2) == 0);
    assert(comparaData(data1, data3) == -1);
    assert(comparaData(data1, data4) == -1);
    assert(comparaData(data1, data5) == 1);
    assert(comparaData(data1, data6) == 1);
    assert(comparaData(data1, data7) == 1);
}

void testCalculaDiasAteMes() {
    tData data1 = {1, 1, 2022};
    tData data2 = {1, 2, 2022};
    tData data3 = {1, 3, 2022};
    tData data4 = {1, 4, 2022};
    tData data5 = {1, 5, 2022};
    tData data6 = {1, 6, 2022};
    tData data7 = {1, 7, 2022};
    tData data8 = {1, 8, 2022};
    tData data9 = {1, 9, 2022};
    tData data10 = {1, 10, 2022};
    tData data11 = {1, 11, 2022};
    tData data12 = {1, 12, 2022};
    
    assert(calculaDiasAteMes(data1) == 0);
    assert(calculaDiasAteMes(data2) == 31);
    assert(calculaDiasAteMes(data3) == 59);
    assert(calculaDiasAteMes(data4) == 90);
    assert(calculaDiasAteMes(data5) == 120);
    assert(calculaDiasAteMes(data6) == 151);
    assert(calculaDiasAteMes(data7) == 181);
    assert(calculaDiasAteMes(data8) == 212);
    assert(calculaDiasAteMes(data9) == 243);
    assert(calculaDiasAteMes(data10) == 273);
    assert(calculaDiasAteMes(data11) == 304);
    assert(calculaDiasAteMes(data12) == 334);
}

void testAvancaData() {
    tData data1 = {31, 1, 2022};
    tData data2 = {28, 2, 2022};
    tData data3 = {31, 3, 2022};
    tData data4 = {30, 4, 2022};
    tData data5 = {31, 5, 2022};
    tData data6 = {30, 6, 2022};
    tData data7 = {31, 7, 2022};
    tData data8 = {31, 8, 2022};
    tData data9 = {30, 9, 2022};
    tData data10 = {31, 10, 2022};
    tData data11 = {30, 11, 2022};
    tData data12 = {31, 12, 2022};
    
    assert(comparaData(avancaData(data1), (tData){1, 2, 2022}) == 0);
    assert(comparaData(avancaData(data2), (tData){1, 3, 2022}) == 0);
    assert(comparaData(avancaData(data3), (tData){1, 4, 2022}) == 0);
    assert(comparaData(avancaData(data4), (tData){1, 5, 2022}) == 0);
    assert(comparaData(avancaData(data5), (tData){1, 6, 2022}) == 0);
    assert(comparaData(avancaData(data6), (tData){1, 7, 2022}) == 0);
    assert(comparaData(avancaData(data7), (tData){1, 8, 2022}) == 0);
    assert(comparaData(avancaData(data8), (tData){30, 9, 2022}) == -1);
    assert(comparaData(avancaData(data9), (tData){31, 10, 2022}) == -1);
    assert(comparaData(avancaData(data10), (tData){30, 11, 2022}) == -1);
    assert(comparaData(avancaData(data11), (tData){30, 11, 2022}) == 1);
    assert(comparaData(avancaData(data12), (tData){1, 1, 2023}) == 0);
}

void testCalculaDiferencaDias() {
    tData data1 = {1, 1, 2022};
    tData data2 = {1, 1, 2022};
    tData data3 = {1, 2, 2022};
    tData data4 = {2, 1, 2022};
    tData data5 = {1, 1, 2021};
    tData data6 = {1, 2, 2021};
    tData data7 = {2, 1, 2021};
    
    assert(calculaDiferencaDias(data1, data2) == 0);
    assert(calculaDiferencaDias(data1, data3) == 31);
    assert(calculaDiferencaDias(data1, data4) == 1);
    assert(calculaDiferencaDias(data1, data5) == 365);
    assert(calculaDiferencaDias(data1, data6) == 334);
    assert(calculaDiferencaDias(data1, data7) == 364);
}

int main(int argc, char const *argv[])
{
    testNumeroDiasMes();
    testVerificaBissexto();
    testVerificaDataValida();
    testComparaData();
    testCalculaDiasAteMes();
    testAvancaData();
    testCalculaDiferencaDias();
    
    printf("All tests passed!\n");

    return 0;
}
