#ifndef _depto
#define _depto

#define STRING_MAX 101 // número máximo de caracteres por string

typedef struct Departamento {
    char *nome;     // nome do departamento
    char *c1, *c2, *c3;    // nomes dos cursos do departamento
    int m1, m2, m3;     // médias de notas dos cursos do departamento
    char *diretor;    // nome do diretor do departamento
    float media_geral;
} tDepartamento;

/**
 * @brief Cria uma estrutura, alocada dinamicamente, que possui os campos de um departamento. 
 * Lembre-se de inicializar os ponteiros com NULL e as variáveis númericas com -1.
 * 
 * @return Um ponteiro para uma estrutura de um Departamento.
 */
tDepartamento* CriaDepartamento();

/**
 * @brief Preenche os dados de uma estrutura departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 */
void PreencheDadosDepartamento(tDepartamento* depto, char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor);

void LiberaMemoriaDepartamento(tDepartamento* depto);


/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void ImprimeAtributosDepartamento (tDepartamento* depto);

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int ValidaMediaDepartamento (int media);

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double CalculaDesvioPadraoDepartamento(tDepartamento* depto);

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double CalculaMediaGeralDepartamento(tDepartamento* depto);

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param deptos Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void OrdenaPorMediaDepartamentos(tDepartamento* d[], int tamanho);

#endif
