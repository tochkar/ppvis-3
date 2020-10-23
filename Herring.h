
#ifndef AL_HERRING_H
#define AL_HERRING_H

#include "Predator.h"
#include "Plankton.h"
#include <vector>

using namespace std;

class Herring: public Predator{
public:
    Herring(int damage, int lifeSpan):Predator(damage, lifeSpan){}

    Herring(int x , int y , int damage , int lifeSpan):Predator(x , y , damage , lifeSpan){}

    void die(vector<Herring>& herring, int pointer);

    void reproduction(vector<Herring>& herrings , int pointer);

    void eat(vector<Plankton>& plankton);
};

#endif //AL_HERRING_H
