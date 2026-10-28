#ifndef _ALUNO_H_
#define _ALUNO_H_

/**
 * @brief Tamanho do vetor usado para ler o nome do aluno: até 49 caracteres (+1 para o '\0').
 */
#define MAX_NOME 50

/**
 * @brief Tipo opaco que representa um aluno com pelo menos os seguintes atributos: 
 * nome, matrícula e as três notas.
 */
typedef struct Aluno tAluno;

/**
 * @brief Cria um novo aluno vazio.
 * Todos os campos da estrutura devem ser inicializados aqui; os dados do aluno são preenchidos
 * depois, por LeAluno.
 * 
 * @return tAluno* Ponteiro para o aluno criado.
 */
tAluno* CriaAluno(); 

/**
 * @brief Libera a memória de um aluno.
 * 
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno);


/**
 * @brief Lê os dados de um aluno da entrada padrão, em três linhas: o nome, a
 * matrícula e as três notas (inteiros de 0 a 10, separados por espaço).
 * 
 * @param aluno Ponteiro para aluno, cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Compara as matrículas de dois alunos.
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2);

/**
 * @brief Calcula a média aritmética das três notas de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return float Retorna a média das notas do aluno.
 */
float CalculaMediaAluno(tAluno* aluno);

/**
 * @brief Verifica se um aluno foi aprovado (média maior ou igual a 7) ou reprovado.
 * 
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno* aluno);

/**
 * @brief Imprime APENAS o nome do aluno, seguido de quebra de linha. Ex.: "Maria\n".
 * 
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno* aluno);

#endif
