
#ifndef AL_PLANKTON_H
#define AL_PLANKTON_H

#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "Creature.h"

using namespace std;

class Plankton: public Creature{
public:
    int countRound;

    void setCoordinates(int x, int y);

    bool searchCoordinates(vector<Plankton> plankton, int x, int y);

    Plankton(vector<Plankton>& plankton);

    Plankton(int x, int y);

    void move(int step, vector<Plankton>& plankton);

    bool findNeighbour(Plankton another);

    void reproduction(vector<Plankton>& plankton);

    void age(vector<Plankton>& plankton, int pointer);

    void die(vector<Plankton>& plankton, int pointer);
};


#endif //AL_PLANKTON_H
