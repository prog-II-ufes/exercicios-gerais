#ifndef _ARRAY_H_
#define _ARRAY_H_


/**
 * @brief Tipo opaco que representa um array que possui pelo menos os seguintes atributos:
 * o vetor de elementos (inteiros) e o seu tamanho.
 */
typedef struct Array tArray;


/**
 * @brief Cria um array vazio (sem elementos).
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tArray* Ponteiro para o array criado.
 */
tArray *CriarArray();


/**
 * @brief Libera a memória de um array.
 *
 * @param array Ponteiro para o array a ser destruído.
 */
void DestruirArray(tArray *array);

/**
 * @brief Lê os elementos do array da entrada padrão.
 * Os elementos são inteiros separados por espaço, e o último é seguido de um ponto final,
 * sem espaço. Ex.: "8 7 12 102 5 67." (6 elementos). A leitura termina no ponto final,
 * que também é consumido. Os elementos são todos diferentes entre si.
 *
 * @param array Ponteiro para o array a ser preenchido.
 */
void LerArray(tArray *array);

/**
 * @brief Ordena os elementos do array em ordem crescente.
 *
 * @param array Ponteiro para o array a ser ordenado.
 */
void OrdenarArray(tArray *array);

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * O array já deve estar ordenado (utilizando sua função apropriada). Os índices começam em 0.
 *
 * @param array Ponteiro para o array onde o elemento será buscado.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return int Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(tArray *array, int elementoBuscado);

#endif
