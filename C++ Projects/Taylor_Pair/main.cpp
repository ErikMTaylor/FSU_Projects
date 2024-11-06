#include <iostream>
#include "Pair.h"
using namespace std;

int main() {
    //Create objects for the equations.
    Pair empty = Pair(), one = Pair(1,3);
    Pair two = Pair(9,2);
    Pair three = Pair(3,8);
    Pair four = Pair(4,9), five = Pair(6,7), six = Pair(4,1), seven = Pair(2,4);
    Pair eight = Pair(3,10), nine = Pair(1,17);
    Pair test = Pair(), test2 = Pair(), test3 = Pair(1);

    //  (1,3)+(0,0)
    cout << "1.  " << one + empty;

    //  7*(9,2)
    cout << "2.  " << 7 * two;

    //  (1,3)*(3,8)
    cout << "3.  " << one * three << endl;

    //  (((4,9)*(6,7))*(4,1)) - ((1,3)+(2,4))
    cout << "4.  " << ((four * five) * six) - (one + seven);

    //  (((3,10)*(1,17))*(4,1)) + ((1,3)-(2,4))
    cout << "5.  " << ((eight * nine) * six) + (one - seven);

    //Test == for like pairs.
    cout << "6.  " << (test == test2) << endl;

    //Test == for unlike pairs.
    cout << "7.  " << (test == test3) << endl;
    return 0;
}
