#ifndef __aluno
#define __aluno

typedef struct aluno Aluno;

Aluno** CriaVetorAlunos(int numeroAlunos);

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA);

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos);

void LiberaAlunos(Aluno** alunos, int numeroAlunos);

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos);

void CarregaAlunosBinario(Aluno **alunos, char *fileName);

void ImprimeAlunos(Aluno** alunos, int numeroAlunos);


#endif