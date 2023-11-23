<<<<<<< HEAD
#if !defined(_ALUNO_H_)
#define _ALUNO_H_

#include <stdio.h>

/**
 * @brief Estrutura para representar um aluno.
 */
typedef struct Aluno tAluno;

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento);

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno);

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario);

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno);

#endif // _ALUNO_H_
=======
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
>>>>>>> e12992bdf671acfb8a105f20eb8a647a9ad6a1d4
