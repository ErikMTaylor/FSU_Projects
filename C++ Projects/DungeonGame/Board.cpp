#include "Board.h"

Board::Board(int _size):maxTreasures(_size/2),maxMobs(_size) {
    size = _size;
//allocate a new board
    boardState = new char*[size];
    for(int i = 0; i < size; i++) {
        boardState[i] = new char[size];
        for(int j = 0; j < size; j++) {
            if(i == 0 || i == size-1) {
                boardState[i][j]= '-';
                continue;
            } else if (j == 0 || j == size-1) {
                boardState[i][j] = '|';
                continue;
            }
            boardState[i][j] = ' ';
        }
    }
//set the entrance
    setupEntrance();
//set the treasures
    setupTreasure();
//set the mobs
    setupMobs();
}
Board::~Board() {
    cout << "Destroying game board state..." << endl;
    for(int i = 0; i < size; i++) {
        delete [] boardState[i];
    }
    delete [] boardState;
    cout << "Destroying mob state..." << endl;
    for(int i = 0; i < numMobs; i++) {
        cout << "Destroying mob " << i << endl;
        delete [] mobs[i];
    }
    cout << "Destroying mob list..." << endl;
    delete [] mobs;
    cout << "Destroying treasure state..." << endl;
    for(int i = 0; i < numTreasures; i++) {
        cout << "Destroying treasure " << i << endl;
        delete [] treasures[i];
    }
    delete [] treasures;
}
ostream& operator<<(ostream& s, const Board& db) {
    for(int i = 0; i < db.size; i++) {
        for(int j = 0; j < db.size; j++) {
            s << db.boardState[i][j] << "\t";
        }
        s << endl<<endl;
    }
    return s;
}
void Board::setupEntrance() {
//find the entry
    srand(time(0));
//pick a number 0-3 to figure out what wall the entrance will be on
    int wall = rand()%4;
//pick a number 1-8 to figure out what position on that wall the entrance 
    //will be at (this keeps the door from being in a corner)
    int pos = rand()%(size-2) + 1;
    switch(wall) {
        case 0:
            boardState[pos][0] = 'X';
            boardState[pos-1][0] = '-';
            boardState[pos+1][0] = '-';
            x_enter = 0;
            y_enter = pos;
            break;
        case 1:
            boardState[0][pos] = 'X';
            boardState[0][pos-1] = '|';
            boardState[0][pos+1] = '|';
            x_enter = pos;
            y_enter = 0;
            break;
        case 2:
            boardState[pos][size-1] = 'X';
            boardState[pos-1][size-1] = '-';
            boardState[pos+1][size-1] = '-';
            x_enter = size - 1;
            y_enter = pos;
            break;
        case 3:
            boardState[size-1][pos] = 'X';
            boardState[size-1][pos-1] = '|';
            boardState[size-1][pos+1] = '|';
            x_enter = pos;
            y_enter = size - 1;
            break;
    }
}
void Board::setupTreasure() {
    numTreasures = rand() % maxTreasures + 1;
    treasures = new int*[numTreasures];
    for(int i = 0; i < numTreasures; i++) {
//get row
        int row = rand()%(size-2) + 1;
//get column
        int column = rand()%(size-2) + 1;
//place treasures
        boardState[row][column] = 'T';
        treasures[i] = new int[2];
        treasures[i][0] = row;
        treasures[i][1] = column;
        cout << "Allocated treasure " << i << endl;
    }
}
void Board::setupMobs() {
    numMobs = rand() % maxMobs + 1;
    mobs = new int*[numMobs];
    for(int i = 0; i < numMobs; i++) {
//get row
        int row = rand()%(size-2) + 1;
//get column
        int column = rand()%(size-2) + 1;
//place treasures
        boardState[row][column] = 'M';
        mobs[i] = new int[2];
        mobs[i][0] = row;
        mobs[i][1] = column;
        cout << "Allocated mob " << i << endl;
    }
}

//Takes in a char and coords to change a section of the board.
void Board::updateBoard(char change, int x, int y){
    boardState[y][x] = change;
}


int Board::getEnterX() const{
    return x_enter;
}

int Board::getEnterY() const{
    return y_enter;
}

int Board::getSize() const {
    return size;
}

char** Board::getBoard() const {
    return boardState;
}

int Board::getMobs() const {
    return numMobs;
}

void Board::setMobs(int given) {
    numMobs = given;
}

int Board::getNumTreasures() const {
    return numTreasures;
}

void Board::setNumTreasures(int given) {
    numTreasures = given;
}