ObtemPrimo
int i;
    int encontrou = 0;

    for (i = m; i <= n; i++) {
        if (EhPrimo(i)) {
            if (!encontrou) {
                *menor = i;
                *maior = i;
                encontrou = 1;
            } else {
                if (i < *menor) {
                    *menor = i;
                }

                if (i > *maior) {
                    *maior = i;
                }
            }
        }
    }
}

int EhPrimo(int n) {
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

void ler(int *x) {
    scanf("%d", x);
}

não coloca & novamente, porque x já é um endereço.



    Estou passando uma variável ou um ponteiro?

Se for uma variável:

int x;
scanf("%d", &x);

Se for um ponteiro para int:

int *x;
scanf("%d", x);

Uma forma de memorizar:

scanf("%d", &variavel);
               ↑
            precisa do &

Mas:

scanf("%d", ponteiro);
              ↑
        já é um endereço

E cuidado com printf

Isso é diferente do printf.

Para imprimir o valor:

printf("%d", *x);

Para scanf:

scanf("%d", x);

Ou seja:

              scanf          printf
variável      &x             x
ponteiro      x              *x

Esse padrão de & na entrada e * na saída é uma ótima regra inicial para entender funções com ponteiros em C.
