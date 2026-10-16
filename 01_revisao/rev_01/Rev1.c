#include <stdio.h>
#include <math.h>

int main(){

    float x1, y1, Raio1, x2, y2, Raio2, 
    distancia, somaRaios;

    scanf("%f %f %f",&x1,&y1,&Raio1);
    scanf("%f %f %f",&x2,&y2,&Raio2);

    distancia = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    somaRaios = Raio1 + Raio2;

    if(distancia <= somaRaios){
        printf("ACERTOU\n");
    }else{
        printf("ERROU\n");
    }

    return 0;
}