#ifndef _PESSOA_H_
#define _PESSOA_H_

typedef struct Pessoa tPessoa;

struct Pessoa{
    char nome[100];
    tPessoa *pai;
    tPessoa *mae;
};

/**
 * @brief Cria uma nova pessoa e inicializa os ponteiros.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa();

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa);

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa);

/**
 * @brief Associa as famílias e grupos de pessoas.
 * Alem disso, e nessa funcao que sera lida a associacao entre as pessoas.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas);

#endif