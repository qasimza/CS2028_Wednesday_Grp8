#include "Card.h"

#ifndef SIDEPILE_H
#define SIDEPILE_H

class SidePile
{
    private:
        Card* top = nullptr;
        int cardsRemaining = 0;

    public:
        SidePile(){};
        void push(int);
        int pop();
        int cardsLeft(){return cardsRemaining;}

};

#endif
