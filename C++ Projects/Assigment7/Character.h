#ifndef ASSIGMENT7_CHARACTER_H
#define ASSIGMENT7_CHARACTER_H

//Health between 80-100
//Power 4-10
//Move
//Display with operator
//Chooses monster to attack
//15% chance of missing the target
//Whole party attacks before monsters attack
//Option to run away based on # of monsters
//5=10%, 4=20%, 3=30%, 2=40%, 1=50%
//Running moves the M tile to another location and player returns to game board.

class Character{
public:
    Character();

    int getHealth() const;
    int getPower() const;

    void setHealth(int);
    void setPower(int);

private:
    int health;
    int power;
};




#endif //ASSIGMENT7_CHARACTER_H
