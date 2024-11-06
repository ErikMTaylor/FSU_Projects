#include <iostream>
#include "Party.h"
using namespace std;

Party::Party(int x, int y){
    srand(time(0));
    size = 5;
    team = new Character[size];
    for(int i=0;i<size;i++) {
        team[i].setPower(rand()%7 + 4);
        team[i].setHealth(rand()%21 + 80);
    }
    xCoord = x;
    yCoord = y;
    totalTreasure = 0;
}

Party::Party(const Party& given) {
    setXCoord(given.getXCoord());
    setYCoord(given.getYCoord());
    setSize(given.getSize());
    setTreasure(given.getTreasure());
    setTeam(given.getParty(), given.getSize());
}

void Party::operator=(Party& given){
    setXCoord(given.getXCoord());
    setYCoord(given.getYCoord());
    setSize(given.getSize());
    setTreasure(given.getTreasure());
    setTeam(given.getParty(), given.getSize());
}

ostream& operator<<(ostream& o, Party& given){
    o << "Your Team:\n";
    for(int i = 0; i < given.getSize(); i++){
        o << i + 1 << ". Health: " << given.getParty()[i].getHealth() << "\tPower: ";
        o << given.getParty()[i].getPower() << endl;
    }
    return o;
}

void Party::kill(int given) {
    for(int i = given; i<getSize();i++){
        team[i] = team[i+1];
    }
    size--;
}



void Party::setSize(const int given){
    size = given;
}
void Party::setXCoord(const int given){
    xCoord = given;
}
void Party::setYCoord(const int given){
    yCoord = given;
}
void Party::setTreasure(const int given){
    totalTreasure = given;
}
void Party::setTeam(const Character* given, int gSize){
    delete [] team;
    size = gSize;
    team = new Character[gSize];
    for(int i=0; i < gSize; i++)
        team[i] = given[i];
}


Party::~Party(){
    delete [] team;
}

int Party::getSize()const{
    return size;
}

int Party::getXCoord()const{
    return xCoord;
}

int Party::getYCoord()const{
    return yCoord;
}

int Party::getTreasure()const{
    return totalTreasure;
}

Character* Party::getParty()const{
    return team;
}
