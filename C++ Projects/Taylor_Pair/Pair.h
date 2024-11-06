#include <iostream>
using namespace std;

class Pair{

    //Friends functions for operator overloads.
    friend Pair operator+(Pair, Pair);
    friend Pair operator-(Pair, Pair);
    friend float operator*(Pair, Pair);
    friend Pair operator*(float, Pair);
    friend bool operator==(Pair, Pair);
    friend ostream& operator<<(ostream& o, Pair);

public:
    //Constructors
    Pair();
    Pair(float);
    Pair(float, float);

    //Getters and Setters
    float getX();
    void setX(float);
    float getY();
    void setY(float);

//Private Data Members.
private:
    float X;
    float Y;
};

