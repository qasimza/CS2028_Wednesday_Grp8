#ifndef DECK_H
#define DECK_H

struct Card
{
        int value = 0;
        Card* next = nullptr;
        Card(int value) {this->value = value;}
};

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

		// Exception
		class Underflow {};
};

#endif
