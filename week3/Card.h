/*
    Assignment:   CSCI205 Week 3 Lab
    Card.h - a header file for a card class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#ifndef CARD_H
#define CARD_H
using namespace std;

class Card {
    private:
        int cardValue;
        char cardSuit;
        bool faceDown = 1;

    public:
        // Constructors
        Card();
        Card(int valIn, char suitIn);
        Card(const Card& toCopy);

        // Getters
        int getCardValue();
        char getSuit();
        bool getFaceDown();

        // Setters
        void setCardValue(int valIn);
        void setSuit(char suitIn);
        void setFaceDown(bool tf);

        // Operators
        friend bool operator ==(const Card& c1, const Card& c2);
        friend bool operator !=(const Card& c1, const Card& c2);
        friend ostream& operator <<(ostream& stream, const Card& card);
};

#endif