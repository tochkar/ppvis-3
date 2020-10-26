
#include "Playground.h"


void Playground::inicializationOfGameField(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gameField[i][j] = "    ";
        }
    }
}

Playground::Playground(){
    inicializationOfGameField();
}