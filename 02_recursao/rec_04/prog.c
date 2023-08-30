#include <stdio.h>
#include <string.h>

#define TAM_MAX 100

void DeslocaParaEsquerda(char* string) {
    int i = 0;

    while(string[i] != '\0') {
        string[i] = string[i+1];
        i++;
    }
}

int palindromo(char *string, int tamanho) { //retorna 1 para SIM e 0 para NAO

    if(tamanho == 1 || (tamanho == 2 && string[tamanho - 1] == string[0])) return 1;
    else {
        if(string[tamanho - 1] == string[0]) {
            DeslocaParaEsquerda(string);
            string[tamanho - 2] = '\0';
            tamanho = strlen(string);
            if(palindromo(string, tamanho)) return 1;
            else return 0;
        }
        else return 0;
    }
}

int main () {
    char string[TAM_MAX];
    int tamanho = 0;

    while(scanf("%s", string) == 1) {
        tamanho = strlen(string);

        if(palindromo(string, tamanho)) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}