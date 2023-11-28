#if !defined(_MOVEL_H_)
#define _MOVEL_H_

/**
 * @brief Estrutura representando um Movel.
 */
typedef struct Movel tMovel;

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome);

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m);

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel();

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m);

#endif // _MOVEL_H_