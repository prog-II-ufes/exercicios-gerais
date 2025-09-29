#include <stdio.h>
#include <string.h>

#define MAX_CHARS 128
#define MAX_TAM 1001

int main() {
    int limite;    
    char funkos[MAX_TAM];
    int frequencia[MAX_CHARS] = {0};
    int tam;
    int imprimiu = 0;

    scanf("%d", &limite);
    scanf("%s", funkos);

    tam = strlen(funkos);

    for (int i = 0; i < tam; i++) {
        frequencia[(int)funkos[i]]++;
    }
    
    for (int i = 0; i < MAX_CHARS; i++) {
        if (frequencia[i] > limite) {
            printf("%c: %d\n", (char)i, frequencia[i]);
            imprimiu = 1;
        }
    }

    if (!imprimiu)
        printf("NENHUM\n");

    return 0;
}