#include <stdio.h>
#include <string.h>

int palindromo(char *string, int tamanho);

int main(int argc, char const *argv[])
{
    char string[100];

    while (scanf("%s\n", string) != EOF)
    {
        if (palindromo(string, strlen(string))) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    
    return 0;
}

int palindromo(char *string, int tamanho) {
    if (tamanho <= 1) {
        return 1;
    } else {
        if (string[0] == string[tamanho - 1]) {
            return palindromo(string + 1, tamanho - 2);
        } else {
            return 0;
        }
    }
}