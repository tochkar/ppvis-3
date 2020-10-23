
#ifndef AL_SHARK_H
#define AL_SHARK_H

#include "Predator.h"
#include "Herring.h"
#include "Cod.h"

using namespace std;


class Shark: public Predator{
public:
    Shark(int damage, int lifeSpan):Predator(damage, lifeSpan){}
    Shark(int x , int y , int damage , int lifeSpan):Predator(x , y , damage , lifeSpan){}

    void die(vector<Shark>& shark, int pointer);

    void reproduction(vector<Shark>& sharks , int pointer);

    void eat(vector<Herring>& herring, vector<Cod>& cod);

    int findHerring(vector<Herring> herring);

    int findCod(vector<Cod> cod);

    void eatHerring(vector<Herring>& herring , int pointer);

    void eatCod(vector<Cod>& cod , int pointer);

};


#endif //AL_SHARK_H
