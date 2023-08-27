#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string);
int ehEspaco(char ch);

int main() {
    char string[1000];

    scanf("%[^\n]\n", string);

    ImprimeInvertido(string);

    return 0;
}

void ImprimeInvertido(char* string) {
    int tam = strlen(string);
    int tam_palavra = 0;

    for (int i = 0; i <= tam; i++) {
        if (ehEspaco(string[i])) {
            for (int j = i - 1; j >= tam_palavra; j--) {
                printf("%c", string[j]);
            }
            tam_palavra = i + 1;
            if (ehEspaco(string[i])) {
                printf(" ");
            }
        }
    }
}

int ehEspaco(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\0';
}
