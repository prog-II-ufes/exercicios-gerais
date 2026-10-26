#ifndef _missil
#define _missil

#define MAX_NOME_MISSIL 100 /**< Tamanho do vetor para ler o nome do míssil: até 99 caracteres (+1 para o '\0'), sem espaços. */

/**
 * @brief Tipo opaco que representa um míssil de ataque que possui pelo menos os seguintes atributos:
 *  nome, coordenadas e poder de ataque.
 */
typedef struct Missil tMissil;

/**
 * @brief Lê um míssil da entrada padrão.
 *
 * Assuma que a letra 'M' do início da linha já foi lida. Esta função lê o restante da
 * linha: o nome, as coordenadas x e y e o poder de ataque.
 *
 * @return tMissil* Ponteiro para o míssil criado. Quem chamou é responsável por
 *         liberá-lo com LiberaMissil.
 */
tMissil* LeMissil();

/**
 * @brief Imprime o míssil no formato "M-<nome>: <poder atual com 2 casas decimais>\n".
 * Depois de ProcessaAtaques, o poder atual é o dano que o míssil causou.
 *
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil* missil);

/**
 * @brief Libera a memória alocada para o míssil.
 *
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil* missil);

/**
 * @brief Obtém a coordenada y do míssil.
 *
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float ObtemYMissil(tMissil* missil);

/**
 * @brief Obtém a coordenada x do míssil.
 *
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float ObtemXMissil(tMissil* missil);

/**
 * @brief Obtém o poder de ataque atual do míssil.
 *
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float ObtemPoderMissil(tMissil* missil);

/**
 * @brief Reduz o poder de ataque do míssil. O poder nunca fica negativo: se o valor for
 * maior que o poder atual, o poder passa a ser 0.
 *
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil* missil, float valor);

#endif
