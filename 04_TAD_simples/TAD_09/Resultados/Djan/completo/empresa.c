#include <stdio.h>
#include "funcionario.h"

typedef struct empresa {
    int id;
    tFuncionario funcionarios[20];
    int qtdFuncionarios;
} tEmpresa;

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id){
    tEmpresa e;

    e.id = id;
    e.qtdFuncionarios = 0;

    return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    tEmpresa e;

    int i, qtdFuncionarios;

    scanf("%d %d",&e.id,&qtdFuncionarios);
    
    for(i = 0; i < qtdFuncionarios; i++){
        leFuncionario();
    }
    
    e.qtdFuncionarios = 0;

    return e;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    
    int i;

    for(i = 0; i < empresa.qtdFuncionarios; i++) {
        if(empresa.funcionarios[i].id == funcionario.id) {
            return empresa; 
        }
    }

    if(empresa.qtdFuncionarios < 20) {
        // Armazena o funcionário pronto na vaga livre
        empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
        
        empresa.qtdFuncionarios++;
    }

    return empresa;

}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){
    
    int i;

    printf("Empresa %d:\n",empresa.id);
    
    for(i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }

}