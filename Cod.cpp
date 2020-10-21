
#include "Cod.h"

void Cod::die(vector<Cod>& cod, int pointer){
    if(age > lifeSpan || hungerCounter >= 10){
        cod.erase(cod.begin() + pointer);
    }
}

void Cod::reproduction(vector<Cod>& cods , int pointer){
    for(int i = 0; i < cods.size(); i++){
        if(pointer != i){
            if(checkReproductionPossibility(cods[i])){
                cods.push_back(*new Cod(x , y , damage , lifeSpan));
            }
        }
    }
}

int Cod::findVictim(vector<Herring> herring){
    for(int i = 0; i < herring.size(); i++){
        if(herring[i].x == x && herring[i].y == y && (herring[i].healthPoints < 80 || herring[i].age > 2)){
            return i;
        }
    }
    return -1;
}

void Cod::eat(vector<Herring>& herring){
    int indexOfVictim = findVictim(herring);
    if(indexOfVictim != -1) {
        herring.erase(herring.begin() + indexOfVictim);
        hungerCounter = 0;
        return;
    }
    hungerCounter += 1;
    return;
}




