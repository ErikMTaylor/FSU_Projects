#ifndef ASSIGMENT7_PARTY_H
#define ASSIGMENT7_PARTY_H
#include "Character.h"
#include <iostream>
using namespace std;
//Holds treasure counter
//Dynamic
//Game ends when
//Win: Party kills all monsters and picks up all treasure
//Lose: Party dies
//Print message for both

class Party{
public:
    Party(int x, int y);
    Party(const Party&);
    ~Party();

    void operator=(Party&);
    friend ostream& operator<<(ostream& o, Party&);

    int getSize() const;
    int getXCoord() const;
    int getYCoord() const;
    int getTreasure() const;
    Character* getParty() const;

    void setSize(const int);
    void setXCoord(const int);
    void setYCoord(const int);
    void setTreasure(const int);
    void setTeam(const Character*, int);

    void kill(int);//Removes a part of the array by sliding items down.
private:
    Character* team;
    int size;
    int xCoord;
    int yCoord;
    int totalTreasure;
};



#endif //ASSIGMENT7_PARTY_H
