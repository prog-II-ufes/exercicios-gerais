#ifndef _nba
#define _nba

#define CAD_FRANQUIA 'F' // Caractere para cadastro de franquia
#define CAD_PARTIDA 'P' // Caractere para cadastro de partida
#define ENCERRAR 'E' // Caractere para encerrar a NBA

/**
 * @brief Tipo opaco que representa o campeonato: as franquias e as partidas cadastradas.
 * Não há limite para a quantidade de franquias ou de partidas 
 * (os vetores devem crescer conforme a necessidade).
 */
typedef struct Nba tNBA;

/**
 * @brief Cria um campeonato vazio (sem franquias e sem partidas).
 *
 * Todos os campos da estrutura devem ser inicializados aqui. Em particular, as listas
 * (vetores de ponteiros) de franquias e de partidas começam vazias: o ponteiro de cada
 * lista deve valer NULL e a quantidade de elementos de cada lista deve valer 0.
 * Como realloc(NULL, tamanho) funciona como malloc(tamanho), a primeira inserção
 * pode usar realloc normalmente.
 *
 * @return tNBA* Ponteiro para o campeonato criado. 
 */
tNBA* CriaNBA();

/**
 * @brief Lê toda a entrada padrão, cadastrando as franquias e processando as partidas,
 * até ler o caractere ENCERRAR.
 *
 * Esta função lê o caractere de cada linha (CAD_FRANQUIA ou CAD_PARTIDA) e chama
 * LeFranquia ou LePartida para ler o restante da linha. Pode-se assumir que as partidas
 * só citam times já cadastrados. O campeonato passa a ser responsável por liberar as
 * franquias e as partidas lidas.
 *
 * @param nba Ponteiro para o campeonato.
 */
void RodaNBA(tNBA* nba);

/**
 * @brief Imprime o relatório final do campeonato: uma linha por franquia, na ordem de
 * cadastro (ver ImprimeFranquia), seguida de uma linha para cada conferência, sempre
 * nesta ordem e mesmo que a conferência não tenha nenhum time:
 * "LESTE V D APR\n" e "OESTE V D APR\n" (V e D são as somas das vitórias e das derrotas
 * dos times da conferência e APR é o aproveitamento em %, inteiro, calculado como em
 * ImprimeFranquia: (V * 100) / (V + D) com divisão inteira, 0 se não houve jogos).
 *
 * @param nba Ponteiro para o campeonato.
 */
void ImprimeRelatorioNBA(tNBA* nba);

/**
 * @brief Libera a memória alocada para o campeonato, inclusive as franquias e as partidas.
 *
 * @param nba Ponteiro para o campeonato a ser liberado.
 */
void LiberaNBA(tNBA* nba);

#endif
