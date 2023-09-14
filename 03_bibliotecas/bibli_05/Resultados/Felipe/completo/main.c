#include "string_utils.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int opcao = -1;
    char str_in[1001];

    scanf("%[^\n]", str_in);

    while (1) {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");

        printf("Opcao escolhida: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("Tamanho da string: %d\n", string_length(str_in));
                break;
            case 2:
                printf("String copiada: %s\n", str_in);
                break;
            case 3:
                string_upper(str_in);
                printf("String convertida para maiusculas: %s\n", str_in);
                break;
            case 4:
                string_lower(str_in);
                printf("String convertida para minusculas: %s\n", str_in);
                break;
            case 5:
                string_reverse(str_in);
                printf("String invertida: %s\n", str_in);
                break;
            case 6:
                return 0;
            default:
                break;
        }

        printf("\n");
    }
    
    return 0;
}
