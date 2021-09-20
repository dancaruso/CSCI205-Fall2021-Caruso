/*
    Assignment:   CSCI205 Week 3 Lab
    Deck.cpp - an implementation file for a deck class header

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/16/2021
*/

#include <iostream>
#include <time.h>
#include "Deck.h"
#include "Card.h"
using namespace std;

// No-argument constructor to populate a deck. With a for loop that executes 52 times, one for each card, this algorithm should be O(n)
Deck::Deck() {
    for(int i = 0; i < 52; ++i) {
        if(i < 13) {
            deckArray[i] = Card(i+2, 'D');
        }
        if((i >= 13) && (i < 26)) {
            deckArray[i] = Card(i-11, 'H');
        }
        if((i >= 26) && (i < 39)) {
            deckArray[i] = Card(i-24, 'C');
        }
        if((i >= 39) && (i <= 51)) {
            deckArray[i] = Card(i-37, 'S');
        }
    }
}

// shuffle() - performs 104 card swaps for a deck represented by an array of card objects
void Deck::shuffle() {
    Card tempCard;
    srand(time(0));
    for (int i = 0; i < 103; ++i) {                                     // Shuffle by swapping two cards 103 times
        int tradePlace1 = dealCounter + (rand() % (51 - dealCounter));  // Generate a random number representing a first index to switch, avoiding any indices having been dealt
        int tradePlace2 = dealCounter + (rand() % (51 - dealCounter));  // Generate a random number representing a second index to switch, avoiding any indices having been dealt
        tempCard = deckArray[tradePlace1];                              // Set tempCard to the card at the first random index
        deckArray[tradePlace1] = deckArray[tradePlace2];                // Set card at random index 2 to random index 1
        deckArray[tradePlace2] = tempCard;                              // Set card from random index 1 to random index 2
    }
}

// deal() - I believe this is O(1) notation since it only executes one time as called, it doesn't execute n number of times based on any for or while loops
Card Deck::deal() {
    Card dealtCard = deckArray[dealCounter];
    deckArray[dealCounter].setCardValue(0);
    deckArray[dealCounter].setSuit('X');
    dealCounter += 1;

    return dealtCard;
}

ostream& operator <<(ostream& stream, const Deck& deck) {
    for (int i = 0; i < 52; ++i) {
        if ((i + 1) % 13 == 0) {
            stream << deck.deckArray[i] << endl;            
        }
        else {
            stream << deck.deckArray[i] << " ";
        }
    }
    return stream;
}
