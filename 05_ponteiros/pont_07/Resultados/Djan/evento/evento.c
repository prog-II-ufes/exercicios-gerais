#include <stdio.h>

#define MAX_EVENTOS 10

//Estrutura para representar um evento no calendário. 
typedef struct {
    char nome[50]; // Nome do evento.
    int dia;       // Dia do evento.
    int mes;       // Mês do evento.
    int ano;       // Ano do evento.
} Evento;

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos >= MAX_EVENTOS){
        printf("Limite de eventos atingido!");
    }

    scanf(" %49[^\n]", eventos[*numEventos].nome);
    scanf("%d %d %d",&eventos[*numEventos].dia,
                     &eventos[*numEventos].mes,
                     &eventos[*numEventos].ano);

    (*numEventos)++; 
    
    printf("Evento cadastrado com sucesso!\n");
    //a variável que guarda a quantidade de eventos é realmente incrementada.
    //numeventos++ avança o ponteiro, não a quantidade de eventos.
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){
    int i;
    printf("Eventos cadastrados:\n");
    for(i = 0; i < *numEventos; i++){
        printf("%d - %s - %02d/%02d/%04d\n",i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int i;
    scanf("%d",&i);
    if(i >= 0 && i <= *numEventos-1){
        scanf("%d %d %d",&eventos[i].dia,&eventos[i].mes,&eventos[i].ano);
        printf("Data modificada com sucesso!\n");
    }
    //Sem os &, o scanf recebe os valores dos campos em vez dos endereços onde deve armazenar os novos valores.
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){

    if (*indiceA < 0 || *indiceA >= *numEventos ||
        *indiceB < 0 || *indiceB >= *numEventos) {
        printf("Indice invalido!\n");
        return;
    }

    Evento temp;

    temp = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = temp;
    
}
