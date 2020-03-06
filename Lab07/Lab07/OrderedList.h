#pragma once
/*
Task 1:
1.	Create a new project.  You can name this whatever you like.
2.	Design and implement an ordered list class using an array of pointers as described in class. 
	This class should be a template.  The template is expected to have overloaded the >, < and == operators.
a.	The class should have an array that holds 25 items.
b.	The AddItem method should start at the front of the array (index 0) when searching for a place to insert a new item.
c.	The RemoveItem method should ensure that the items in the array are still in order and there are no empty spots between items.
d.	The class should include IsEmpty, IsFull and MakeEmpty methods.
3.	Any error conditions encountered such as the item to be removed doesn’t exist or
	the list is full when trying to add an item should throw a custom error class.
*/

#include <iostream>

using namespace std;

class ListFull {
};
class ListEmpty {
};
class OutOfBoundsIndex {
};


template<class T>
class OrderedList {

public:
	int maxSize = 0;
	T **data;
	int size = 0;

	int moveAndCompares = 0;

public:
	OrderedList(int size) {
		this->data = new T*[size];
		this->maxSize = size;
	}

	void addItem(T *d) {

		if (this->size == 0) {
			this->data[0] = d;
			this->size++;
			return;
		}

		if (this->size == this->maxSize) {
			throw ListFull();
		}

		bool isReached = false;
		int counter = 0;

		while (!isReached) {

			if (counter == this->size) {
				this->data[this->size] = d;
				isReached = true;

			} else if (*d < *this->data[counter] || *d == *this->data[counter]) {

				for (int i = (this->size - 1); i >= counter; i--) {
					this->data[i + 1] = this->data[i];
				}
				this->data[counter] = d;
				isReached = true;
			}

			counter++;

		}
		this->size++;

	}

	T* removeItem(int ind) {
		if (this->size == 0) {
			throw ListEmpty();
		}

		if (ind < 0 || ind > this->size) {
			throw OutOfBoundsIndex();
		}

		T* ans  = this->data[ind];

		for (int i = ind; i < this->size; i++) {
			this->data[i] = this->data[i + 1];
		}
		this->size--;

		return ans;
	}

	bool isEmpty() {
		return  this->size == 0;
	}

	bool isFull() {
		return  this->size == this->maxSize;
	}

	void makeEmpty() {
		for (int i = 0; i < this->size; i++) {
			delete this->data[i];
		}
		this->size = 0;
	}
//
//public:
//	int getSize() { return this->size;}
//
//	int getMaxSize() { return this->maxSize; }
//
//	T** getData() { return this->data; }
//
//	int getMovesAndCompare() { return this->moveAndCompares; }
//
//	void setSize(int val) { this->size = val; }
//
//	void setMovesAndCompare(int val) { this->moveAndCompares = val; }
//
//	void incrementSize(int increment) { this->size += increment; }
//
//	void incrementMovesAndCompare(int increment) { this->moveAndCompares += increment; }

};
