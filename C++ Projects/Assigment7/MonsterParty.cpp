#include "MonsterParty.h"
#include <random>
using namespace std;

MonsterParty::MonsterParty(){
    srand(time(0));
    treasure = rand()%10 + 1;
    size = rand()%5 + 1;
    enemies = new Monster[size];
    for(int i = 0; i<size; i++){
        enemies[i].setHealth(rand()%16 + 15);
        enemies[i].setPower(rand()%6 + 1);
    }
}

MonsterParty::MonsterParty(MonsterParty& given){
    setTreasure(given.getTreasure());
    setSize(given.getSize());
    enemies = new Monster[1];
    setParty(given.getParty(), given.getSize());
}

MonsterParty::~MonsterParty() {
    delete [] enemies;
}

ostream& operator<<(ostream& o, MonsterParty& given){
    o << "Monsters:\n";
    for(int i = 0; i < given.getSize(); i++){
        o << i + 1 << ". Health: " << given.getParty()[i].getHealth() << "\tPower: ";
        o << given.getParty()[i].getPower() << endl;
    }
    return o;
}

void MonsterParty::operator=(MonsterParty & given) {
    setTreasure(given.getTreasure());
    setSize(given.getSize());
    setParty(given.getParty(), given.getSize());
}

void MonsterParty::kill(int given){
    for(int i = given; i<getSize();i++){
        enemies[i] = enemies[i+1];
    }
    size--;
}



void MonsterParty::setSize(int given){
    size = given;
}
void MonsterParty::setTreasure(int given){
    treasure = given;
}
void MonsterParty::setParty(Monster* given, int gSize){
    delete [] enemies;
    size = gSize;
    enemies = new Monster[gSize];
    for(int i = 0; i < gSize; i++)
        enemies[i] = given[i];
}

int MonsterParty::getSize() const{
    return size;
}
int MonsterParty::getTreasure() const{
    return treasure;
}
Monster* MonsterParty::getParty() const{
    return enemies;
}