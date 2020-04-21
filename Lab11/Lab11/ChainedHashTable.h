/*
Task 4:  Create a derived class from your Hash table that implements a chained hash table.
		 Use your linked list class from Lab 8, Task 1.
		 Modify your test program from Task 3 to test this new class.
		 Include a screen shot of some of this testing in your lab report.
Complete this before moving on to task 5.
*/

#pragma once
#include "HashTable.h"
#include "ODLinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
class ChainedHashTable : public HashTable<T> {

public:

	class TableFullException {};

	ODLinkedList<T>** lists;

	ChainedHashTable() {
		init();
	}

	ChainedHashTable(int maxSize) :HashTable<T>(maxSize) {
		init();
	}

	void addItem(T* item) {

		if (this->size == this->maxSize) {
			throw TableFullException();
		}

		int index = this->hash(string(*item));

		//add only if item is not present in list
		if (!((lists[index])->isInList(item))) {  //Inefficient, but this has to be done because ODList allows duplicated to be stored
			(lists[index])->addItem(item);
			(this->size)++;
		}

	}

	T* removeItem(T* item) {
		int index = this->hash(string(*item));
		T* retItem = lists[index]->getItem(item);  //ODList->getItem() is equivalent to hashTable->remove(). I know, confusing method names

		if (retItem != nullptr) {
			(this->size)--;
		}

		return retItem;
	}

	void display() {
		for (int i = 0; i < this->maxSize; i++) {
			lists[i]->display();
		}
	}

	~ChainedHashTable() {
		delete[] lists;
	}

	T* getItem(T* item) {
		int index = this->hash(string(*item));
		T* ret = lists[index]->getItem(item);  //ODList->getItem() is equivalent to hashTable->remove(). I know, confusing method names

		if (ret != nullptr) {
			lists[index]->addItem(ret);  //Since getItem() removes item from list, it must be added back into the list. There is no function to just search and return value without deleting node in ODList
		}

		return ret;

	}

protected:
	void init() {
		lists = new ODLinkedList<T> * [this->maxSize];
		for (int i = 0; i < this->maxSize; i++) {
			lists[i] = new ODLinkedList<T>();
		}
	}

};