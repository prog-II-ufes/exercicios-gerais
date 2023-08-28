#include <stdio.h>

int somaDigitos(unsigned int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + somaDigitos(n / 10);
    }
}

int main(int argc, char const *argv[])
{
    unsigned int n;

    scanf("%d", &n);

    printf("%d\n", somaDigitos(n));

    return 0;
}
