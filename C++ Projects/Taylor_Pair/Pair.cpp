#include <iostream>
#include "Pair.h"
using namespace std;

//Constructors
Pair::Pair() {
    X = 0;
    Y = 0;
}

//Conversion Constructor
Pair::Pair(float given) {
    X = given;
    Y = 0;
}

Pair::Pair(float givenX, float givenY) {
    X = givenX;
    Y = givenY;
}

//Getters
float Pair::getX() {
    return X;
}

float Pair::getY() {
    return Y;
}

//Setters
void Pair::setX(float given) {
    X = given;
}

void Pair::setY(float given) {
    Y = given;
}

//Operator Overloads
//Overload for addition of Pairs.
Pair operator+(Pair first, Pair second){
    Pair sum;
    sum.setX((first.getX()) + (second.getX()));
    sum.setY((first.getY()) + (second.getY()));
    return sum;
}

//Overload for subtraction of Pairs.
Pair operator-(Pair first, Pair second){
    Pair difference;
    difference.setX((first.getX()) - (second.getX()));
    difference.setY((first.getY()) - (second.getY()));
    return difference;
}

//Overload that multiplies a Pair by a number.
Pair operator*(float num, Pair given){
    Pair multiplied;
    multiplied.setX((num) * (given.getX()));
    multiplied.setY((num) * (given.getY()));
    return multiplied;
}

//Overload that returns the dot product of two Pairs.
float operator*(Pair first, Pair second){
    float multipliedX, multipliedY, product;
    multipliedX = (first.getX()) * (second.getX());
    multipliedY = (first.getY()) * (second.getY());
    product = multipliedX + multipliedY;
    return product;
}

//Overload that returns a bool for Pair == tests
bool operator==(Pair first, Pair second){
    if (first.getX() == second.getX()){
        if(first.getY() == second.getY()){
            return true;
        }else
            return false;
    }else
        return false;
}

//Overload that displays a Pair
ostream& operator<<(ostream& o, Pair given){
    o << "(" << given.getX() << "," << given.getY() << ")\n";
    return o;
}