#include <stdio.h>

int fibonacci(int n);

int main(){

    int num, resultado = 0;

    scanf("%d",&num);

    resultado = fibonacci(num);

    printf("%d\n",resultado);

    return 0;
}

int fibonacci(int n){
    
    if(n > 1){
        return fibonacci(n-1) + fibonacci(n-2);
    } 
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
}