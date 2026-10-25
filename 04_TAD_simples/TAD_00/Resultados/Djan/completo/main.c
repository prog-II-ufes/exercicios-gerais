#include <stdio.h>
#include "ponto.h"

int main(){

    Ponto p1, p2;
    float x1,x2,y1,y2, resultado = 0;

    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    p1 = pto_cria(x1,y1);
    p2 = pto_cria(x2,y2);
    x1 = pto_acessa_x(p1);
    pto_atribui_x(p1,x1);
    y1 = pto_acessa_y(p1);
    pto_atribui_y(p1,y1);
    x2 = pto_acessa_x(p2);
    pto_atribui_x(p2,x2);
    y2 = pto_acessa_y(p2);
    pto_atribui_y(p2,y2);
    resultado = pto_distancia(p1,p2);

    printf("%g",resultado);

    return 0;
}