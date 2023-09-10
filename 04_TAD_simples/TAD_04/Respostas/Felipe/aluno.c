#include "aluno.h"
#include <stdio.h>
#include <string.h>

tAluno criar_aluno(char *nome, int matricula, int n1, int n2, int n3) {
    tAluno aluno;

    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

int comparar_matricula_aluno(tAluno aluno1, tAluno aluno2) {
    if (aluno1.matricula > aluno2.matricula) {
        return 1;
    } else if (aluno1.matricula < aluno2.matricula) {
        return -1;
    } else {
        return 0;
    }
}

int calcular_media_aluno(tAluno aluno) {
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int aluno_aprovado(tAluno aluno) {
    return calcular_media_aluno(aluno) >= 7;
}

void imprimir_aluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}