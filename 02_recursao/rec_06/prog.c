#include <stdio.h>

int Fibonacci(int n) {
    int n1 = 0, n2 = 0, n_esimo = 0;

    if(n == 1) return 0;
    else if(n == 2 || n == 3) return 1;
    else{
        n1 = Fibonacci(n - 2);
        n2 = Fibonacci(n - 1);
        n_esimo = n1 + n2;
    }
}

int main () {
    int n = 0;

    scanf("%d", &n);
    n++;
    n = Fibonacci(n);
    printf("%d\n", n);

    return 0;
}