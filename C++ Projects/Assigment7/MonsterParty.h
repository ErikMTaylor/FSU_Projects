#ifndef ASSIGMENT7_MONSTERPARTY_H
#define ASSIGMENT7_MONSTERPARTY_H
#include "Monster.h"
#include <iostream>
using namespace std;
//Up to 5 instances
//Treasure reward??
//50% chance of missing an attack
//Attacks random player in party

class MonsterParty{
public:
    MonsterParty();
    MonsterParty(MonsterParty&);
    ~MonsterParty();

    void operator=(MonsterParty&);
    friend ostream& operator<<(ostream&, MonsterParty&);

    void kill(int);

    int getSize() const;
    int getTreasure() const;
    Monster* getParty() const;

    void setSize(int);
    void setTreasure(int);
    void setParty(Monster*, int);

private:
    Monster* enemies;
    int size;
    int treasure;
};




#endif //ASSIGMENT7_MONSTERPARTY_H
