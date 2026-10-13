#include<stdio.h>
#include"tDepartamento.h"
#include<string.h>



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
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento d;
    strcpy(d.curso1,curso1);
    strcpy(d.curso2,curso2);
    strcpy(d.curso3,curso3);
    strcpy(d.diretor,diretor);
    strcpy(d.nome,nome);
    d.m1=m1;
    d.m2=m2;
    d.m3=m3;
    return d;

}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    /*Departamento: Informatica
	Diretor: Patricia
	1o curso: CC
	Media do 1o curso: 10
	2o curso: EC
	Media do 2o curso: 7
	3o curso: SI
	Media do 3o curso: 5
	Media dos cursos: 7.33
    */
   printf("Departamento: %s\n",depto.nome);
   printf(" Diretor: %s",depto.diretor);
   printf(" 1o curso: %s",depto.curso1);
   printf(" Media do 1o curso %d\n",depto.m1);
   printf(" 2o curso: %s",depto.curso2);
   printf(" Media do 2o curso %d\n",depto.m2);
   printf(" 3o curso %s",depto.curso3);
   printf(" Media do 3o curso %d\n",depto.m3);
   printf(" Media dos curso: %.2f",(float)(depto.m1+depto.m2+depto.m3)/3);

}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    tDepartamento dep1,dep2;
    for(int i=0;i<num_deptos;i++){
        for(int j=i+1;j<num_deptos;j++){
            dep1=vetor_deptos[i];
            dep2=vetor_deptos[j];
            float media1, media2;
            media1=(float)(dep1.m1+dep1.m2+-dep1.m3)/3;
            media2=(float)(dep2.m1+dep2.m2+-dep2.m3)/3;
            if(media1<media2){
                vetor_deptos[i]=dep2;
                vetor_deptos[j]=dep1;
            }
        }
    }
}
