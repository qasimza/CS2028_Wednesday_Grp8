#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        int value = 0;
        Card* next = nullptr;
        Card(int value){this->value = value;}
};

#endif
