
#include "Plankton.h"

void Plankton::setCoordinates(int x, int y){
    this->x = x;
    this->y = y;
}

bool Plankton::searchCoordinates(vector<Plankton> plankton, int x, int y){
    for(int i = 0; i < plankton.size(); i++){
        if (x == plankton[i].x && y == plankton[i].y){
            return true;
        }
    }
    return false;
}

Plankton::Plankton(vector<Plankton>& plankton){
    countRound = 0;
    int x , y;
    do {
        x = rand() % 10;
        y = rand() % 10;
    }while (searchCoordinates(plankton, x, y));
    setCoordinates(x, y);
}

Plankton::Plankton(int x, int y){
    countRound = 0;
    this->x = x;
    this->y = y;
}

void Plankton::move(int step, vector<Plankton>& plankton){
    vector<bool> directions = {false , false , false , false};
    srand(time(NULL));
    int direction = rand() % 4, x = this->x, y = this->y;
    while(find(directions.begin(), directions.end(), false) != directions.end()){
        if (direction == 0 && x + step < 10) x += step; //right
        else if (direction == 1 && x - step > -1) x -= step; //left
        else if (direction == 2 && y + step < 10) y += step; //up
        else if (y - step > -1) y -= step;//down
        directions[direction] = true;
        if(!searchCoordinates(plankton, x, y)){
            setCoordinates(x,y);
            return;
        }
        if(direction < 3)direction++; else direction = 0;
    }
    return;
}

bool Plankton::findNeighbour(Plankton another){
    if((abs(x - another.x) == 1 && abs(y - another.y == 0)) || (abs(x - another.x) == 0 && abs(y - another.y == 1))) return true; else return false;
}

void Plankton::reproduction(vector<Plankton>& plankton){
    if(countRound != 4){
        countRound++;
        return ;
    }
    countRound = 0;
    for(int i = 0; i < plankton.size(); i++){
        if (this->findNeighbour(plankton[i])){
            plankton[i].healthPoints = 100;
            return;
        }
    }
    int x1 = 0 , y1 = 0;
    if (this->x < 8){
        x1 = this->x + 1;
    }else if (this->y < 8){
        y1 = this->y + 1;
    } else y1 = this->y - 1;
    if(x1 == 0){
        plankton.push_back(*new Plankton(x , y1));
    }else{
        plankton.push_back(*new Plankton(x1 , y));
    }
    return;
}

void Plankton::age(vector<Plankton>& plankton, int pointer){
    healthPoints -= 10;
    if(plankton[pointer].healthPoints <= 0)
        plankton[pointer].die(plankton, pointer);
    return;
}

void Plankton::die(vector<Plankton>& plankton, int pointer){
    plankton.erase(plankton.begin() + pointer);
    return;
}

