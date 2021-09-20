/*
    Assignment:   CSCI205 Week 3 Lab
    GameBoard.cpp - an implementation file for a GameBoard class header

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#include <iostream>
#include <typeinfo>
#include <vector>
#include <math.h>
#include <iomanip>
#include "GameBoard.h"
#include "Card.h"
#include "Deck.h"
using namespace std;

// randomize - performs 104 swaps for a given array of card objects
void GameBoard::randomize(Card cardArray[]) {
    Card tempCard;
    srand(time(0));
    for (int i = 0; i < 103; ++i) {
        int tradePlace1 = rand() % (sizeof(&cardArray) - 1);
        int tradePlace2 = rand() % (sizeof(&cardArray) - 1);
        tempCard = cardArray[tradePlace1];
        cardArray[tradePlace1] = cardArray[tradePlace2];
        cardArray[tradePlace2] = tempCard;
    }
}

// Constructor
GameBoard::GameBoard(int size) {
    if((size % 2) == 0) {
        boardSize = size;
    }
    else {
        boardSize = size + 1;
    }
}

// initialize - creates a game board by creating a deck, shuffling it, populating the desired board size, and randomizing the card placement on the board
void GameBoard::initialize() {
    // Clear the board
    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < 52; ++x) {
            board[y][x] = Card(0, 'X');
        }
    }
    // Create a deck, game card array, and card variable to copy, shuffle the deck 
    Deck deck;
    Card cardArray[104];
    deck.shuffle();
    Card c1;
    // Populate the game card array with a dealt card and a match of it
    int arrayPopulate = 0;
    for (int i = 0; i < (boardSize / 2); ++i) {
        c1 = deck.deal();
        cardArray[arrayPopulate] = c1;
        cardArray[arrayPopulate + 1] = Card(c1);
        arrayPopulate += 2;
    }
    // Shuffle the card array, use dealt cards to populate game board
    randomize(cardArray);
    int cardCounter = 0;
    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < (boardSize / 2); ++x) {
            board[y][x] = cardArray[cardCounter];
            cardCounter += 1;
            cout << board[y][x] << endl;
        }
    }
    winCounter = 52 - boardSize;
}

// select - selects a card from the board, returns 0 if the selection was successful, 1 if not
// This should be O(1) since there's no looping or iterating - it will only execute once as called
bool GameBoard::select(int x, int y) {
    if ((board[y - 1][x - 1].getFaceDown() == 0) || ((x - 1) > boardSize) || ((y - 1) >= 2) || ((x - 1) < 0) || ((y - 1) < 0)) {
        return 0;
    }
    else {
        board[y - 1][x - 1].setFaceDown(0);
        return 1;
    }
}

// display - draws the game board. If my understanding is correct, this should be O(n) since it performs two separate non-nested loops.
void GameBoard::display() {
    for (int i = 0; i < (boardSize / 2); ++i) {
        if (board[0][i].getFaceDown() == 1) {
            cout << std::setw(5) << left << "XX";    
        }
        else {
            cout << board[0][i] << "   ";
        }
    }
    cout << endl;
    for (int j = 0; j < (boardSize / 2); ++j) {
        if (board[1][j].getFaceDown() == 1) {
            cout << std::setw(5) << left << "XX";
        }
        else {
            cout << board[1][j] << "   ";
        }
    }
    cout << endl;
}

// checkMatch - checks to see if two selected cards match
bool GameBoard::checkMatch(int x1, int y1, int x2, int y2) {
    if (firstSelect == secondSelect) {
        winCounter += 2;
        cout << "Pairs Left: " << ((52 - winCounter) / 2) << endl;
        return 1;
    }
    else {
        board[y1 - 1][x1 - 1].setFaceDown(1);
        board[y2 - 1][x2 - 1].setFaceDown(1);
        cout << "Pairs Left: " << ((52 - winCounter) / 2) << endl;
        return 0;
    }
}

// checkForWin - performs a simple check to see if the game has been won...should be O(1) since it only performs once as called with no looping or iterating
bool GameBoard::checkForWin() {
    if (winCounter == 52) {
        return 1;
    }
    else {
        return 0;
    }
}

// Some nifty getters and setters
Card GameBoard::getFirstSelect() {
    return firstSelect;
}

Card GameBoard::getSecondSelect() {
    return secondSelect;
}

int GameBoard::getWinCounter() {
    return winCounter;
}

void GameBoard::setFirstSelect(int x, int y) {
    firstSelect = board[y - 1][x - 1];
}

void GameBoard::setSecondSelect(int x, int y) {
    secondSelect = board[y - 1][x - 1];
}
