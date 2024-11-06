/*Name: Erik Taylor
 * Class:COP 3330
 * Section: 0006
 * Date: 9/24/22
*/

#include <iostream>
#include <cctype>
#include "Blob.h"
using namespace std;

//Function Definitions
void showMenu(int);
void displayBlobs(Blob [4], Blob [4]);
int getValidChoice();
Blob* getValidBlob(int, Blob[4]);
char getValidDirection();
bool attack(Blob*, Blob [4]);
void move(Blob*, Blob [4], Blob [4]);

int main() {

    //Variables
    char choice;
    bool kill = false;//Variables that control while loops
    bool turnRed = false;
    bool turnBlue = false;
    bool gameOver = false;
    Blob* blobChoice;//Pointer to the chosen Blob for a players turn.

    //Create all instances of Blobs for both teams by passing team char.
    Blob redA = Blob('1'), redB = Blob('1'), redC = Blob('1'), redD = Blob('1');
    Blob blueA = Blob('2'), blueB = Blob('2'), blueC = Blob('2'), blueD = Blob('2');

    //Arrays to hold each team's Blobs for easier passing as arguments.
    Blob player1[4] = {redA, redB, redC, redD};
    Blob player2[4] = {blueA, blueB,blueC, blueD};

    //Loop that iterates until game ends.
    while(gameOver == 0)
    {
        //Player 1 Turn
        //Displays All Blobs
        while(turnRed == 0) {
            displayBlobs(player1, player2);//Displays Blobs
            blobChoice = getValidBlob(1, player1);//Gets Blob Choice

            showMenu(1);//Displays choices.
            choice = getValidChoice();//Gets and Validates Choice
            if (choice == 'A')
                move(blobChoice, player1, player2);//If chosen, the Blob moves to a new spot.
            else if (choice == 'B')
                kill = attack(blobChoice, player2);//If chosen, the Blob attacks.
            else
                cout << "Fix your code.\n";//Error message for testing.

            turnRed = true;//Ends the turn loop.
        }
        turnRed = false;//Resets turn loop

        //Tests to see if anyone won again.
        //if(redA.getColor() == '0')
        if(player1[0].getColor() == '0') {
            if (player1[1].getColor() == '0') {
                if (player1[2].getColor() == '0') {
                    if (player1[3].getColor() == '0') {
                        cout << "Player2 Won!\n";
                        gameOver = true;
                    }
                }
            }
        }
        if(player2[0].getColor() == '0') {
            if (player2[1].getColor() == '0') {
                if (player2[2].getColor() == '0') {
                    if (player2[3].getColor() == '0') {
                        cout << "Player1 Won!\n";
                        gameOver = true;
                    }
                }
            }
        }

        //Loop that starts if there was a kill. It will loop until there are no more kills.
        if(kill == 1){
            do {
                kill = false;//Resets loop.
                cout << "You get another turn for a successful kill!\n";
                displayBlobs(player1, player2);
                blobChoice = getValidBlob(1, player1);

                showMenu(1);
                choice = getValidChoice();
                if (choice == 'A')
                    move(blobChoice, player1, player2);
                else if (choice == 'B')
                    kill = attack(blobChoice, player2);
                else
                    cout << "Fix your code.\n";
            }while(kill == 1);
        }

        //Same exact thing as player1 but different arguments.
        //Player 2 Turn
        //Displays All Blobs
        while(turnBlue == 0) {
            displayBlobs(player1, player2);
            blobChoice = getValidBlob(2, player2);

            showMenu(2);
            choice = getValidChoice();
            if (choice == 'A')
                move(blobChoice, player1, player2);
            else if (choice == 'B')
                kill = attack(blobChoice, player1);
            else
                cout << "Fix your code.\n";
            turnBlue = true;//Ends turn loop
        }
        turnBlue = false;//Resets Loop

        //Tests to see if anyone won again.
        //if(redA.getColor() == '0')
        if(player1[0].getColor() == '0') {
            if (player1[1].getColor() == '0') {
                if (player1[2].getColor() == '0') {
                    if (player1[3].getColor() == '0') {
                        cout << "Player2 Won!\n";
                        gameOver = true;
                    }
                }
            }
        }
        if(player2[0].getColor() == '0') {
            if (player2[1].getColor() == '0') {
                if (player2[2].getColor() == '0') {
                    if (player2[3].getColor() == '0') {
                        cout << "Player1 Won!\n";
                        gameOver = true;
                    }
                }
            }
        }

        //Kill loop used for player2
        if(kill == 1){
            do{
                kill = false;//Resets loop
                displayBlobs(player1, player2);
                blobChoice = getValidBlob(2, player2);

                showMenu(2);
                choice = getValidChoice();
                if (choice == 'A')
                    move(blobChoice, player1, player2);
                else if (choice == 'B')
                    kill = attack(blobChoice, player1);
                else
                    cout << "Fix your code.\n";
            }while(kill == 1);
        }

    }
    return 0;
}

//Displays choices for a chosen Blob.
void showMenu(int num){
    cout << "Player " << num << ":\n";
    cout << "A. Move" << endl;
    cout << "B. Attack" << endl;
}

//Displays all Blobs in an organized way.
void displayBlobs(Blob red[4], Blob blue[4]){
    int i;
    cout << "Player 1 Blobs:\n";
    for(i=0; i<4; i++){     //Loop that iterates through Player1 array.
        if(red[i].getColor() == '1')
            cout << i+1 << "--> " << red[i];
    }
    cout << "Player 2 Blobs:\n";
    for(i=0; i<4; i++){     //Loop that iterates through Player2 array
        if(blue[i].getColor() == '2')
            cout << i+1 << "--> " << blue[i];
    }
}

//Function is called when attack is chosen in menu.
bool attack(Blob* given, Blob enemy[4]){
    //Bool variables for loops.
    bool attack = false;
    bool kill = false;

    while(attack == 0) {
        char direction = getValidDirection();//Gets valid direction of attack.
        int i;

        //Each if statement takes in a direction and tests to see
        //if there is an enemy Blob one square away in the chosen direction.
        //If true, the enemy health is subtracted by user power
        //Then it tests to see if the enemy Blob is dead and returns kill bool.
        if (direction == 'N') {
            for (i = 0; i < 5; i++) {
                if ((*given).getXCoord() == enemy[i].getXCoord()) {
                    if ((*given).getYCoord() + 1 == enemy[i].getYCoord()) {
                        enemy[i].setHealth(enemy[i].getHealth() - (*given).getPower());
                        if (enemy[i].getHealth() <= 0) {
                            enemy[i].setColor('0');
                            enemy[i].setYCoord(-1);
                            enemy[i].setXCoord(-1);
                            kill = true;
                        }
                    }
                }
            }
        } else if (direction == 'E') {      //If for East
            for (i = 0; i < 5; i++) {
                if ((*given).getYCoord() == enemy[i].getYCoord()) {
                    if ((*given).getXCoord() + 1 == enemy[i].getXCoord()) {
                        enemy[i].setHealth(enemy[i].getHealth() - (*given).getPower());
                        if (enemy[i].getHealth() <= 0) {
                            enemy[i].setColor('0');
                            enemy[i].setYCoord(-1);
                            enemy[i].setXCoord(-1);
                            kill = true;
                        }
                    }
                }
            }
        } else if (direction == 'S') {      //If for South
            for (i = 0; i < 5; i++) {
                if ((*given).getXCoord() == enemy[i].getXCoord()) {
                    if ((*given).getYCoord() - 1 == enemy[i].getYCoord()) {
                        enemy[i].setHealth(enemy[i].getHealth() - (*given).getPower());
                        if (enemy[i].getHealth() <= 0) {
                            enemy[i].setColor('0');
                            enemy[i].setYCoord(-1);
                            enemy[i].setXCoord(-1);
                            kill = true;
                        }
                    }
                }
            }
        } else if (direction == 'W') {      //If for West
            for (i = 0; i < 5; i++) {
                if ((*given).getYCoord() == enemy[i].getYCoord()) {
                    if ((*given).getXCoord() - 1 == enemy[i].getXCoord()) {
                        enemy[i].setHealth(enemy[i].getHealth() - (*given).getPower());
                        if (enemy[i].getHealth() <= 0) {
                            enemy[i].setColor('0');
                            enemy[i].setYCoord(-1);
                            enemy[i].setXCoord(-1);
                            kill = true;
                        }
                    }
                }
            }
        } else {
            cout << "There is a problem.\n";   //Error message for testing.
        }
         //Ends the loop. If there was no attack, the turn is lost.
            attack = true;
    }
    return kill;//Returns the kill bool that initiates the kill loop in main.
}

//Move function that can be chosen by players.
//Tests to make sure move is in bounds, not on enemy Blobs, and merges on teammates.
void move(Blob* given, Blob red[4], Blob blue[4]){
    //Variables for loops/Ifs
    bool tests = false;//Loop
    bool bounds = false;//If
    bool onEnemy = true;//If

    //Loop that iterates till all tests are complete.
    while(tests == 0) {
        //New Blob that resets every loop. To prevent random changes to the real Blob.
        Blob temp = *given;
        char direction;
        direction = getValidDirection();//Gets and validates direction input.

        //Changes the coords based on direction.
        if (direction == 'N')
            temp.setYCoord(temp.getYCoord() + 1);
        else if (direction == 'S')
            temp.setYCoord(temp.getYCoord() - 1);
        else if (direction == 'E')
            temp.setXCoord(temp.getXCoord() + 1);
        else if (direction == 'W')
            temp.setXCoord(temp.getXCoord() - 1);

        //Tests to make sure Blob is in bounds.
        if (temp.getXCoord() > 10 || temp.getXCoord() < 0)
            cout << "That direction is out of bounds. Please try again.\n";
        else if(temp.getYCoord() > 10 || temp.getYCoord() < 0)
            cout << "That direction is out of bounds. Please Try Again.\n";
        else
            bounds = true;//Starts next section.

        //If starts when Blob is in bounds.
        if(bounds == 1) {
            int i;
            //If for each team that tests to see if it lands on enemy Blobs.
            if (temp.getColor() == '1') {
                for (i = 0; i < 5; i++) {
                    if (temp.getXCoord() == blue[i].getXCoord()) {
                        if (temp.getYCoord() == blue[i].getYCoord()) {
                            cout << "You cannot move onto the enemy Blob.\n";
                            break;
                        }
                    }
                }
                onEnemy = false;//Starts the next if statement.
            }else if (temp.getColor() == '2') {
                for (i = 0; i < 5; i++) {
                    if (temp.getXCoord() == red[i].getXCoord()) {
                        if (temp.getYCoord() == red[i].getYCoord()) {
                            cout << "You cannot move onto the enemy Blob.\n";
                            break;
                        }
                    }
                }
                onEnemy = false;//Starts the next if statement.
            }
        }
        if(onEnemy == 0){
            int i;

            //If that tests to see if Blob lands on friendly Blob then adds them together.
            if (temp.getColor() == '2') {
                for (i = 0; i < 5; i++) {
                    if (temp.getXCoord() == blue[i].getXCoord()) {
                        if (temp.getYCoord() == blue[i].getYCoord()) {
                            temp = temp + blue[i];
                            blue[i].setColor('0');
                            (*given) = temp;
                            return;
                        }
                    }
                }
            }else if(temp.getColor() == '1') {
                for (i = 0; i < 5; i++) {
                    if (temp.getXCoord() == red[i].getXCoord()) {
                        if (temp.getYCoord() == red[i].getYCoord()) {
                            temp = temp + red[i];
                            red[i].setColor('0');
                            (*given) = temp;
                            return;
                        }
                    }
                }
            }else {
                cout << "Chosen Blob was dead.\n";//If there was an error.
            }
            (*given) = temp;//Copies values onto the real blob if not landed on teammate.
            tests = true;//Ends big loop.
        }
    }
}

//Gets choice and validates.
//I have an error that prints a million messages if a char is entered.
//Not sure why it does that.
int getValidChoice(){
    char choice;
    bool valid = false;

    while(valid == 0) {
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'A')
            valid = true;
        else if(choice == 'B')
            valid = true;
        else
            cout << "That was not a valid choice. Try again.\n";
    }
    return choice;
}

//Function that gets a valid Blob choice and returns it as a pointer.
Blob* getValidBlob(int num, Blob given[4]){
    char choice;
    bool valid = false;
    Blob* wanted;//Pointer

    cout << "Player " << num << endl;
    cout << "Pick the number Blob you want to use: ";

    while(valid == 0)
    {
        cin >> choice;
        cout << endl;

        if(choice == '1') {
            wanted = &given[0];
            valid = true;
        }else if(choice == '2') {
            wanted = &given[1];
            valid = true;
        }else if(choice == '3') {
            wanted = &given[2];
            valid = true;
        }else if(choice == '4') {
            wanted = &given[3];
            valid = true;
        }else
            cout << "Please enter in 1, 2, 3, or 4.";
    }
    return wanted;//Returned pointer to picked address
}

//Gets valid direction and returns the char.
char getValidDirection(){
    char choice;
    bool valid = false;

    cout << "Which way would you like to move? (N,S,E,W):";

    while(valid == 0){

        cin >> choice;
        choice = toupper(choice);//Changes to uppercase for consistency

        if(choice == 'N')
            valid = true;
        else if(choice == 'S')
            valid = true;
        else if(choice == 'E')
            valid = true;
        else if(choice == 'W')
            valid = true;
        else
            cout << "Please enter a valid direction (N,S,E,W):";
    }
    return choice;
}