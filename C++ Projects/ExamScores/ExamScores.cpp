

#include <iostream>
using namespace std;
int main() {
    //Variables for scores
    double exam1;
    double exam2;
    double exam3;

    //Gets variable values from user.
    cout << "This program orders exam scores in order.\n";
    cout << "What is the first exam score?\n";
    cin >> exam1;
    cout << "What is the second exam score?\n";
    cin >> exam2;
    cout << "What is the third exam score?\n";
    cin >> exam3;

    //Prevents user from entering equal scores.
    if (exam1 == exam2 && exam2 == exam3)
        cout << "The exam scores you entered are all equal.\n Please try again.";
    else {

        //First path for if exam1 is the max.
        if (exam1 > exam2 && exam1 > exam3) {
            cout << exam1 << endl;

            //Embedded if statement to determine middle and min variables.
            if (exam2 > exam3)
                cout << exam2 << endl << exam3;
            else
                cout << exam3 << endl << exam2;

            //Second path for if exam2 is the max.
        } else if (exam2 > exam1 && exam2 > exam3) {
            cout << exam2 << endl;

            //Embedded if statement to determine middle and min variables.
            if (exam1 > exam3)
                cout << exam1 << endl << exam3;
            else
                cout << exam3 << endl << exam1;

            //Third path for if exam3 is the max.
        } else {
            cout << exam3 << endl;

            //Embedded if statement to determine middle and min variables.
            if (exam1 > exam2)
                cout << exam1 << endl << exam2;
            else
                cout << exam2 << endl << exam1;
        }
    }
    return 0;
}
