#include <stdio.h>
#include "data.h"

tData criaData(int dia, int mes, int ano) {
    tData data = {dia, mes, ano};

    return data;
}

int verificaDataValida(tData data) {
    if (data.dia < 1 || data.dia > numeroDiasMes(data)) {
        return 0;
    } else if (data.mes < 1 || data.mes > 12) {
        return 0;
    } else {
        return 1;
    }
}

int numeroDiasMes(tData data) {
    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12) {
        return 31;
    } else if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
        return 30;
    } else if (data.mes == 2) {
        if (verificaBissexto(data)) {
            return 29;
        } else {
            return 28;
        }
    }
}

int verificaBissexto(tData data) {
    if (data.ano % 400 == 0) {
        return 1;
    } else if (data.ano % 4 == 0 && data.ano % 100 != 0) {
        return 1;
    } else {
        return 0;
    }
}

void imprimeMesExtenso(tData data) {
    switch (data.mes) {
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
        default:
            break;
    }
}

void imprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    imprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

int comparaData(tData data1, tData data2) {
    if (data1.ano < data2.ano) return 1;
    if (data1.ano > data2.ano) return -1;

    if (data1.mes < data2.mes) return 1;
    if (data1.mes > data2.mes) return -1;

    if (data1.dia < data2.dia) return 1;
    if (data1.dia > data2.dia) return -1;

    return 0;
}

int calculaDiasAteMes(tData data) {
    int dias = 0, mes = data.mes;

    for (int i = 1; i < mes; i++) {
        data.mes = i;
        dias += numeroDiasMes(data);
    }

    return dias;
}

/**
 * @brief Avança um dia na data.
 * 
 * @param data Data a ser avançada
 * @return tData Data avançada
 */
tData avancaData(tData data) {
    data.dia++;

    if (data.dia > numeroDiasMes(data)) {
        data.mes++;
        data.dia = 1;
    }

    if (data.mes > 12) {
        data.ano++;
        data.mes = 1;
    }

    return data;
}

int calculaDiferencaDias(tData data1, tData data2) {
    int diferenca = 0;

    if (comparaData(data1, data2) == -1) {
        while (comparaData(data1, data2) != 0) {
            data2 = avancaData(data2);
            diferenca++;
        }
    } else if (comparaData(data1, data2) == 1) {
        while (comparaData(data1, data2) != 0) {
            data1 = avancaData(data1);
            diferenca++;
        }
    }

    return diferenca;
}
