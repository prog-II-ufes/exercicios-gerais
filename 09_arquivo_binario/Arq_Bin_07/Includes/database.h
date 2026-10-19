#if !defined(_DATABASE_H_)
#define _DATABASE_H_

typedef struct Database tDatabase;

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe, a função termina o programa.
 */
tDatabase *CriaDatabase();

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db);

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db);

/**
 * @brief Ordena uma database de acordo com o nome: os alunos entre si e os professores entre si.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db);

/**
 * @brief Salva uma database em um arquivo binário: um int com o número de alunos, os alunos, um int com o
 * número de professores e os professores.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file);

/**
 * @brief Carrega uma database de um arquivo binário, no mesmo formato gravado por SalvarDatabase.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file);

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores. Apenas os nomes são impressos, um por linha.
 * Antes dos alunos é impressa a linha "Alunos:" e, antes dos professores, uma linha em branco seguida da linha "Professores:".
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db);

#endif // _DATABASE_H_