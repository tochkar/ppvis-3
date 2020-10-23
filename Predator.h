
#ifndef AL_PREDATOR_H
#define AL_PREDATOR_H

#include "Creature.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Predator: public Creature {
public:
    bool sex;
    int damage;
    int age;
    int hungerCounter;
    int lifeSpan;

    Predator(int damage, int lifeSpan);

    Predator(int x, int y, int damage, int lifeSpam);
    bool checkReproductionPossibility(Predator another);
    void moveForPredator(int step , vector<vector<int>>& map);
};


#endif //AL_PREDATOR_H
