#include<stdio.h>
#include"tDepartamento.h"


int main(){
    int nDepart;
    scanf("%d",&nDepart);
    tDepartamento *dept;
    char *curso1,*curso2,*curso3,*nome,*diretor;
    int m1,m2,m3;
    for(int i=0;i<nDepart;i++){
        int valido=0;
        while(valido==0){
            scanf("%s[^\n]\n",nome);
        scanf("%s[^\n]\n",diretor);
        scanf("%s[^\n]\n",curso1);
        scanf("%s[^\n]\n",curso2);
        scanf("%s[^\n]\n",curso3);
        scanf("%d %d %d",&m1,&m2,&m3);
        if(m1<0||m2<0||m3<0){
            printf("Digite um departamento com médias válidas\n");
        }
        else
            valido=1;
        }


    }
}