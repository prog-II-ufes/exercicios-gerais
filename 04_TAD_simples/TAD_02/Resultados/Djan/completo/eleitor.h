#ifndef _ELEITOR_H_
#define _ELEITOR_H_

typedef struct{
    int id;
    int votoP;
    int votoG;
} tEleitor;

/**
 * @brief Cria um eleitor com os dados informados.
 * @param id Identificador do eleitor.
 * @param votoP Voto para presidente do eleitor.
 * @param votoG Voto para governador do eleitor.
 * @return Eleitor criado.
 */
tEleitor CriaEleitor(int id, int votoP, int votoG);

/**
 * @brief Lê um eleitor do teclado.
 * @return Eleitor lido.
 */
tEleitor LeEleitor();

/**
 * @brief Obtém o voto para presidente do eleitor.
 * @param eleitor Eleitor a ser verificado.
 * @return Voto para presidente do eleitor.
 */
int ObtemVotoPresidente(tEleitor eleitor);

/**
 * @brief Obtém o voto para governador do eleitor.
 * @param eleitor Eleitor a ser verificado.
 * @return Voto para governador do eleitor.
 */
int ObtemVotoGovernador(tEleitor eleitor);

/**
 * @brief Verifica se dois eleitores são iguais (dica: use para verificar se algum eleitor tentou registar um voto novamente).
 * @param eleitor1 Primeiro eleitor a ser comparado.
 * @param eleitor2 Segundo eleitor a ser comparado.
 * @return 1 se os eleitores são iguais, 0 caso contrário.
 */
int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2);

#endif