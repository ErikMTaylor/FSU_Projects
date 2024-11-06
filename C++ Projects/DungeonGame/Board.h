#ifndef ASSIGMENT7_BOARD_H
#define ASSIGMENT7_BOARD_H

#include<iostream>
using namespace std;

class Board {
    friend ostream& operator<<(ostream& s, const Board& db);
public:
    Board(int _size);
    ~Board();

    int getEnterX() const;
    int getEnterY() const;
    int getSize() const;
    char** getBoard() const;
    int getNumTreasures() const;
    int getMobs() const;

    void setMobs(int);
    void setNumTreasures(int);

    void updateBoard(char, int, int);

private:
//data
    const int maxTreasures;
    int numTreasures;
    const int maxMobs;
    int numMobs;
    int size;
    char** boardState;
    int** treasures;
    int** mobs;
//entrance
    int x_enter;
    int y_enter;
//exit
    int x_exit;
    int y_exit;
//functionality
    void setupEntrance();
    void setupTreasure();
    void setupMobs();
};



#endif //ASSIGMENT7_BOARD_H
