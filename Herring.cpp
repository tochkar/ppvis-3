

#include "Herring.h"

void Herring::die(vector<Herring>& herring, int pointer){
    if(age > lifeSpan ||hungerCounter >= 10){
        herring.erase(herring.begin() + pointer);
    }
}

void Herring::reproduction(vector<Herring>& herrings , int pointer){
    for(int i = 0; i < herrings.size(); i++){
        if(pointer != i){
            if(checkReproductionPossibility(herrings[i])){
                herrings.push_back(*new Herring(x , y , damage , lifeSpan));
            }
        }
    }
}

void Herring::eat(vector<Plankton>& plankton){
    for(int i = 0; i< plankton.size(); i++){
        if(plankton[i].x == x && plankton[i].y == y){
            plankton[i].healthPoints = plankton[i].healthPoints- 50;
            hungerCounter=0;
            if(plankton[i].healthPoints <= 0) plankton[i].die(plankton, i);
            return;
        }
    }
    hungerCounter++;
    return;
}









