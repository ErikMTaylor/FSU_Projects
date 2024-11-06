#include <iostream>
#include "Line.h"
using namespace std;

//Default Constructor
Line::Line() {
    xCoord = 0;
    yCoord = 0;
    slope = 1;
}
//Constructor for slope
Line::Line(float num) {
    xCoord = 0;
    yCoord = 0;
    slope = num;
}
//Constructor for slope and intercept
Line::Line(float intercept, float num) {
    xCoord = 0;
    yCoord = intercept;
    slope = num;
}
//Constructor for all three data.
Line::Line(float x, float y, float num) {
    xCoord = x;
    yCoord = y;
    slope = num;
}

//End of Constructors
//Start of public functions.

void Line::printPointSlope()const{
    float newX = getXcoord();
    if(newX == -0)//Prevents -0's and makes the equations prettier.
        newX = 0;
    //If statements that determine which way the line should be printed based on 0's,
    // Positives and negatives to make things look pretty.
    if(getYcoord() >= 0 && getXcoord() >= 0)
        cout << "y-" << getYcoord() << "="<< getSlope() << "(x-" << newX << ")\n";
    else if(getYcoord() >= 0 && getXcoord() < 0)
        cout << "y-" << getYcoord() << "="<< getSlope() << "(x+" << -newX << ")\n";
    else if(getYcoord() < 0 && getXcoord() >= 0)
        cout << "y" << getYcoord() << "="<< getSlope() << "(x-" << newX << ")\n";
    else if(getYcoord() < 0 && getXcoord() < 0)
        cout << "y" << getYcoord() << "="<< getSlope() << "(x+" << -newX << ")\n";
}

void Line::printSlopeIntercept()const{
    float y;//Variable to hold the intercept.

    //If statements that determine whether to add or subtract the yCoord.
    //I could not think of a simpler way to code this.
    //The if statements solve for the y-intercept by plugging in a zero for x.
    if(getYcoord() > 0)
        y = getSlope() * -getXcoord() + getYcoord();
    else
        y = getSlope() * -getXcoord() - getYcoord();

    if(y == -0)//Prevents -0s to make prettier functions.
        y = 0;

    //If statements that determine the way the line should be printed.
    if(y >= 0)
        cout << "y=" << getSlope() << "x+" << y << endl;
    else if(y < 0)
        cout << "y=" << getSlope() << "x" << y << endl;
}

void Line::printStandard()const{
    float newX;//Holds the "B"
    float varC;//Holds the "C"

    //Solves for B when plugged into point slope form.
    newX = getSlope() * -1;

    //If statement that determines whether to add or subtract across.
    if(getYcoord() > 0)
        varC = getSlope() * getXcoord() + getYcoord();
    else
        varC = getSlope() * getXcoord() - getYcoord();

    //If statement that prints depending on if x is positive or negative.
    if(newX >= 0)
        cout << "y+" << newX << "x=" << varC << endl;
    else if(newX < 0)
        cout << "y" << newX << "x=" << varC << endl;
}

Line Line::getPerpendicular()const{
    //Copies the data into a new line.
    Line perp(getXcoord(), getYcoord(), getSlope());
    //solves for the perpendicular slope and returns it.
    perp.slope = (-1/getSlope());
    return perp;
}

void Line::Intersection(Line given)const{
    //Variables to hold the intersection points and solved integers/coefficients.
    float solvedB;
    float solvedC;
    float x, y;

    //Using point slope form, the coords are plugged in and moved around.
    solvedB = (getSlope() * -1) - (given.getSlope() * -1);

    //Tests to see if there are no intersections and prints message.
    if(solvedB == 0) {
        cout << "There are no intersections." << endl;
        return;
    }

    //I had this line split up into separate functions, but to make it more efficient
    // and use less memory, I changed it to one line with fewer variables.
    solvedC = (getSlope()*-getXcoord()+getYcoord()) - (given.getSlope()*-given.getXcoord()+given.getYcoord());

    //After everything is eliminated, there is an easy algebra equation left.
    x = solvedC / solvedB;

    //Plug x back into the equation to get y.
    y = (getSlope() * x) + (getSlope() * -getXcoord()) + getYcoord();

    //Prints the points.
    cout << "The lines intersect at (" << x << "," << y << ").\n";
}
//Member function that returns xCoord.
float Line::getXcoord()const{
    return xCoord;
}
//Member function that returns yCoord.
float Line::getYcoord()const{
    return yCoord;
}
//Member function that returns slope.
float Line::getSlope()const{
    return slope;
}
//Member function that sets a new xCoord.
void Line::setXcoord(float num){
    xCoord = num;
}
//Member function that sets a new yCoord.
void Line::setYcoord(float num){
    yCoord = num;
}
//Member function that sets a new slope.
void Line::setSlope(float num){
    slope = num;
}

