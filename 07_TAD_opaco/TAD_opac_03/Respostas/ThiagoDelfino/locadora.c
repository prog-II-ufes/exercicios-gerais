#include"locadora.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_FILMES 100

struct Locadora{
    tFilme **filmes;
    int lucro,qntdFilmes;
};


/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora (){
    tLocadora *locadora = (tLocadora*) calloc(1,sizeof(tLocadora));
    locadora->filmes=(tFilme**) calloc(MAX_FILMES,sizeof(tFilme*));
    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora){
    if(locadora!=NULL){
        for(int i=0;i<MAX_FILMES;i++){
            DestruirFilme(locadora->filmes[i]);
        }
        free(locadora->filmes);
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    for(int i;i<locadora->qntdFilmes;i++){
        if(ObterCodigoFilme(locadora->filmes[i])==codigo)
            return 1;
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    char indice;
    int i=0;
    while(scanf("%c",&indice)==1){
        if(indice=='#')
            break;
        int achou=0,cod;
        LeFilme(filme,cod);
        for(int i=0;i<locadora->qntdFilmes;i++){
            if(ObterCodigoFilme(locadora->filmes[i])==ObterCodigoFilme(filme)){
                achou=1;
                break;
            }
        }
        if(!achou){
            locadora->filmes[i]=filme;
            i++;
        }
    }
    locadora->qntdFilmes=i;
    realloc(locadora->filmes,locadora->qntdFilmes+1);
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora){
    tFilme *filme;
    CadastrarFilmeLocadora(Locadora,filme);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i=0; i<quantidadeCodigos;i++){
        for(int j=0;j<locadora->qntdFilmes;j++){
            if(ObterCodigoFilme(locadora->filmes[j])==codigos[i])
                if(ObterQtdEstoqueFilme(locadora->filmes[j])>0){
                    AlugarFilme(locadora->filmes[j]);
                    locadora->lucro+=ObterValorFilme(locadora->filmes[j]);
                }
        }
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int *codigo= (int*)calloc(1,sizeof(int)),qntdAlugar=1,i=1;
    char hastag;
    while(scanf("%c",&hastag)==1){
        if(hastag=='#')
            break;
        scanf("%d",&codigo[i]);
        qntdAlugar=i;
        i++;
        realloc(codigo,i);

    }
    AlugarFilmesLocadora(locadora,codigo,qntdAlugar);
    free(codigo);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i=0; i<quantidadeCodigos;i++){
        for(int j=0;j<locadora->qntdFilmes;j++){
            if(ObterCodigoFilme(locadora->filmes[j])==codigos[i])
                if(ObterQtdEstoqueFilme(locadora->filmes[j])>0)
                    DevolverFilme(locadora->filmes[j]);
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora){
    int *codigo= (int*)calloc(1,sizeof(int)),qntdDevolver=1,i=1;
    char hastag;
    while(scanf("%c",&hastag)==1){
        if(hastag=='#')
            break;
        scanf("%d",&codigo[i]);
        qntdDevolver=i;
        i++;
        realloc(codigo,i);

    }
    DevolverFilmesLocadora(locadora,codigo,qntdDevolver);
    free(codigo);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora){
    tFilme *FilmeAux;
    for(int i=0;i<locadora->qntdFilmes;i++){
        for(int j=i+1;j<locadora-i;j++){
            if(CompararNomesFilmes(locadora->filmes[i],locadora->filmes[j])==1){
                FilmeAux=locadora->filmes[i];
                locadora->filmes[i]=locadora->filmes[j];
                locadora->filmes[j]=FilmeAux;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora){
    printf("~Estoque~\n");
    for(int i=0;i<locadora->qntdFilmes;i++){
        printf("%d - ",i+1);
        ImprimirNomeFilme(locadora->filmes[i]);
    }
    printf("\n");
}
/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){
    printf("Lucro total R$%d\n",locadora->lucro);
    printf("\n");
}