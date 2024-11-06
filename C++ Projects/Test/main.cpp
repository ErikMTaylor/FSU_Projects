#include <iostream>
#include <cctype>
using namespace std;

int getValidChoice();
int main(){
    int choice;
    choice = getValidChoice();
    cout << choice;

    return 0;
}

int getValidChoice(){
    char choice;
    bool valid = false;

    while(valid == 0) {
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'A') {
            valid = true;
        }else if(choice == 'B') {
            valid = true;
        }else {
            cout << "Not Valid.\n";
        }
    }
    return choice;
}