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

template <class T>
void Stack<T>::push(T* item)
{
    if (size == capacity)
    {
        throw StackOverFlow();
    }
    arr[size++] = item;
}

template <class T>
T* Stack<T>::pop()
{
    if (size == 0)
    {
        throw StackUnderFlow();
    }
    return arr[--size];
}

template <class T>
T* Stack<T>::top()
{
    if (size == 0)
    {
        throw StackUnderFlow();
    }
    return arr[size - 1];
}

template <class T>
void Stack<T>::empty()
{
    while (size > 0)
    {
        delete arr[--size];
    }
}

#endif

