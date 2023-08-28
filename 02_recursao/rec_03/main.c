#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);  

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int size;
        int numeroProcurado;

        scanf("%d %d", &numeroProcurado, &size);
        int vet[size];

        for (int j = 0; j < size; j++) {
            scanf("%d", &vet[j]);
        }

        printf("%d\n", ContaOcorrencias(vet, size, numeroProcurado));
    }
    
    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    if (numElementos <= 0) {
        return 0;
    }

    int ocorrencias = ContaOcorrencias(vet, numElementos - 1, numeroProcurado);

    if (numeroProcurado == vet[numElementos - 1]) {
        return ocorrencias + 1;
    } else {
        return ocorrencias;
    }
}
