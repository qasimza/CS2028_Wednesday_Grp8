#include "Card.h"

#ifndef DECK_H
#define DECK_H

class Deck
{
    private:
        Card* top = nullptr;
        Card* bottom = nullptr;
        int cardsRemaining = 0;

    public:
        Deck(int*, int);
        void push(int);
        int pop();
        int peek();
        int cardsLeft(){return cardsRemaining;}

};

#endif
