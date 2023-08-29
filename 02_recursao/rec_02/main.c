#include <stdio.h>
#include <string.h>

int SomaElementosPares(int* vet, int numElementos);

int main() {
    int N, tamVet;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &tamVet);
        int vet[tamVet];
        
        for (int j = 0; j < tamVet; j++) {
            scanf("%d", &vet[j]);
        }

        int soma = SomaElementosPares(vet, tamVet);
        printf("%d\n", soma);
    }

    return 0;
}

int SomaElementosPares(int* vet, int numElementos) {
    int soma = 0;
    
    if (numElementos == 0) {
        return soma;
    } 

    if (vet[--numElementos] % 2 == 0) {
        soma += vet[numElementos];
    } 

    return soma + SomaElementosPares(vet, numElementos);
}
