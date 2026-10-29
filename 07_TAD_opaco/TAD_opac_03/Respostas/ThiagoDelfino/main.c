#include"locadora.h"
#include<stdio.h>
#include<stdlib.h>


int main(){
    tLocadora *locadora;
    char opcao[MAX_CARACTERES];
    char indice;
    while(scanf("%s",opcao)==1){
        if(*opcao=='#'){
            break;
        }
        switch (*opcao){
    case 'C':
    LerCadastroLocadora(locadora);
        break;
    case 'A':
    LerAluguelLocadora(locadora);
        break;
    case 'D':
    LerDevolucaoLocadora(locadora);
        break;
    case 'E':
    ConsultarEstoqueLocadora(locadora);
        break;
    default:
        break;
    }
    }
    ConsultarLucroLocadora(locadora);
    return 0;
}