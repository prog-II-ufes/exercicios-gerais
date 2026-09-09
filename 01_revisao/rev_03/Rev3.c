#include <stdio.h>

int main(){

    int N, i, j;

    scanf("%i",&N);
    int identificador[N], naoCopia[j], vet[i];

    for(i = 0; i < N; i++){
        scanf("%i",&identificador[i]);
    }


    for(i = 0; i < N-1; i++){
        for(j = 1; j <= N; j++){     
            if(identificador[i] == identificador[j]){
                vet [i] = identificador [i];
            }
        }
    }

    j = 0;
    for(i = 0; i <= N; i++){
        if(vet[i] == identificador[i]){

        }else{
            naoCopia[j] == identificador[i];
            j++;
        }
    }

    if(naoCopia[0] > 0){
        for(i = 0; i <= j; i++){
        printf("%i \n",naoCopia[i]);
        }
    }else{
        printf("NENHUM\n");
    }
    

    return 0;
}