//
// Created by erikm on 4/15/2022.
//

#include "Avenger.h"
#include <string>
using namespace std;

Avenger::Avenger()
{
    name = "";
    appearances = 0;
    gender = "";
    dead = false;
}

Avenger::Avenger(string nm)
{
    name = nm;
    appearances = 0;
    gender = "";
    dead = false;
}

void Avenger::setName(string nm)
{
    name = nm;
}

void Avenger::setAppearances(int app)
{
    appearances = app;
}

void Avenger::setGender(string gen)
{
    gender = gen;
}

void Avenger::setDead(bool ded)
{
    dead = ded;
}

string Avenger::computeNumberOfAppearancesRange(int app)
{
if(app >=1 && app <=750)
    return "<=750";
else if(app > 750 && app <= 1500)
    return "> 750 and <=1500";
else if(app > 1500 && app <= 2250)
    return "> 1500 and <=2250";
else if(app > 2250 && app <= 3000)
    return "> 2250 and <=3000";
else if(app > 3000 && app <= 3750)
    return "> 3000 and <=3750";
else
    return "> 3750 and <=4500";
}

string Avenger::accName() const
{
    return name;
}

string Avenger::accGender() const
{
    return gender;
}
bool Avenger::accDead() const
{
    return dead;
}

int Avenger::accAppearances() const
{
    return appearances;
}

string Avenger::accNewAppearances() const
{
    return newAppearances;
}