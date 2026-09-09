#include <stdio.h>
#include "aluno.h"

int main(){

    int nAlunos = 0, i, j; 
    tAluno aux;//uma estrutura auxiliar para trocar valores de estruturas.
    tAluno alunos[100];

    scanf("%d",&nAlunos);

    for(i = 0; i < nAlunos;i++){
        alunos[i] = LeAluno();
    }
   
    //Não estamos trocando apenas números; estamos trocando estruturas tAluno inteiras. Por isso aux também é do tipo tAluno:

    //ele para quando i >= nAlunos - 1
    for(i = 0; i < nAlunos - 1; i++){
        //alunos[0] com alunos[1],alunos[1] com alunos[2],alunos[2] com alunos[3]

        //Ele para quando j >= nAlunos - 1 - i
        for(j = 0; j < nAlunos - 1 - i; j++){
            //"Se a matrícula do aluno atual for maior que a matrícula do próximo, troque os dois."
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