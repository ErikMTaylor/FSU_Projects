#include <iostream>
using namespace std;
class Blob{

public:
    //Constructor
    Blob();
    Blob(char);//The compiler is saying to set this to explicit, Does this matter?

    //Getters
    int getXCoord()const;
    int getYCoord()const;
    int getHealth()const;
    int getPower()const;
    int getColor()const;

    //Setters
    void setXCoord(int);
    void setYCoord(int);
    void setHealth(int);
    void setPower(int);
    void setColor(char);

    //Operator Overloads
    friend ostream& operator<<(ostream& o, Blob);
    friend Blob operator+(Blob, Blob);

    //Private section to secure variables of Blobs.
private:
    char color;
    int health;
    int power;
    int xCoord;
    int yCoord;
};