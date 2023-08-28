#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string);

void imprimePalavrasInvertidas(char* string);

int main() {
    char str[1001];

    scanf("%[^\n]", str);

    imprimePalavrasInvertidas(str);

    return 0;
}

void ImprimeInvertido(char* string) {
    if (*string == '\0') {
        return;
    }

    ImprimeInvertido(string + 1);

    printf("%c", *string);
}

void imprimePalavrasInvertidas(char* string) {
    int i = 0, j = 0;
    char palavra[1001];

    while (string[i]) {
        if (string[i] != ' ') {
            palavra[j] = string[i];
            j++;
        } 
        
        if (string[i] == ' ' || string[i + 1] == '\0'){
            palavra[j] = '\0';
            ImprimeInvertido(palavra);
            printf(" ");

            j = 0;
        }

        i++;
    }
}