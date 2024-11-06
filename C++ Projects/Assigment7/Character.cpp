#include "Character.h"
#include <random>
using namespace std;

Character::Character(){
    srand(time(0));
    health = rand()%21 + 80;
    power = rand()%7 + 4;
}

int Character::getHealth() const{
    return health;
}

int Character::getPower() const{
    return power;
}

void Character::setPower(int given) {
    power = given;
}

void Character::setHealth(int given) {
    health = given;
}