#include <stdio.h>
#include "aluno.h"

int main(){

    int nAlunos = 0, i, j; 
    tAluno aux;
    tAluno alunos[100];

    scanf("%d",&nAlunos);

    for(i = 0; i < nAlunos;i++){
        alunos[i] = LeAluno();
    }
   
    for(i = 0; i < nAlunos - 1; i++){
        for(j = 0; j < nAlunos - 1 - i; j++){

            if(ComparaMatricula(alunos[j], alunos[j + 1])>0){
                aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }

    for(i = 0; i < nAlunos; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }

    return 0;
}