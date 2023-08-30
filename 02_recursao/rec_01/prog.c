#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string) {
    int tam = strlen(string);

    if(tam == 0) {
        return;
    }
    else {
        printf("%c", string[tam - 1]);
        string[tam - 1] = '\0';
        ImprimeInvertido(string);
    }
}

int main () {
    char string[1000];

    while(scanf("%s", string) == 1) {
        ImprimeInvertido(string);
        printf(" ");
    }

    return 0;
}