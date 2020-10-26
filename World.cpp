

#include "World.h"

void World::createMapOfOccupation(){
    for(int i = 0; i < 10; i++){
        vector<int> temp;
        for(int j = 0; j < 10; j++){
            temp.push_back(0);
        }
        mapOfOccupation.push_back(temp);
    }
}

void World::mapNullifying(){
    for(int i = 0; i < mapOfOccupation.size(); i++){
        for(int j = 0; j < 10; j++){
            mapOfOccupation[i][j] = 0;
        }
    }
}

void World::createMap(){
    inicializationOfGameField();

    for(int i = 0; i < planktons.size(); i++){
        gameField[planktons[i].x][planktons[i].y][0] ='P';
    }
    for(int i = 0; i < sharks.size(); i++){
        int pointer = searchForSpace(sharks[i].x, sharks[i].y);
        if(pointer != -1) gameField[sharks[i].x][sharks[i].y][pointer] ='S';
    }
    for(int i = 0; i < whales.size(); i++){
        int pointer = searchForSpace(whales[i].x, whales[i].y);
        if(pointer != -1)gameField[whales[i].x][whales[i].y][pointer] ='W';
    }
    for(int i = 0; i < cods.size(); i++){
        int pointer = searchForSpace(cods[i].x, cods[i].y);
        if(pointer != -1)gameField[cods[i].x][cods[i].y][pointer] ='C';
    }
    for(int i = 0; i < herrings.size(); i++){
        int pointer = searchForSpace(herrings[i].x, herrings[i].y);
        if(pointer != -1)gameField[herrings[i].x][herrings[i].y][pointer] ='H';
    }

    outputMap();
}

int World::searchForSpace(int Row, int Column){
    return gameField[Row][Column].find(' ');
}

void World::outputMap(){
    cout << "YEAR : " << year << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << gameField[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "Plankton : " << planktons.size() << endl;
    cout << "Whale : " << whales.size() << endl;
    cout << "Herring : " << herrings.size() << endl;
    cout << "Cod : " << cods.size() << endl;
    cout << "Shark : " << sharks.size() << endl;
}

World::World(){
    year = 0;
    srand(time(NULL));
    int amount = rand() % 40 + 10;
    for (int i = 0; i < amount; i++) {
        Plankton plankton(planktons);
        planktons.push_back(plankton);
    }
    amount = rand() % 20 + 10;
    for (int i = 0; i < amount; i++) {
        Herring herring(FILE[classHerringDefine()].damage, FILE[classHerringDefine()].age);
        herrings.push_back(herring);
    }
    amount = rand() % 20 + 10;
    for (int i = 0; i < amount; i++) {
        Whale whale(FILE[classWhaleDefine()].damage, FILE[classWhaleDefine()].age);
        whales.push_back(whale);
    }
    amount = rand() % 20 + 10;
    for (int i = 0; i < amount; i++) {
        Cod cod(FILE[classCodDefine()].damage, FILE[classCodDefine()].age);
        cods.push_back(cod);
    }
    amount = rand() % 20 + 10;
    for (int i = 0; i < amount; i++) {
        Shark shark(FILE[classSharkDefine()].damage, FILE[classSharkDefine()].age);
        sharks.push_back(shark);
    }

    createMap();
    createMapOfOccupation();
}

void World::move(){
    for(int i = 0; i < planktons.size(); i++){
        planktons[i].move(FILE[classPlanktonDefine()].step , planktons);
    }
    for(int i = 0; i < herrings.size(); i++){
        herrings[i].moveForPredator(FILE[classHerringDefine()].step , mapOfOccupation);
    }
    for(int i = 0; i < cods.size(); i++){
        cods[i].moveForPredator(FILE[classCodDefine()].step , mapOfOccupation);
    }
    for(int i = 0; i < sharks.size(); i++){
        sharks[i].moveForPredator(FILE[classSharkDefine()].step , mapOfOccupation);
    }
    for(int i = 0; i < whales.size(); i++){
        whales[i].moveForPredator(FILE[classWhaleDefine()].step , mapOfOccupation);
    }
}

void World::eat(){
    for(int i = 0; i < sharks.size(); i++){
        sharks[i].eat(herrings, cods);
    }
    for(int i = 0; i < cods.size(); i++){
        cods[i].eat(herrings);
    }
    for(int i = 0; i < herrings.size(); i++){
        herrings[i].eat(planktons);
    }
    for(int i = 0; i < whales.size(); i++){
        whales[i].eat(planktons);
    }
}

void World::die(){
    for(int i = 0; i < planktons.size(); i++){
        planktons[i].age(planktons, i);
    }
    for(int i = 0; i < herrings.size(); i++){
        herrings[i].die(herrings, i);
    }
    for(int i = 0; i < cods.size(); i++){
        cods[i].die(cods, i);
    }
    for(int i = 0; i < sharks.size(); i++){
        sharks[i].die(sharks, i);
    }
    for(int i = 0; i < whales.size(); i++){
        whales[i].die(whales, i);
    }
}

void World::reproduction(){
    int size = planktons.size();
    for (int i = 0; i < size; i++) {
        planktons[i].reproduction(planktons);
    }
    size = whales.size();
    for (int i = 0; i < size; i++) {
        if(mapOfOccupation[whales[i].x][whales[i].y] < 4) whales[i].reproduction(whales , i);
    }

    size = sharks.size();
    for (int i = 0; i < size; i++) {
        if(mapOfOccupation[sharks[i].x][sharks[i].y] < 4) sharks[i].reproduction(sharks , i);
    }

    size = cods.size();
    for (int i = 0; i < size; i++) {
        if(mapOfOccupation[cods[i].x][cods[i].y] < 4) cods[i].reproduction(cods , i);
    }

    size = herrings.size();
    for (int i = 0; i < size; i++) {
        if(mapOfOccupation[herrings[i].x][herrings[i].y] < 4)herrings[i].reproduction(herrings , i);
    }
}

void World::fillMapOfOccupation(){
    for(int i = 0; i < planktons.size(); i++){
        mapOfOccupation[planktons[i].x][planktons[i].y]++;
    }
    for(int i = 0; i < herrings.size(); i++){
        mapOfOccupation[herrings[i].x][herrings[i].y]++;
    }
    for(int i = 0; i < cods.size(); i++){
        mapOfOccupation[cods[i].x][cods[i].y]++;
    }
    for(int i = 0; i < sharks.size(); i++){
        mapOfOccupation[sharks[i].x][sharks[i].y]++;
    }
    for(int i = 0; i < whales.size(); i++){
        mapOfOccupation[whales[i].x][whales[i].y]++;
    }
}

void World::round(){
    mapNullifying();
    fillMapOfOccupation();
    this->year++;
    eat();
    die(); //+
    reproduction();
    move(); //+
}

void World::manualMode(){
    while(true){
        string check;
        while(check != "exit" && check != "\n") check += getchar();
        if(check == "exit") break;
        cout << string(30 , '\n');
        round();
        createMap();
    }
}
