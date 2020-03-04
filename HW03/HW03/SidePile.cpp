#include "SidePile.h"

SidePile::SidePile() {
	top = 0;
}

void SidePile::push(int value){
    if(top == MAX_SIZE){
        throw Overflow();
    }
	stackList[++top] = value;
}

int SidePile::pop(){
    if(top == 0)    {
        throw Underflow();
    }
    return stackList[--top];
}
