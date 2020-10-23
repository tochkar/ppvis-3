#include "Predator.h"

Predator::Predator(int damage, int lifeSpan){
    sex = rand() % 2;
    this->damage = damage;
    this->lifeSpan = lifeSpan;
    this->age = 0;
    x = rand() % 10;
    y = rand() % 10;
    hungerCounter = 0;
}

Predator::Predator(int x, int y, int damage, int lifeSpam){
    sex = rand() % 2;
    this->damage = damage;
    this->x = x;
    this->y = y;
    hungerCounter = 0;
}

bool Predator::checkReproductionPossibility(Predator another){
    return (sex != another.sex && x == another.x && y == another.y);
}

void Predator::moveForPredator(int step, vector<vector<int>>& map){
    vector<bool> directions = {false , false , false , false};
    map[x][y]--;
    age++;
    int right = 0, left = 1, up = 2, down = 3;
    int direction = rand() % 4, x = this->x, y = this->y;
    while(find(directions.begin(), directions.end(), false) != directions.end()){
        if (direction == right && x + step < 10) x += step; //right
        else if (direction == left && x - step > -1) x -= step; //left
        else if (direction == up && y + step < 10) y += step; //up
        else if (direction == down && y - step > -1) y -= step;//down
        directions[direction] = true;
        if(direction < 3)direction++; else direction = 0;
        if(this->y == y){
            continue;
        }
        if(map[x][y] < 4){
            map[x][y]++;
            this->x = x;
            this->y = y;
            return;
        }else{
            x = this->x;
            y = this->y;
        }
    }
    map[x][y]++;
    return;
}









