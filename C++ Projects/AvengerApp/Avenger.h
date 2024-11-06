//
// Created by erikm on 4/15/2022.
//

#include <string>
using namespace std;
#ifndef AVENGERAPP_AVENGER_H
#define AVENGERAPP_AVENGER_H

class Avenger
{
private:
    string name;
    int appearances;
    string gender;
    bool dead;
    string newAppearances;
public:
    //Constructors
    Avenger();
    Avenger(string nm);

    //Mutators
    void setName(string nm);
    void setAppearances(int app);
    void setGender(string gen);
    void setDead(bool ded);
    static string computeNumberOfAppearancesRange(int app);

    //Accessors
    string accName() const;
    string accGender() const;
    bool accDead() const;
    int accAppearances() const;
    string accNewAppearances() const;
};
#endif //AVENGERAPP_AVENGER_H
