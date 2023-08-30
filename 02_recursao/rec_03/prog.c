#include <stdio.h>

void LeVetor(int* vet, int numElementos) {
    int i;

    for(i = 0; i < numElementos; i++) {
        scanf("%d", &vet[i]);
    }
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    int ocorrencias = 0;

    if(numElementos - 1 == 0) {
        if(vet[0] == numeroProcurado) {
            ocorrencias++;
            return ocorrencias;
        } else {
            return ocorrencias;
        }
        
    } else {
        if(vet[numElementos - 1] == numeroProcurado) {
            numElementos--;
            ocorrencias += ContaOcorrencias(vet, numElementos, numeroProcurado);
            ocorrencias++;
            return ocorrencias;

        } else {
            numElementos--;
            ocorrencias += ContaOcorrencias(vet, numElementos, numeroProcurado);
            return ocorrencias;
        }
    }

}

int main () {
    int numVetores = 0, numElementos = 0, numProcurado = 0, i = 0;

    scanf("%d", &numVetores);

    for(i = 0; i < numVetores; i++) {
        scanf("%d %d", &numProcurado, &numElementos);

        int vet[numElementos], ocorrencias = 0;
        LeVetor(vet, numElementos);

        ocorrencias = ContaOcorrencias(vet, numElementos, numProcurado);
        printf("%d\n", ocorrencias);
    }

    return 0;
}