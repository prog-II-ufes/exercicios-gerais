#if !defined(_ALUNO_H_)
#define _ALUNO_H_


typedef struct Aluno tAluno;

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento);

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno);

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno();

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2);

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file);

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file);

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno);

#endif // _ALUNO_H_