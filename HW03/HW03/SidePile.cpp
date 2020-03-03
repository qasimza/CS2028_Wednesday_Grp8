#include "SidePile.h"

class Overflow{};

const int MAX_SIZE = 5;

void SidePile::push(int value)
{
    if(cardsRemaining == MAX_SIZE)
    {
        throw Overflow();
    }

    Card* card = new Card(value);

    if(top == nullptr)
    {
        top = card;
    }

    else
    {
        card->next = top;
        top = card;
    }

    cardsRemaining++;
}

int SidePile::pop()
{
    if(cardsRemaining == 0)
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
