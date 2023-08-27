
#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string);

int main() {
    char string[1000];

    
    while (scanf("%s", string) == 1) {
        ImprimeInvertido(string);
        printf(" ");
    }

    return 0;
}

void ImprimeInvertido(char* string) {
    int tam = strlen(string);
    if (tam > 0) {
        ImprimeInvertido(string + 1);
        printf("%c", string[0]);
    }
}
