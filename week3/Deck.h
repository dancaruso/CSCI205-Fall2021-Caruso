/*
    Assignment:   CSCI205 Week 3 Lab
    Deck.h - a header file for a deck class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#ifndef DECK_H
#define DECK_H
#include "Card.h"
using namespace std;

class Deck {
    private:
        Card deckArray[52];
        int dealCounter = 0;      
    public:
        // Constructors
        Deck();

        // Methods
        void shuffle();
        Card deal();

        // Operators
        friend ostream& operator <<(ostream& stream, const Deck& deck);
};

#endif