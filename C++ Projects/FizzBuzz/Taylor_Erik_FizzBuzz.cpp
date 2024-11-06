/* Name: Erik Taylor
 * Class: COP 3330
 * Section: 0006
 * Date: 8/24/22
 */

#include <iostream>
using namespace std;

int main()
{
    //Variables that hold index and entered number.
    int max;
    int i;

    //Welcome message + gets max number.
    cout << "Please enter in a whole integer > 0 -->";
    cin >> max;
    cout << endl;

    //Loop that iterates through all the numbers being tested.
    for(i=1; i < max +1; i++)
    {
        //If statements that test index to see if it is divisible by each picked divisor.
        if(i % 15 == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else if(i % 5 == 0)
        {
            cout << "Buzz" << endl;
        }
        else if(i % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;//End
}
