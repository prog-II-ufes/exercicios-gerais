#ifndef __aluno
#define __aluno

/**
 * @brief Estrutura que representa um aluno da UFES.
 */
typedef struct aluno Aluno;

/**
 * @brief Cria um vetor de ponteiros para alunos, com espaço para numeroAlunos elementos.
 *
 * @param numeroAlunos - Quantidade de alunos que o vetor deve comportar
 *
 * @return Ponteiro para o vetor de alunos criado
 */
Aluno** CriaVetorAlunos(int numeroAlunos);

/**
 * @brief Cria um aluno com os dados passados como parâmetro.
 *
 * @param nome - Nome do aluno
 * @param dtNasc - Data de nascimento do aluno
 * @param cursoUfes - Curso do aluno na UFES
 * @param periodoIngresso - Período de ingresso do aluno
 * @param percConclusao - Porcentagem de conclusão do curso
 * @param CRA - Coeficiente de rendimento acadêmico
 *
 * @return Ponteiro para o aluno criado
 */
Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA);

/**
 * @brief Lê da entrada padrão os dados de numeroAlunos alunos, criando cada um deles e guardando-o no vetor.
 *
 * @param vetorAlunos - Vetor (já criado) onde os alunos serão guardados
 * @param numeroAlunos - Quantidade de alunos a serem lidos
 */
void LeAlunos(Aluno** vetorAlunos, int numeroAlunos);

/**
 * @brief Libera a memória de todos os alunos e do próprio vetor.
 *
 * @param alunos - Vetor de alunos a ser liberado
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void LiberaAlunos(Aluno** alunos, int numeroAlunos);

/**
 * @brief Salva o vetor de alunos em um arquivo binário e imprime a quantidade de bytes salvos
 * no formato "Numero de bytes salvos: X", seguido de uma quebra de linha.
 *
 *
 * @param alunos - Vetor de alunos a ser salvo
 * @param fileName - Nome do arquivo binário a ser criado
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos);

/**
 * @brief Lê os alunos de um arquivo binário criando cada um deles e guardando no vetor.
 *
 * @param alunos - Vetor (já criado, com espaço para todos os alunos do arquivo) onde os alunos serão guardados
 * @param fileName - Nome do arquivo binário a ser lido
 */
void CarregaAlunosBinario(Aluno **alunos, char *fileName);

/**
 * @brief Imprime os dados de todos os alunos do vetor.
 *
 * @param alunos - Vetor de alunos a ser impresso
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void ImprimeAlunos(Aluno** alunos, int numeroAlunos);


#endif