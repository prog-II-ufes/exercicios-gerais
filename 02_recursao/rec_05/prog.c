#include <stdio.h>

int Fatorial(int n) {
    int fat = 0;

    if(n == 1) {
        return 1;
    }
    else {
        fat = n * Fatorial(n-1);
        return fat;
    }

}

int main() {
    int num = 0, fat = 0;

    scanf("%d", &num);

    fat = Fatorial(num);

    printf("%d\n", fat);

    return 0;
}