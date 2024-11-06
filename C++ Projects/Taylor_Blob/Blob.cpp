#include "Blob.h"
#include <random>
#include <iostream>

//Default constructor for Dead Blob
Blob::Blob() {
    color = '0';
    health = 100;
    power = 10;
    xCoord = 0;
    yCoord = 0;
}

//Constructor used for creating Blobs on certain teams
Blob::Blob(char team) {
    color = team;
    health = 100;
    power = 10;
    xCoord = rand() % 11;//Rand function sets the variable randomly
    yCoord = rand() % 11;//to anything in the range from 0-10.
}

//Operator overload that allows me to display Blobs efficiently.
ostream& operator<<(ostream& o, Blob given){
    o << "Position: (" << given.getXCoord() << "," << given.getYCoord() << ") ";
    o << "Health= " << given.getHealth() << " Power= " << given.getPower() << "\n";
    return o;
}

//Operator overload that allows me to add Blobs together when landing on same team.
Blob operator+(Blob moved, Blob stationary){
    Blob merged;
    merged.health= moved.getHealth() + stationary.getHealth();
    if(moved.getPower() > stationary.getPower())
        merged.setPower(moved.getPower() + 2);
    else if(stationary.getPower() >= moved.getPower())
        merged.setPower(stationary.power + 2);
    else
        cout << "There is an issue.\n";
    merged.setXCoord(stationary.getXCoord());
    merged.setYCoord(stationary.getXCoord());
    merged.setColor(stationary.getColor());
    return merged;
}

//Getters-------------------------
int Blob::getColor() const {
    return color;
}

int Blob::getHealth() const {
    return health;
}

int Blob::getPower() const {
    return power;
}

int Blob::getXCoord() const {
    return xCoord;
}

int Blob::getYCoord() const {
    return yCoord;
}
//End of Getters-------------------

//Setters--------------------------
void Blob::setHealth(int num) {
    health = num;
}

void Blob::setPower(int num) {
    power = num;
}

void Blob::setXCoord(int num) {
    xCoord = num;
}

void Blob::setYCoord(int num) {
    yCoord = num;
}
void Blob::setColor(char letter) {
    color = letter;
}
//End of Setters-------------------
