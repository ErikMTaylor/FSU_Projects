/* Name: Erik Taylor
 * Class: COP 3330
 * Section: 0006
 * Date: 9/10/22
 */

#include <iostream>
#include "Line.h"
using namespace std;

int main(){
    //Uses all constructors.
    Line basicLine = Line();
    Line slope = Line(5.0);
    Line intercept = Line(5.0,1.0);
    Line all = Line(5.0,5.0,-5.0);

    //Uses all the print functions.
    intercept.printSlopeIntercept();
    basicLine.printPointSlope();
    slope.printSlopeIntercept();
    all.printStandard();

    //Uses perpendicular and Intersection.
    Line allPerpendicular = all.getPerpendicular();
    all.Intersection(allPerpendicular);//Not Parallel Lines
    basicLine.Intersection(intercept);//Parallel Lines

    //Uses all getters and setters.
    cout << "The xCoord is " << basicLine.getXcoord() << endl;
    basicLine.setXcoord(2.0);
    cout << "The yCoord is " << basicLine.getYcoord() << endl;
    basicLine.setYcoord(4.0);
    cout << "The slope is " << basicLine.getSlope() << endl;
    basicLine.setSlope(2.0);
    basicLine.printSlopeIntercept();

    return 0;
}