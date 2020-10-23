
#include "Shark.h"

void Shark::die(vector<Shark>& shark, int pointer){
    if(age > lifeSpan || hungerCounter >= 10){
        shark.erase(shark.begin() + pointer);
    }
}

void Shark::reproduction(vector<Shark>& sharks , int pointer){
    for(int i = 0; i < sharks.size(); i++){
        if(pointer != i){
            if(checkReproductionPossibility(sharks[i])){
                sharks.push_back(*new Shark(x , y , damage , lifeSpan));
            }
        }
    }
}

void Shark::eat(vector<Herring>& herring, vector<Cod>& cod){
    int indexOfVictm;
    indexOfVictm = findHerring(herring);
    if(indexOfVictm != -1){
        eatHerring(herring , indexOfVictm);
        return;
    }
    indexOfVictm = findCod(cod);
    if(indexOfVictm != -1){
        eatCod(cod , indexOfVictm);
        return;
    }
    hungerCounter+=2;
}

int Shark::findHerring(vector<Herring> herring){
    for(int i = 0; i < herring.size(); i++){
        if(herring[i].x == x && herring[i].y == y){
            return i;
        }
    }
    return -1;
}

int Shark::findCod(vector<Cod> cod){
    for(int i = 0; i < cod.size(); i++){
        if(cod[i].x == x && cod[i].y == y){
            return i;
        }
    }
    return -1;
}

void Shark::eatHerring(vector<Herring>& herring , int pointer){
    herring.erase(herring.begin() + pointer);
    hungerCounter=0;
    return;
};

void Shark::eatCod(vector<Cod>& cod , int pointer){
    cod.erase(cod.begin() + pointer);
    hungerCounter=0;
    return;
};

