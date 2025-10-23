#include <stdio.h>
#include "jogo.h"
#include "jogada.h"

int main(){

    tJogo j = CriaJogo();

    ComecaJogo(j);

    while (!AcabouJogo(j)){

    }

    if (ContinuaJogo(j)){
        
    }



    return 0;
}