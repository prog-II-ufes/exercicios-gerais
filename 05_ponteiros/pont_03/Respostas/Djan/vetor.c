#include <stdio.h>

/**
 * @brief Lê dados do usuário e armazena em um vetor.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e lê do usuário os valores a serem armazenados no vetor.
 * 
 * @param vet Ponteiro para o vetor que receberá os valores lidos.
 * @param tam Tamanho do vetor.
 */
void LeDadosParaVetor(int * vet, int tam){
    
    int i;
    
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
}

/**
 * @brief Imprime os dados de um vetor na tela.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e imprime na tela os valores armazenados no vetor.
 * 
 * @param n Ponteiro para o vetor a ser impresso.
 * @param tam Tamanho do vetor.
 */
void ImprimeDadosDoVetor(int * n, int tam){
    
    int i;
    
    for(i = 0; i < tam; i++){
        printf("%d ", n[i]);
    }
    printf("\n");

}

/**
 * @brief Troca o valor de duas variáveis se o segundo for menor que o primeiro.
 * 
 * 
 * Obs.: Essa função tem o comportamento de encontrar o menor valor no vetor vet de tamanho tam, 
 *  se esse valor for menor do que o valor apontado por paraTrocar, realiza uma troca. 
 *  Ao final da execução, a variável apontada por paraTrocar terá o menor valor encontrado no vetor vet.
 * 
 * @param vet Ponteiro para o vetor a ser percorrido.
 * @param tam Tamanho do vetor.
 * @param paraTrocar Ponteiro para a variável que armazenará o índice do menor valor encontrado.
 */
void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int i;
    //i = (*paraTrocar)posição 0 + 1 = posição 1, inicialmente;
    for(i = *paraTrocar + 1; i < tam; i++){
        if(vet[i] < vet[*paraTrocar]){ //primeiro caso: 100 < 11? Não, i++ vet[2], loop; 3 < 11? S, *paraTrocar = i(2);
                                        // vet[3] < vet[2], N, então o menor e 3; tudo volta e quem é para trocar e 3;
            *paraTrocar = i;
        }
    }
}

/**
 * @brief Ordena um vetor em ordem crescente.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e ordena os valores do vetor em ordem crescente.
 * 
 * @param vet Ponteiro para o vetor a ser ordenado.
 * @param tam Tamanho do vetor.
 */
void OrdeneCrescente(int * vet, int tam){
    
    int i, temp, menor;

    for(i = 0; i < tam; i++){
        
        menor = i;
        //chega vet, 4, 3;
        TrocaSeAcharMenor(vet, tam, &menor);

        //temp = vet[0](11);
        temp = vet[i];
        //vet[0] = vet[2], na segunda posição;
        vet[i] = vet[menor];
        //vet[2] = temp que é posição 0 que contém 11;
        vet[menor] = temp;
    
        //ficando: 3 100 11 7; e vai loop pois ainda não está crescente
        //saída correta: 3 7 11 100. 
    }
}