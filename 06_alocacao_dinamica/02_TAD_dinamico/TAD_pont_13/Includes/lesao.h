#ifndef _lesao
#define _lesao

#define TAM_ID 10 /**< Tamanho máximo do identificador da lesão. */
#define TAM_DIAG 100 /**< Tamanho máximo do diagnóstico da lesão. */
#define TAM_REG 100 /**< Tamanho máximo da região do corpo da lesão. */

typedef struct lesao{
    char * id; /**< O identificador da lesão. */
    char * diagnostico; /**< O diagnóstico da lesão. */
    char * regiao_corpo; /**< A região do corpo da lesão. */
    int chance_malignidade; /**< A chance de malignidade da lesão. */
} tLesao;

/**
 * @brief Cria uma estrutura do tipo lesão
 * 
 * @return ponteiro para estrutura do tipo lesão
 */ 
tLesao* CriaLesao();

/**
 * @brief Lê informações sobre uma lesão da entrada padrão.
 * 
 * @param l ponteiro para lesão que terá seus dados preenchidos
 */
void LeLesao(tLesao* l);

/**
 * @brief Libera a memória alocada para uma estrutura de dados tLesao.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao a ser liberada.
 */
void LiberaLesao(tLesao* l);

/**
 * @brief Retorna o identificador da lesão.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna uma string contendo o identificador da lesão.
 */
char* GetIdLesao(tLesao* l);

/**
 * @brief Verifica se a lesão precisa de cirurgia.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna 1 se a lesão precisa de cirurgia e 0 caso contrário.
 */
int PrecisaCirurgiaLesao(tLesao* l);

#endif