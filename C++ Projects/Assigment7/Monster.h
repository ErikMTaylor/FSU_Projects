#ifndef ASSIGMENT7_MONSTER_H
#define ASSIGMENT7_MONSTER_H

//Health between 15-30
//Power between 1-6
//Treasure reward??
//50% chance of missing an attack
//Attacks random player in party

class Monster{
public:
    Monster();

    int getHealth() const;
    int getPower() const;

    void setHealth(int);
    void setPower(int);
private:
    int health;
    int power;
};




#endif //ASSIGMENT7_MONSTER_H
