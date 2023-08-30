#include <stdio.h>

int SomaDigitos(int n) {
    int n_final = 0, soma = 0;

    if(n / 10 == 0) return n;
    else {
        n_final = n % 10;
        n = n/10;
        soma += n_final + SomaDigitos(n);
    }     
}

int main () {
    int n = 0;

    scanf("%d", &n);
    
    printf("%d\n", SomaDigitos(n));

    return 0;
}