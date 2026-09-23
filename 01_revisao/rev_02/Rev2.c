#include <stdio.h>

int main(){

    int N, i, j, cont = 1;

    scanf("%i",&N);

    for(i = 1; i <= N; i++){
        for(j = 1; j <= i; j++){
                printf("%i ",cont);
                cont++;
        }
        printf("\n");
    }

    return 0;
}