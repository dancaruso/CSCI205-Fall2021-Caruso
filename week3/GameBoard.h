/*
    Assignment:   CSCI205 Week 3 Lab
    GameBoard.h - a header file for a GameBoard class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Card.h"
#include "Deck.h"
using namespace std;

class GameBoard {
    private:
        Card board[2][52];
        bool winBoard[2][52];
        int boardSize;
        int colSize;
        int remainder;
        int rowSize;
        void randomize(Card cardArray[]);
        int winCounter;
        int selectCounter;
        Card firstSelect;
        Card secondSelect;

    public:
        //Constructors
        GameBoard(int size);

        // Methods
        void initialize();
        bool select(int x, int y);
        void display();
        bool checkMatch(int x1, int y1, int x2, int y2);
        bool checkForWin();
        Card getFirstSelect();
        Card getSecondSelect();
        void setFirstSelect(int x, int y);
        void setSecondSelect(int x, int y);
        int getWinCounter();
};

#endif