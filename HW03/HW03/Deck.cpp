#include "Deck.h"



// Constructor
Deck::Deck(int* deckArray, int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        this->push(deckArray[i]);
    }
}

// Add
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


// Remove
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

//  Peek
int Deck::peek()
{
    return top->value;
}
