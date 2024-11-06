/* Erik Taylor
 * emt20bd
 * COP3330
 * Section 0006
*/

#include <iostream>
#include "Party.h"
#include "MonsterParty.h"
#include "Board.h"
#include <random>
#include <cctype>
using namespace std;

void showMenu();        //Displays the menu options when in battle
void showIntro();       //Displays instructions
char battle(Party&);    //Called when battle occurs, returns end result

int main() {
    bool gameEnd = false;       //While loop for game
    char direction;             //Holds inputted direction of movement
    char result;                //Result from calling battle function

    srand(time(0));  //For random numbers

    //Create board of size 5
    Board gameBoard = Board(5);
    //Creates players team, with entrance coords from board
    Party user = Party(gameBoard.getEnterX(), gameBoard.getEnterY());

    showIntro();
    while(!gameEnd) {
        bool reallocate = false;            //Loop that iterates until M tile is in right spot

        //Tests to see if the player wins.
        if(gameBoard.getMobs() == 0 && gameBoard.getNumTreasures() == 0){
            cout << "You collected all treasure and beat all monsters.\n";
            cout << "So you win!!!\n";
            gameEnd = true;
        }
        cout << gameBoard;
        cin >> direction;
        direction = toupper(direction);
        if (direction == 'Q')
            gameEnd = true;

        //If statements for each direction input.
        //Each section test for what tile is landed on.
        //It also tests to make sure the move is in bounds.
        //Battles take in a char, which then determines what to do after.
        else if (direction == 'W') {
            if (user.getYCoord() - 1 < 1)
                cout << "That is out of bounds!\n";
            else
                user.setYCoord(user.getYCoord() - 1);

            if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'M') {
                result = battle(user);
                //User beat the group of monsters.
                if (result == 'W') {
                    cout << "You beat the group of monsters!\n";
                    cout << "Total Treasure: " << user.getTreasure() << endl;
                    gameBoard.setMobs(gameBoard.getMobs() - 1);

                    //User's party died.
                } else if (result == 'L') {
                    cout << "You lost because your whole party died.\n";
                    gameEnd = true;

                    //User ran away.
                } else if (result == 'R') {
                    cout << "You ran successfully!\n";
                    int yTemp;
                    int xTemp;
                    //Loop iterates until it randomly picks an empty space
                    while(!reallocate) {
                        yTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        xTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        if (gameBoard.getBoard()[yTemp][xTemp] == ' ') {
                            reallocate = true;
                        }
                    }
                    //Updates board tile.
                    //I did not use the dynamically allocated treasure or monster arrays at all.
                    gameBoard.updateBoard('M', yTemp, xTemp);
                }
                //If land on treasure tile, treasure is added to counter, and numTreasure is decremented.
            } else if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'T') {
                user.setTreasure(user.getTreasure() + rand() % 10 + 1);
                cout << "Party's Treasure: " << user.getTreasure() << endl;
                gameBoard.setNumTreasures(gameBoard.getNumTreasures() - 1);
            }
            //Swap the tiles for X
            gameBoard.updateBoard('X', user.getXCoord(), user.getYCoord());
            gameBoard.updateBoard(' ', user.getXCoord(), user.getYCoord() + 1);

            //Same exact thing but for a different direction.
        } else if (direction == 'A') {
            if (user.getXCoord() - 1 < 1)
                cout << "That is out of bounds!\n";
            else
                user.setXCoord(user.getXCoord() - 1);

            if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'M') {
                result = battle(user);
                if (result == 'W') {
                    cout << "You beat the group of monsters!\n";
                    cout << "Total Treasure: " << user.getTreasure() << endl;
                    gameBoard.setMobs(gameBoard.getMobs() - 1);
                } else if (result == 'L') {
                    cout << "You lost because your whole party died.\n";
                    gameEnd = true;
                } else if (result == 'R') {
                    cout << "You ran successfully!\n";
                    int yTemp;
                    int xTemp;
                    while(!reallocate) {
                        yTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        xTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        if (gameBoard.getBoard()[yTemp][xTemp] == ' ') {
                            reallocate = true;
                        }
                    }
                    gameBoard.updateBoard('M', yTemp, xTemp);
                }
            } else if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'T') {
                user.setTreasure(user.getTreasure() + rand() % 10 + 1);
                cout << "Party's Treasure: " << user.getTreasure() << endl;
                gameBoard.setNumTreasures(gameBoard.getNumTreasures() - 1);
            }
            gameBoard.updateBoard('X', user.getXCoord(), user.getYCoord());
            gameBoard.updateBoard(' ', user.getXCoord() + 1, user.getYCoord());
        } else if (direction == 'S') {
            if (user.getYCoord() + 1 > gameBoard.getSize() - 2)
                cout << "That is out of bounds!\n";
            else
                user.setYCoord(user.getYCoord() + 1);

            if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'M') {
                result = battle(user);
                if (result == 'W') {
                    cout << "You beat the group of monsters!\n";
                    cout << "Total Treasure: " << user.getTreasure() << endl;
                    gameBoard.setMobs(gameBoard.getMobs() - 1);
                } else if (result == 'L') {
                    cout << "You lost because your whole party died.\n";
                    gameEnd = true;
                } else if (result == 'R') {
                    cout << "You ran successfully!\n";
                    int yTemp;
                    int xTemp;
                    while(!reallocate) {
                        yTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        xTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        if (gameBoard.getBoard()[yTemp][xTemp] == ' ') {
                            reallocate = true;
                        }
                    }
                    gameBoard.updateBoard('M', yTemp, xTemp);
                }
            }else if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'T') {
                user.setTreasure(user.getTreasure() + rand() % 10 + 1);
                cout << "Party's Treasure: " << user.getTreasure() << endl;
                gameBoard.setNumTreasures(gameBoard.getNumTreasures() - 1);
            }
            gameBoard.updateBoard('X', user.getXCoord(), user.getYCoord());
            gameBoard.updateBoard(' ', user.getXCoord(), user.getYCoord() - 1);
        } else if(direction == 'D') {
            if (user.getXCoord() + 1 > gameBoard.getSize() - 2)
                cout << "That is out of bounds!\n";
            else
                user.setXCoord(user.getXCoord() + 1);

            if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'M') {
                result = battle(user);
                if (result == 'W') {
                    cout << "You beat the group of monsters!\n";
                    cout << "Total Treasure: " << user.getTreasure() << endl;
                    gameBoard.setMobs(gameBoard.getMobs() - 1);
                } else if (result == 'L') {
                    cout << "You lost because your whole party died.\n";
                    gameEnd = true;
                } else if (result == 'R') {
                    cout << "You ran successfully!\n";
                    int yTemp;
                    int xTemp;
                    while(!reallocate) {
                        yTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        xTemp = rand() % (gameBoard.getSize() - 2) + 1;
                        if (gameBoard.getBoard()[yTemp][xTemp] == ' ') {
                            reallocate = true;
                        }
                    }
                    gameBoard.updateBoard('M', yTemp, xTemp);
                }
            } else if (gameBoard.getBoard()[user.getYCoord()][user.getXCoord()] == 'T') {
                user.setTreasure(user.getTreasure() + rand() % 10 + 1);
                cout << "Party's Treasure: " << user.getTreasure() << endl;
                gameBoard.setNumTreasures(gameBoard.getNumTreasures() - 1);
            }
            gameBoard.updateBoard('X', user.getXCoord(), user.getYCoord());
            gameBoard.updateBoard(' ', user.getXCoord() - 1, user.getYCoord());
        }else
            cout << "Please enter a valid direction or 'Q'.\n";
    }
    return 0;
}

//Holds a loop for one single battle against a whole group of monsters
char battle(Party& user) {
    int enemyChoice;                //User attack choice
    int partyChoice;                //Computer Attack choice
    char choice;                    //Holds menu choice
    char result;                    //Value returned
    int chance;                     //Hold random numbers
    bool battleOver = false;        //For loop
    MonsterParty enemy;             //Creates MonsterParty

    while (!battleOver) {
        cout << enemy << endl;
        showMenu();
        cin >> choice;
        cin.get();
        choice = toupper(choice);

        //If user wants to attack, it cycles through the targets they want to attack for each character.
        //After the whole team goes, the monsters go by random selection.
        if (choice == '1') {
            for (int i = 0; i < user.getSize(); i++) {
                bool valid = false;
                //Loop to make sure input is valid.
                while (!valid) {
                    cout << "Which enemy do you want to attack?\n";
                    cin >> enemyChoice;
                    enemyChoice -= 1;
                    if (enemyChoice < enemy.getSize() & enemyChoice >= 0)
                        valid = true;
                }
                //Gets a random number for 15% chance of miss
                chance = rand() % 6 + 1;
                if (chance < 2)
                    cout << "The attack missed.\n";
                else {
                    //Subtract power from health
                    enemy.getParty()[enemyChoice].setHealth((enemy.getParty()[enemyChoice].getHealth()) -
                                                            (user.getParty()[i].getPower()));
                    //Tests to see if enemy is dead.
                    if (enemy.getParty()[enemyChoice].getHealth() <= 0) {
                        //Deallocates the enemy by sliding them all down the list.
                        enemy.kill(enemyChoice);
                    }
                    //Test to see of they are all dead, to skip the rest of the loop.
                    if(enemy.getSize() == 0)
                        i = user.getSize();
                }
                cout << enemy << endl;
            }
            //Computers turn.
            //Same thing as above, with different chance.
            for (int i = 0; i < enemy.getSize(); i++) {
                partyChoice = rand() % (user.getSize()+1);
                chance = rand() % 2 + 1;
                if (chance == 1)
                    cout << "An enemy missed their attack.\n";
                else {
                    user.getParty()[partyChoice].setHealth(user.getParty()[partyChoice].getHealth() -
                                                           enemy.getParty()[i].getPower());
                    if (user.getParty()[partyChoice].getHealth() <= 0)
                        user.kill(partyChoice);
                }
            }
            //Tests to see if either of the teams are fully dead.
            if (enemy.getSize() == 0) {
                user.setTreasure(user.getTreasure() + enemy.getTreasure());
                result = 'W';
                battleOver = true;
            } else if (user.getSize() == 0) {
                result = 'L';
                battleOver = true;
            }
            //Displays team.
        } else if (choice == '2') {
            cout << user << endl;

            //User chose to run.
        } else if (choice == '3') {
            //5=10%, 4=20%, 3=30%, 2=40%, 1=50%
            chance = rand() % 11 + 1;       //Holds chance number

            //Random tests that should equal the rates above.
            if (enemy.getSize() == 5) {
                if (chance == enemy.getSize())
                    return 'R';
                else
                    cout << "You failed to run away!\n";
            } else if (enemy.getSize() == 4) {
                if (chance < 3)
                    return 'R';
                else
                    cout << "You failed to run away!\n";
            } else if (enemy.getSize() == 3) {
                if (chance % 3 == 0)
                    return 'R';
                else
                    cout << "You failed to run away!\n";
            } else if (enemy.getSize() == 2) {
                if (chance < 5)
                    return 'R';
                else
                    cout << "You failed to run away!\n";
            } else if (enemy.getSize() == 1) {
                if (chance <= 5)
                    return 'R';
                else
                    cout << "You failed to run away!\n";
            }
            //Enemy attacks if run fails.
            for (int i = 0; i < enemy.getSize(); i++) {
                partyChoice = rand() % (user.getSize()+1);
                chance = rand() % 2 + 1;
                if (chance == 1)
                    cout << "An enemy missed their attack.\n";
                else {
                    user.getParty()[partyChoice].setHealth(user.getParty()[partyChoice].getHealth() -
                                                           enemy.getParty()[i].getPower());
                    if (user.getParty()[partyChoice].getHealth() <= 0)
                        user.kill(partyChoice);
                }
            }
        } else
            cout << "That was not a valid choice\n";
    }
    //Returns 'W' for win, 'L' for loss, and 'R' for run.
    return result;
}


//Prints instructions
void showIntro(){
    cout << endl << endl;
    cout << "To move, enter W,A,S,D.\n";
    cout << "Or enter 'Q' to quit.\n";
}

//Prints menu in battle
void showMenu(){
    cout << "1. Attack\n";
    cout << "2. Display Party\n";
    cout << "3. Run\n";
}