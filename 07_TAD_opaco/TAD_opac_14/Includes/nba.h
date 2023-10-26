#ifndef _nba
#define _nba

#define MAX_FR 10 // Número máximo de franquias
#define MAX_PT 10 // Número máximo de partidas
#define CAD_FRANQUIA 'F' // Caractere para cadastro de franquia
#define CAD_PARTIDA 'P' // Caractere para cadastro de partida
#define ENCERRAR 'E' // Caractere para encerrar a NBA


typedef struct nba * tNBA;

/**
 * @brief Cria uma nova instância da NBA.
 * 
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA();

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 * 
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba);

/**
 * @brief Imprime o relatório final da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba);

/**
 * @brief Libera a memória alocada para a instância da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba);

#endif