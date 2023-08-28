#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos) {
    if (numElementos <= 0) {
        return 0;
    }

    int numAtual = vet[numElementos - 1];
    int somaAtual = SomaElementosPares(vet, numElementos - 1);

    if (numAtual % 2 == 0) {
        return somaAtual + numAtual;
    } else {
        return somaAtual;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);

        int vet[size];

        for (int j = 0; j < size; j++) {
            scanf("%d", &vet[j]);
        }

        printf("%d\n", SomaElementosPares(vet, size));
    }

    return 0;
}