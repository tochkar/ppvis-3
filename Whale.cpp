

#include "Whale.h"

void Whale::die(vector<Whale>& whale, int pointer){
    if(age > lifeSpan || hungerCounter >= 10){
        whale.erase(whale.begin() + pointer);
    }
}

void Whale::reproduction(vector<Whale>& whales , int pointer){
    for(int i = 0; i < whales.size(); i++){
        if(pointer != i){
            if(checkReproductionPossibility(whales[i])){
                whales.push_back(*new Whale(x , y , damage , lifeSpan));
            }
        }
    }
};

void Whale::eat(vector<Plankton>& plankton){
    for(int i = 0; i< plankton.size(); i++){
        if(plankton[i].x == x && plankton[i].y == y){
            plankton.erase(plankton.begin() + i);
            hungerCounter = 0;
            return;
        }
    }
    hungerCounter += 2;
    return;
}
