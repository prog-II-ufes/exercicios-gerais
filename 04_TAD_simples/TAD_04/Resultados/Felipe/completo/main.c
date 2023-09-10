#include <stdio.h>
#include "aluno.h"

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);

    tAluno alunos[n];

    for (int i = 0; i < n; i++) {
        char nome[50];
        int matricula;
        int n1, n2, n3;

        scanf("%s", nome);
        scanf("%d", &matricula);
        scanf("%d %d %d", &n1, &n2, &n3);

        alunos[i] = criar_aluno(nome, matricula, n1, n2, n3);
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (comparar_matricula_aluno(alunos[j], alunos[min_idx]) == -1) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            tAluno aux = alunos[i];
            alunos[i] = alunos[min_idx];
            alunos[min_idx] = aux;
        }
    }

    for (int i = 0; i < n; i++) {
        if (aluno_aprovado(alunos[i])) {
            imprimir_aluno(alunos[i]);
        }
    }

    return 0;
}
