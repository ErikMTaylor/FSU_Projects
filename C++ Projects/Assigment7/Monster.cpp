#include "Monster.h"
#include <random>
using namespace std;

Monster::Monster(){
    srand(time(0));
    health = rand()%16 + 15;
    power = rand()%6 + 1;
}

int Monster::getPower() const {
    return power;
}

int Monster::getHealth() const{
    return health;
}

void Monster::setPower(int given) {
    power = given;
}

void Monster::setHealth(int given) {
    health = given;
}