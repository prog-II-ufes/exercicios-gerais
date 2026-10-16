#include <stdio.h>

int fatorial(int n);

int main(){

    int num, resultado = 0;
    
    scanf("%d",&num);
    resultado = fatorial(num);

    printf("%d\n",resultado);

    return 0;
}

int fatorial(int n){
    if(n == 1){
        return 1;
    }
        return n*fatorial(n-1);
}