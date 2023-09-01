#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (ano < 0) return 0;

    if (dia < 1 || dia > numeroDiasMes(mes, ano)) return 0;

    return 1;
}

int verificaBissexto(int ano) {
    if (ano % 400 == 0) return 1;
    if (ano % 4 == 0 && ano % 100 != 0) return 1;

    return 0;
}

void imprimeMesExtenso(int mes) {
    switch (mes) {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Marco");
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

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %02d\n", ano);
}

int numeroDiasMes(int mes, int ano) {
    if (mes == 2) {
        if (verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 0;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {    
    if (ano1 < ano2) {
        return 1;
    } else if (ano1 > ano2) {
        return -1;
    } else {
        if (mes1 < mes2) {
            return 1;
        } else if (mes1 > mes2) {
            return -1;
        } else {
            if (dia1 < dia2) {
                return 1;
            } else if (dia1 > dia2) {
                return -1;
            } else {
                return 0;
            }
        }
    }
    
    // if (ano1 < ano2) return 1;
    // if (ano1 > ano2) return -1;

    // if (mes1 < mes2) return 1;
    // if (mes1 > mes2) return -1;

    // if (dia1 < dia2) return 1;
    // if (dia1 > dia2) return -1;

    // return 0;
}

int calculaDiasAteMes(int mes, int ano) {
    int dias = 0;

    for (int i = 1; i < mes; i++) {
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int diferenca = 0;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0) return 0;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1) {
        diferenca -= calculaDiasAteMes(mes2, ano2);
        diferenca -= dia2;

        diferenca += calculaDiasAteMes(mes1, ano1);
        diferenca += dia1;

        for (int i = ano2; i < ano1; i++) {
            if (verificaBissexto(i)) {
                diferenca += 366;
            } else {
                diferenca += 365;
            }
        }
    } else {
        diferenca -= calculaDiasAteMes(mes1, ano1);
        diferenca -= dia1;

        diferenca += calculaDiasAteMes(mes2, ano2);
        diferenca += dia2;

        for (int i = ano1; i < ano2; i++) {
            if (verificaBissexto(i)) {
                diferenca += 366;
            } else {
                diferenca += 365;
            }
        }
    }

    return diferenca;
}
