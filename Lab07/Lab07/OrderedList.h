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
		data = new T*[size];
		maxSize = size;
	}

	void addItem(T *d) {

		if (size == 0) {
			data[0] = d;
			size++;
			return;
		}

		if (size == maxSize) {
			throw ListFull();
		}

		bool isReached = false;
		int counter = 0;

		while (!isReached) {

			if (counter == size) {
				data[size] = d;
				isReached = true;

			} else if (*d < *data[counter] || *d == *data[counter]) {

				for (int i = (size - 1); i >= counter; i--) {
					data[i + 1] = data[i];
				}
				data[counter] = d;
				isReached = true;
			}

			counter++;

		}
		size++;

	}

	T* removeItem(int ind) {
		if (size == 0) {
			throw ListEmpty();
		}

		if (ind < 0 || ind > size) {
			throw OutOfBoundsIndex();
		}

		T* ans  = data[ind];

		for (int i = ind; i < size; i++) {
			data[i] = data[i + 1];
		}
		size--;

		return ans;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == maxSize;
	}

	void makeEmpty() {
		for (int i = 0; i < size; i++) {
			delete data[i];
		}
		size = 0;
	}

};
