#include <stdio.h>

int somaDigitos(int n);

int main(){

    int num, resultado = 0;

    scanf("%d",&num);

    resultado = somaDigitos(num);

    printf("%d\n",resultado);

    return 0;
}

int somaDigitos(int n){

    if(n < 10){
        return n;
    }

    return (n % 10) + somaDigitos(n / 10);

}