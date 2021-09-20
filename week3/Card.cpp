/*
    Assignment:   CSCI205 Week 3 Lab
    Card.cpp - an implementation file for a card class header

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#include <iostream>
#include "Card.h"
using namespace std;

// Constructor
Card::Card(int valIn, char suitIn) {
    setCardValue(valIn);
    setSuit(suitIn);
}

Card::Card(const Card& toCopy) {
    setCardValue(toCopy.cardValue);
    setSuit(toCopy.cardSuit);
}

Card::Card() {
    setCardValue(0);
    setSuit('X');
} 

// Getters
int Card::getCardValue() {
    return cardValue;
}

char Card::getSuit() {
    return cardSuit;
}

bool Card::getFaceDown() {
    return faceDown;
}

// Setters
void Card::setCardValue(int valIn) {
    cardValue = valIn;
}

void Card::setSuit(char suitIn) {
    cardSuit = suitIn;
}

void Card::setFaceDown(bool tf) {
    faceDown = tf;
}

// Operator Overloading
bool operator ==(const Card& c1, const Card& c2) {
    bool cardsEqual = 0;
    if((c1.cardValue == c2.cardValue) && (c1.cardSuit == c2.cardSuit)) {
        cardsEqual = 1;
    }
    return cardsEqual;
}

bool operator !=(const Card& c1, const Card& c2) {
    bool cardsNotEqual = 0;
    if((c1.cardValue != c2.cardValue) && (c1.cardSuit == c2.cardSuit)) {
        cardsNotEqual = 1;
    }
    return cardsNotEqual = 1;
}

ostream& operator <<(ostream& stream, const Card& card) {
    if (card.cardValue == 11) {
        stream << 'J' << card.cardSuit;
    }
    else if(card.cardValue == 12) {
        stream << 'Q' << card.cardSuit;
    }
    else if(card.cardValue == 13) {
        stream << 'K' << card.cardSuit;
    }
    else if(card.cardValue == 14) {
        stream << 'A' << card.cardSuit;
    }
    else {
        stream << card.cardValue << card.cardSuit;
    }
    return stream;
}
