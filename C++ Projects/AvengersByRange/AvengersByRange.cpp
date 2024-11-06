#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Data_
        {
        string rangeAppearances;
        int upperLimits;
        int numMales = 0;
        int numFemales = 0;
        int diedOnce = 0;
        int neverDied = 0;
        };

void Menu();
void SortData(int i, Data_ &);
void DisplayData(int numRanges, Data_ [numRanges]);

int main() {

    //Welcome Message + Display Menu
    cout << "Welcome to Avengers Data By Range Program\n";
    Menu();

    //Variables
    bool quit = false;
    char choice;
    int numRanges = 6;
    int i;

    Data_ avengers[numRanges];
    int temp[] = {750, 1500, 2250, 3000, 3750, 4500};
    for(i=0; i<numRanges; i++)
    {
        avengers[i].upperLimits = temp[i];
    }

    //Opens function that will take in and sort data into the structure.
    for(i=0; i<numRanges; i++)
    {
        SortData(i, &avengers[i]);
    }

    while(quit == false)
    {
        cin >> choice;
        cout << endl;
        choice = toupper(choice);

        switch (choice)
        {
            case 'A':
                DisplayData(numRanges, avengers[numRanges]);
                Menu();
                break;
            case 'B':
                cout << "The range with the largest number of avengers who have died once is ...\n";
                Menu();
                break;
            case 'C':
                cout << "The range with the largest percentage of avengers who are female is ...\n";
                Menu();
                break;
            case 'D':
                quit = true;
                break;
            default:
                Menu();
                break;
        }
    }
    return 0;
}

void Menu()
{
    cout << "Menu Options:\n";
    cout << "A) Display Data\n";
    cout << "B) Find Range with the larges number of Avengers who have died\n";
    cout << "C) Find Range with the largest percentage of Avengers that are female\n";
    cout << "D) Quit\n";
}

void SortData(int i, Data_ &avengers)
{
    //Take in and sort data from file into structure.
    ifstream openFile("AvengersData.txt");

    string data1, data3, data4;
    int data2;

    while(openFile >> data1 >> data2 >> data3 >> data4)
    {
        if(data2 > avengers.upperLimits[i] && data2 <= avengers.upperLimits[i+1])
        {
            if(data3 == "MALE")
                avengers.numMales++;
            else
                avengers.numFemales++;
            if(data4 == "YES")
                avengers.diedOnce++;
            else
                avengers.neverDied++;}
    }
    openFile.close();
}

void DisplayData(int numRanges, Data_ avengers[numRanges])
{
    int i;
    cout << setw(15);
    cout << "Range" << "Num Females" << "Num Males" << "Num Died Once" << "Num Never Died Once\n";
    for(i=0; i<numRanges; i++)
    {
        cout << avengers[i].rangeAppearances << avengers[i].numFemales;
        cout << avengers[i].numMales << avengers[i].diedOnce << avengers[i].neverDied;
        cout << endl;

    }
}