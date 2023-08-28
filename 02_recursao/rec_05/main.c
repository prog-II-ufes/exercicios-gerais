#include <stdio.h>

int fatorial(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * fatorial(num - 1);
    }
}

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);

    printf("%d", fatorial(n));

    return 0;
}
