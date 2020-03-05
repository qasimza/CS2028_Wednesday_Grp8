#ifndef SIDEPILE_H
#define SIDEPILE_H

class SidePile
{
    private:
		static const int MAX_SIZE = 5;
        int top; //Top is also a count of the number of cards in the pile
		int stackList[MAX_SIZE];

    public:
        SidePile();
        void push(int);
        int pop();
		int peek();
        int cardsLeft(){return top;}

		// Exception
		class Underflow {};
		class Overflow {};
};

#endif
