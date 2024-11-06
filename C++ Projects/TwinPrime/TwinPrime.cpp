

#include <iostream>
using namespace std;

int main()
{
    //Variables.
    int max,
        x,
        y,
        divisorX,
        divisorY,
        primeTotal = 0,
        notPrime;

    //Welcome message + User input for max.
    cout << "Welcome to the Twin Primes program.\n";
    cout << "What is the upper value?";
    cin >> max;
    cout << endl;

    //Prevent user input error.
    while (max <= 0)
    {
        cout << "What is the upper value? (must be an integer > 0)";
        cin >> max;
    }

    //Loop for the given range that increases x on every cycle.
    for (x = 3; x <= max; x++)
    {
        //Loop that determines if x is a prime number.
        divisorX = 2;
        for (notPrime = 0; divisorX < x; divisorX++)
        {
            if (x % divisorX == 0)
                notPrime++;
            else if (notPrime > 0)
                break;
            else {}
        }
        //Loop that determines if y is a prime.
        divisorY = 2;
        y = x + 2;
        if (notPrime == 0)
        for (notPrime = 0; divisorY < y; divisorY++)
        {
            if (y % divisorY == 0)
                notPrime++;
            else if (divisorY == y - 1 && notPrime == 0)
            {
                //If x and y are both twin primes, it will display and add one to total.
                cout << "(" << x << "," << y << ")\n";
                primeTotal++;
            }
            else if (notPrime > 0)
                break;
            else
                continue;
        }
        else
            continue;
    }
    //When range is complete, this message will display.
    cout << "Found " << primeTotal << " Twin Prime pairs.\n";
    return 0;
}
