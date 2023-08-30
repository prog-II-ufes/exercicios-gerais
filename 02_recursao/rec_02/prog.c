#include <stdio.h>
#include <stdlib.h>

void LeVetor(int* vet, int numElementos) {
    int i;

    for(i = 0; i < numElementos; i++) {
        scanf("%d", &vet[i]);
    }
}

int SomaElementosPares(int* vet, int numElementos) {
    int soma = 0;

    if (numElementos - 1 == 0) {
        if (vet[0] % 2 == 0) return vet[0];
        else return soma;
    }
    else {
        if (vet[numElementos - 1] % 2 == 0) {
            soma += vet[numElementos - 1];
            numElementos--;
            soma += SomaElementosPares(vet, numElementos);
            return soma;
        }
        else {
            numElementos--;
            soma += SomaElementosPares(vet, numElementos);
            return soma;
        }
    }
    
}

int main () {
    int numVetores, numElementos, i;
    
    scanf("%d", &numVetores);
    
    for(i = 0; i < numVetores; i++) {
        scanf("%d", &numElementos);
        
        int vet[numElementos], soma = 0;
        LeVetor(vet, numElementos);

        soma = SomaElementosPares(vet, numElementos);
        printf("%d\n", soma);
    }
    
    return 0;
}