/*
    Assignment:   CSCI205 Week 3 Lab
    main.cpp - main function for concentration game

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Card.h"
#include "Deck.h"
#include "GameBoard.h"
using namespace std;

int main() {
    /*Deck d1;
    cout << d1 << endl;
    cout << endl;
    
    cout << d1.deal() << endl;
    cout << d1 << endl;

    cout << d1.deal() << endl;
    cout << d1 << endl;

    d1.shuffle();
    cout << d1 << endl; */

    /*
    cout << std::setw(5) << left << "2C";
    cout << std::setw(5) << left << "10D";
    cout << std::setw(5) << left << "5D" << endl;
    cout << std::setw(5) << left << "AS";
    cout << std::setw(5) << left << "10H";
    cout << std::setw(5) << left << "QC" << endl;
    */

    int boardSize;
    int x1;
    int y1;
    int x2;
    int y2;
    int playAgain = 1;

    while (playAgain == 1) {  // Main while loop to create repeat games
        cout << "Please enter board size (total number of cards on board. Example: 8 means 4 pairs of cards): " << endl;
        cin >>  boardSize;
        GameBoard gameBoard(boardSize);
        gameBoard.initialize();

        while (gameBoard.checkForWin() == 0) {  // Main game loop to keep running until all matches are made
            gameBoard.display();
            cout << "Please enter the x coordinate of the card you want to view (column 1 is on the left): ";
            cin >> x1;
            cout << "Please enter the y coordinate of the card you want to view (row 1 is the top row): ";
            cin >> y1;
            gameBoard.select(x1, y1);
            gameBoard.setFirstSelect(x1, y1);
            gameBoard.display();
            cout << "Please enter the x coordinate of the card you want to view (column 1 is on the left): ";
            cin >> x2;
            cout << "Please enter the y coordinate of the card you want to view (row 1 is the top row): ";
            cin >> y2;
            gameBoard.select(x2, y2);
            gameBoard.setSecondSelect(x2, y2);
            gameBoard.display();
            gameBoard.checkMatch(x1, y1, x2, y2);
            gameBoard.checkForWin();
            cout << endl;
        }
        
        cout << "Play again? Enter 1 for yes,  0 for no: ";
        playAgain = 2;
        while ((playAgain != 1) && (playAgain != 0)) {
            cin >> playAgain;
            if ((playAgain != 1) && (playAgain != 0)) {
                cout << "Invalid choice. Please enter 1 to play again or 0 to quit." << endl;
            }
        }
    }
    cout << "Thanks for playing!  Goodbye" << endl;
}
