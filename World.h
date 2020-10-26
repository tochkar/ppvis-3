
#ifndef AL_WORLD_H
#define AL_WORLD_H

#include "Playground.h"
#include "FileUploading.h"
#include "Shark.h"
#include "Whale.h"



using namespace std;

class World: public Playground, FileUploading{
public:
    int year;
    vector<Shark> sharks;
    vector<Cod> cods;
    vector<Whale> whales;
    vector<Herring> herrings;
    vector<Plankton> planktons;
    vector<vector<int>> mapOfOccupation;

    void createMapOfOccupation();

    void mapNullifying();

    void createMap();

    int searchForSpace(int Row, int Column);

    void outputMap();

    World();

    void move();

    void eat();

    void die();

    void reproduction();

    void fillMapOfOccupation();

    void round();

    void manualMode();

};


#endif //AL_WORLD_H
