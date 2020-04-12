#ifndef STACK_H
#define STACK_H

class StackOverFlow {};
class StackUnderFlow {};
class StackEmpty {};

// Class taken from Lab 6 

template <class T>
class Stack
{
private:
	T** arr = nullptr;
	int size = 0;
	int capacity = 0;

public:
	Stack() {};
	Stack(int length) {
		arr = new T * [length];
		capacity = length;
	}

	void push(T* item) {
		if (size == capacity) {
			throw StackOverFlow();
		}
		arr[size++] = item;
	}

	T* pop() {
		if (size == 0) {
			throw StackUnderFlow();
		}
		return arr[--size];
	}

	T* top() {
		if (size == 0) {
			throw StackUnderFlow();
		}
		return arr[size - 1];
	}

	int length() {
		return size; 
	}

	void empty() {
		while (size > 0) {
			delete arr[--size];
		}
	}
};

#endif
