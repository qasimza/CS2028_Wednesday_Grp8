#include "Deck.h"

class Underflow{};

Deck::Deck(int* deckArray, int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        this->push(deckArray[i]);
    }
}

void Deck::push(int value)
{
    Card* card = new Card(value);

    if(top == nullptr)
    {
        top = card;
        bottom = card;
    }

    else
    {
        bottom->next = card;
        bottom = bottom->next;
    }

    cardsRemaining++;
}

int Deck::pop()
{
    if(top == nullptr)
    {
        throw Underflow();
    }

    int value = top->value;
    Card* temp = top;
    top = top->next;
    delete temp;
    cardsRemaining--;
    return value;
}

int Deck::peek()
{
    return top->value;
}
