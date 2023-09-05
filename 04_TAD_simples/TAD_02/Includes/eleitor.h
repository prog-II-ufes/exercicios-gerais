#ifndef _ELEITOR_H
#define _ELEITOR_H

/**
 * @struct tEleitor
 * @brief Estrutura que representa um eleitor.
 * @var tEleitor::id
 * Identificador do eleitor.
 * @var tEleitor::votoP
 * Voto para Presidente.
 * @var tEleitor::votoM
 * Voto para Primeiro Ministro.
 */
typedef struct{
    int id;
    int votoP;
    int votoM;
} tEleitor;

/**
 * @brief Cria um eleitor.
 * @param id Identificador do eleitor.
 * @param votoP Voto para Presidente.
 * @param votoM Voto para Primeiro Ministro.
 * @return Retorna um eleitor.
 */
tEleitor criaEleitor(int id, int votoP, int votoM);

/**
 * @brief Verifica se o eleitor já votou.
 * @param eleitor Eleitor a ser verificado.
 * @param idAnterior Identificador do eleitor anterior.
 * @return Retorna 1 se o eleitor já votou e 0 caso contrário.
 */
int jaVotou(tEleitor eleitor, int idAnterior);

/**
* @brief Obtém o identificador do eleitor.
* @param eleitor Eleitor a ser verificado.
* @return Retorna o identificador do eleitor.
*/
int obtemIdEleitor(tEleitor eleitor);

/**
 * @brief Obtém o voto para Presidente.
 * @param eleitor Eleitor a ser verificado.
 * @return Retorna o voto para Presidente.
 */
int obtemVotoPresidente(tEleitor eleitor);

/**
 * @brief Obtém o voto para Primeiro Ministro.
 * @param eleitor Eleitor a ser verificado.
 * @return Retorna o voto para Primeiro Ministro.
 */
int obtemVotoPMinistro(tEleitor eleitor);

#endif