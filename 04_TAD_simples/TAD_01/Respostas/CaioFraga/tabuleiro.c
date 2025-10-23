#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro t;
    t.peca1 = 'X';
    t.peca2 = '0';
    t.pecaVazio = '-';
    
    for (int i = 0; i < TAM_TABULEIRO; i++){
        for (int j = 0; j < TAM_TABULEIRO; j++){
            t.posicoes[i][j] = t.pecaVazio;
        }
    }

    return t;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if (PECA_1 == peca){
        if (EhPosicaoValidaTabuleiro(x, y)){
            
        } else {
            printf("");
        }

        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, x , y, peca)){

        } else {
            printf("");
        }

        
    } else if (PECA_2 == peca){

    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    for (int i = 0; i < TAM_TABULEIRO; i++){
        for (int j = 0; j < TAM_TABULEIRO; j++){
            if (tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if (peca == PECA_1){
        for (int i = 0; i < TAM_TABULEIRO; i++){
            for (int j = 0; j < TAM_TABULEIRO; j++){
                if (tabuleiro.posicoes[i][j] == tabuleiro.peca1){
                    return 1;
                }
            }
        }
    } else if (peca == PECA_2){
        for (int i = 0; i < TAM_TABULEIRO; i++){
            for (int j = 0; j < TAM_TABULEIRO; j++){
                if (tabuleiro.posicoes[i][j] == tabuleiro.peca2){
                    return 1;
                }
            }
        }
    }
    return 0;
}