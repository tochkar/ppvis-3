

#ifndef AL_COD_H
#define AL_COD_H

#include "Predator.h"
#include "Herring.h"
#include <vector>

using namespace std;

class Cod: public Predator{
public:
    Cod(int damage, int lifeSpan):Predator(damage, lifeSpan){}
    Cod(int x , int y , int damage , int lifeSpan):Predator(x , y , damage , lifeSpan){}

    void die(vector<Cod>& cod, int pointer);

    void reproduction(vector<Cod>& cods , int pointer);

    int findVictim(vector<Herring> herring);

    void eat(vector<Herring>& herring);
};


#endif //AL_COD_H
