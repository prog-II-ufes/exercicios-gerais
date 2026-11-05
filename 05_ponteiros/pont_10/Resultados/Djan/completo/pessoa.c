#include <stdio.h>
#include <string.h>

typedef struct Pessoa tPessoa;

struct Pessoa{
    char nome[100];
    tPessoa *pai;
    tPessoa *mae;
    tPessoa *irmao;
};

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa(){
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;

    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){
    scanf(" %99[^\n]",pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    return pessoa->pai != NULL || pessoa->mae != NULL;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){
    if(!VerificaSeTemPaisPessoa(pessoa)){
        return;
    }

    printf("NOME COMPLETO: %s\n", pessoa->nome);

    if(pessoa->pai != NULL) {
        printf("PAI: %s\n", pessoa->pai->nome);
    }else{
        printf("PAI: NAO INFORMADO\n");
    }

    if(pessoa->mae != NULL){
        printf("MAE: %s\n", pessoa->mae->nome);
    }else{
        printf("MAE: NAO INFORMADO\n");
    }

    if(pessoa->irmao != NULL){
        printf("IRMAO: %s\n\n", pessoa->irmao->nome);
    }else{
        printf("IRMAO: NAO INFORMADO\n\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){

    if(pessoa1->pai == NULL && pessoa1->mae == NULL){
        return 0;
    }    

    if(pessoa1->pai == pessoa2->pai && pessoa1->mae == pessoa2->mae){
        return 1;
    }else{
        return 0;
    }

}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    
    int numAssociacoes, i, j;
    int indiceMae, indicePai, indiceFilho;

    // 1. Ler a quantidade de associações
    scanf("%d", &numAssociacoes);

    // 2. Associar os pais aos filhos
    for (i = 0; i < numAssociacoes; i++) {
        scanf(" mae: %d, pai: %d, filho: %d",
              &indiceMae, &indicePai, &indiceFilho);

        if (indiceMae == -1) {
            pessoas[indiceFilho].mae = NULL;
        } else {
            pessoas[indiceFilho].mae = &pessoas[indiceMae];
        }

        if (indicePai == -1) {
            pessoas[indiceFilho].pai = NULL;
        } else {
            pessoas[indiceFilho].pai = &pessoas[indicePai];
        }
    }

    // 3. Procurar irmãos
    for (i = 0; i < numPessoas; i++) {
        for (j = 0; j < numPessoas; j++) {

            if (i != j &&
                VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) &&
                (pessoas[i].pai != NULL || pessoas[i].mae != NULL)) {

                pessoas[i].irmao = &pessoas[j];
                break;
            }
        }
    }
}