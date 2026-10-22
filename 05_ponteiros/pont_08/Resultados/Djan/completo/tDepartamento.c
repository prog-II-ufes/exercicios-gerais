#include <stdio.h>
#include <string.h>

#define STRING_MAX 50

typedef struct departamento {
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
} tDepartamento;

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor){
                                    tDepartamento depto;

                                    strcpy(depto.curso1,curso1);
                                    strcpy(depto.curso2,curso2);
                                    strcpy(depto.curso3,curso3);
                                    strcpy(depto.diretor,diretor);
                                    strcpy(depto.nome,nome);
                                    depto.m1 = m1; depto.m2 = m2; depto.m3 = m3;

                                    return depto;
                                }

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("\nDepartamento: %s\n",depto.nome);
    printf("    Diretor: %s\n",depto.diretor);
    printf("    1o curso: %s\n  Media do 1o curso: %d\n",depto.curso1,depto.m1);
    printf("    2o curso: %s\n  Media do 1o curso: %d\n",depto.curso2,depto.m2);
    printf("    3o curso: %s\n  Media do 1o curso: %d\n",depto.curso3,depto.m3);
    printf("    Media dos cursos: %.2f\n",(depto.m1+depto.m2+depto.m3)/3.0);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){

    int i, j, maior;
    tDepartamento temp;

    for (i = 0; i < num_deptos - 1; i++){
        maior = i;

        for(j = i + 1; j < num_deptos; j++){
            int somaAtual = vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3;
            int somaMaior = vetor_deptos[maior].m1 + vetor_deptos[maior].m2 + vetor_deptos[maior].m3;

            if(somaAtual > somaMaior){
                maior = j;
            }
        }

        temp = vetor_deptos[i];
        vetor_deptos[i] = vetor_deptos[maior];
        vetor_deptos[maior] = temp;
    }
}

/*1.maior = i: considera inicialmente que o departamento da posição i tem a maior média.
2.O segundo for percorre as posições seguintes, procurando um departamento com notas maiores.
3.Comparamos a soma das três notas, em vez da média, porque todos os departamentos têm três notas. 
Assim, comparar as somas dá o mesmo resultado que comparar as médias.
4.Ao encontrar o departamento com a maior soma, guardamos sua posição em maior.
5.No final, usamos temp para trocar os departamentos de posição. Como temp é do tipo tDepartamento, a troca preserva todos os dados do departamento.*/