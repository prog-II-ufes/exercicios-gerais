#if !defined(CONTATO_H_)
#define CONTATO_H_

typedef struct Contato tContato;

/**
 * @brief Cria um novo contato.
 * 
 * @param nome Nome do contato.
 * @param telefone Telefone do contato.
 * @return tContato* Retorna um ponteiro para o contato criado. Caso não seja possível alocar memória, encerra o programa.
*/
tContato *CriarContato(char *nome, unsigned long int telefone);

/**
 * @brief Libera a memória alocada para um contato.
 * 
 * @param contato Ponteiro para o contato a ser liberado.
*/
void DestruirContato(tContato *contato);

/**
 * @brief Imprime as informações de um contato.
 * Formato de impressão:
 * Nome: <nome>
 * Telefone: <telefone>
 * 
 * @param contato Ponteiro para o contato a ser impresso.
*/
void ImprimirContato(tContato *contato);

/**
 * @brief Salva as informações de um contato em um arquivo binario.
 * 
 * @param contato Ponteiro para o contato a ser salvo.
 * @param arquivo Ponteiro para o arquivo binario onde o contato será salvo.
*/
void SalvarContato(tContato *contato, FILE *arquivo);

/**
 * @brief Le as informações de um contato da entrada padrão, primeiro lendo o nome e depois o telefone.
 * 
 * @return tContato* Retorna um ponteiro para o contato lido.
*/
tContato *LeContato();

/**
 * @brief Carrega as informações de um contato de um arquivo binario, primeiro lendo o nome e depois o telefone.
 * 
 * @param arquivo Ponteiro para o arquivo binario de onde o contato será carregado.
 * @return tContato* Retorna um ponteiro para o contato carregado.
*/
tContato *CarregarContato(FILE *arquivo);

/**
 * @brief Compara dois contatos pelo número de telefone.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os números de telefone dos contatos são iguais e 0 caso contrário.
*/
int ComparaTelefoneContato(tContato *c1, tContato *c2);

/**
 * @brief Compara dois contatos pelo nome.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os nomes dos contatos são iguais e 0 caso contrário.
*/
int ComparaNomeContato(tContato *c1, tContato *c2);

/**
 * @brief Retorna o número de telefone de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return unsigned long int Retorna o número de telefone do contato.
*/
unsigned long int GetTelefoneContato(tContato *contato);

/**
 * @brief Retorna o nome de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return char* Retorna o nome do contato.
*/
char *GetNomeContato(tContato *contato);

#endif // CONTATO_H_
