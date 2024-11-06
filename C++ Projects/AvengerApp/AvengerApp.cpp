

#include <iostream>
#include "Avenger.h"
using namespace std;

void DisplayAvenger(Avenger);

int main() {

    //Creates the instance and fills in info for an Avenger.
    Avenger Anthony_Stark("Anthony Stark");
    Anthony_Stark.setAppearances(3068);
    Anthony_Stark.setGender("MALE");
    Anthony_Stark.setDead(true);

    //Creates the instance and fills in info for an Avenger.
    Avenger Hercules;
    Hercules.setName("Hercules");
    Hercules.setAppearances(741);
    Hercules.setGender("MALE");
    Hercules.setDead(false);


    //Creates the instance and fills in info for an Avenger.
    Avenger Wanda;
    Wanda.setName("Wanda Maximoff");
    Wanda.setAppearances(1214);
    Wanda.setGender("FEMALE");
    Wanda.setDead(true);

    //Creates the instance and fills in info for an Avenger.
    Avenger Vision;
    Vision.setName("Vision");
    Vision.setAppearances(1036);
    Vision.setGender("MALE");
    Vision.setDead(true);

    //Calls function to display all the data for each Avenger.
    DisplayAvenger(Anthony_Stark);
    DisplayAvenger(Hercules);
    DisplayAvenger(Wanda);
    DisplayAvenger(Vision);

    return 0;
}

void DisplayAvenger(Avenger nm)
{
    cout << "Name: " << nm.accName() << endl;
    cout << "Number of Appearances: " << nm.accAppearances() << endl;
    cout << "Gender: " << nm.accGender() << endl;
    cout << "Died At Least Once: " << nm.accDead() << endl;
    cout << "Number of Appearances Range: " << nm.computeNumberOfAppearancesRange(nm.accAppearances()) << endl;
    cout << endl;
}