#ifndef STACK_H
#define STACK_H

class StackOverFlow{};
class StackUnderFlow{};
class StackEmpty{};

template <class T>

class Stack
{
    private:
        T** arr = nullptr;
        int size = 0;
        int capacity = 0;

    public:
        Stack(){};
        Stack(int length){arr = new T*[length]; capacity = length;}
        void push(T*);
        T* pop();
        T* top();
        int length(){return size;}
        void empty();
};

#endif
