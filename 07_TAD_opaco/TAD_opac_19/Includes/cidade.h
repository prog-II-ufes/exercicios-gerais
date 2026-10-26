#ifndef _cidade
#define _cidade

#define ENCERRAR 'F' /**< Caractere que indica o fim da entrada. */
#define MISSIL 'M' /**< Caractere que indica um míssil. */
#define DEFESA 'D' /**< Caractere que indica uma defesa. */

/**
 * @brief Tipo opaco que representa uma cidade com pelo menos os atributos: seus limites (X e Y), 
 * as defesas aéreas e os mísseis de ataque. Não há limite para a quantidade de defesas ou de mísseis 
 * (os vetores devem crescer conforme a necessidade).
 */
typedef struct Cidade tCidade;

/**
 * @brief Lê a primeira linha da entrada, no formato "C X Y" (inclusive o caractere 'C'),
 * e cria uma nova cidade, ainda sem defesas e sem mísseis. A cidade ocupa a região
 * 0 <= x <= X e 0 <= y <= Y (a borda faz parte da cidade).
 *
 * Todos os campos da estrutura devem ser inicializados aqui. 
 *
 * @return tCidade* Ponteiro para a cidade criada. Quem chamou é responsável por
 *         liberá-la com LiberaCidade.
 */
tCidade* CriaCidade();

/**
 * @brief Lê as defesas e os mísseis da entrada padrão e os acrescenta à cidade, na ordem
 * da entrada, até ler o caractere ENCERRAR.
 *
 * Esta função lê o primeiro caractere de cada linha (DEFESA ou MISSIL) e chama LeDefesa
 * ou LeMissil para ler o restante da linha.
 *
 * @param cidade Ponteiro para a cidade que será preenchida.
 */
void LeEntrada(tCidade* cidade);

/**
 * @brief Libera a memória alocada para a cidade, inclusive as defesas e os mísseis.
 *
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade* cidade);

/**
 * @brief Processa os ataques na cidade, um míssil por vez, na ordem em que foram lidos.
 *
 * Para cada míssil:
 * - se ele cair fora da cidade, nenhuma defesa é usada e o dano causado pelo míssil é zero.
 * - se ele cair dentro da cidade, para cada defesa (na ordem em que foram lidas) que tenha
 *   munição e cuja área cubra o local atingido lança um míssil de defesa (gastando uma
 *   munição) e reduz o poder do míssil pelo seu poder de defesa.
 *   O poder do míssil que sobrar ao passar por todas as defesas é o dano causado na cidade.
 *
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void ProcessaAtaques(tCidade* cidade);

/**
 * @brief Imprime o relatório final na saída padrão. Imprime, nesta
 * ordem: uma linha por defesa, uma linha por míssil e a
 * linha "Efetividade: P%\n", onde P é o dano mitigado dividido pelo dano que o ataque
 * poderia causar (soma do poder inicial dos mísseis que caíram dentro da cidade), em %  e com duas casas decimais.
 * 
 *
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade* cidade);

#endif
