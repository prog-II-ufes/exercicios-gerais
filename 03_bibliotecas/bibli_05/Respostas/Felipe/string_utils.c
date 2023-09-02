#include "string_utils.h"

int string_length(char *str) {
    int i = 0;

    while (str[i]) {
        i++;
    }

    return i;
}

void string_copy(char *src, char *dest) {
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

void string_upper(char *str) {
    int i = 0;

    while (str[i]) {
        char c = str[i];

        if (c >= 'a' && c <= 'z') {
            str[i] = c - 32;
        }

        i++;
    } 
}

void string_lower(char *str) {
    int i = 0;

    while (str[i]) {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            str[i] = c + 32;
        }

        i++;
    }
}

void string_reverse(char *str) {
    int size = string_length(str);
    
    for (int i = 0; i < size/2; i++) {
        char aux = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = aux;
    }
}
