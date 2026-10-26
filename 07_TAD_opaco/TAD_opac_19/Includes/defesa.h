#ifndef _defesa
#define _defesa

#define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
#define CIRCULO 'C' /**< Caractere que indica uma defesa do tipo círculo. */
#define MAX_NOME_DEFESA 100 /**< Tamanho do vetor para ler o nome da defesa: até 99 caracteres (+1 para o '\0'), sem espaços. */

/**
 * @brief Tipo opaco que representa uma defesa aérea que possui pelo menos os seguintes atributos:
 * nome, posição, tipo, poder de neutralização e quantidade de mísseis de defesa. 
 */
typedef struct Defesa tDefesa;

/**
 * @brief Lê uma defesa da entrada padrão.
 *
 * Assuma que a letra 'D' do início da linha já foi lida. Esta função lê o restante da
 * linha: o nome, as coordenadas x e y, o tipo (QUADRADO ou CIRCULO), o tamanho, o poder e
 * a quantidade de mísseis de defesa. 
 *
 * @return tDefesa* Ponteiro para a defesa criada. Quem chamou é responsável por
 *         liberá-la com LiberaDefesa.
 */
tDefesa* LeDefesa();

/**
 * @brief Imprime a defesa no formato "D-<nome>: <quantidade de mísseis de defesa>\n".
 *
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa* defesa);

/**
 * @brief Libera a memória alocada para a defesa.
 *
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa* defesa);

/**
 * @brief Verifica se um ponto está dentro da área de proteção da defesa (não verifica a
 * munição). Pontos exatamente sobre a borda da área NÃO estão protegidos.
 *
 * Dica:
 * O alcance da defesa é a distância do centro da defesa até o ponto mais distante que ela protege:
 * - CIRCULO: o alcance é o raio e o ponto está dentro se a distância até a defesa for
 *   menor que o tamanho.
 * - QUADRADO: o alcance tem os lados paralelos aos eixos e o tamanho é a distância do
 *   centro até um canto (metade da diagonal). A metade do lado é tamanho / sqrt(2), e o
 *   ponto está dentro se |x - X| e |y - Y| forem menores que a metade do lado.
 *
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa* defesa, float x, float y);

/**
 * @brief Consome um míssil de defesa (diminui a quantidade em 1).
 *
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa* defesa);

/**
 * @brief Obtém o poder de neutralização da defesa.
 *
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float ObtemPoderDefesa(tDefesa* defesa);

/**
 * @brief Verifica exclusivamente se a quantidade de mísseis de defesa é maior que zero.
 *
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa* defesa);

#endif
