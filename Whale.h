
#ifndef AL_WHALE_H
#define AL_WHALE_H

#include "Predator.h"
#include "Plankton.h"

using namespace std;

class Whale: public Predator{
public:
    Whale(int damage, int lifeSpan):Predator(damage, lifeSpan){}

    Whale(int x , int y , int damage , int lifeSpan):Predator(x , y , damage , lifeSpan){}

    void die(vector<Whale>& whale, int pointer);

    void reproduction(vector<Whale>& whales , int pointer);

    void eat(vector<Plankton>& plankton);
};


#endif //AL_WHALE_H
