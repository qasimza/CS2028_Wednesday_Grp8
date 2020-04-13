/*
Task 1:  Create a Hash Table that uses linear probing.
		 1.	Create a new project.  You can name this whatever you like.
		 2.	Design and implement Hash Table class using linear probing as described in class.  
			This class should be a template.  
			The template is expected to have overloaded the == operator 
			and the string object conversion  (you don’t need to write these overloads as part of your Hash table, 
			it will be in the data type you are storing in your hash table).
			a.	The class should have the following methods fully implemented.
				i.	Constructor – This should have an overload indicating the maximum number of items 
					the Hash table can store.  The default value is 100.
				ii.	Hash – This should be a private function that accepts a string and returns an int.  
					For this, we are going to add the sum of all the ASCII values for the passed in string 
					and modulus by the maximum size of the table.
				iii.AddItem – adds an item from the list.
				iv.	RemoveItem – searches the list for the given item.  
					If found, it removes it from the list and returns it.  
					If not found, it returns a null pointer.
				v.	GetItem – searches the list for a given item.  
					If found, it returns a pointer to the item but doesn’t remove it from the list.
				vi.	GetLength – returns an int indicating the number of items in the table.
				vii.	Destructor
			b.	All items passed to or from the class should be done so via a 
				pointer rather than by value.
			c.	Make sure you don’t have any memory leaks.
		Complete this before moving on to task 2.
*/

#pragma once

#include <string>
#include <iostream>
using namespace std;

template <typename T>
class HashNode {

public:
	T* data;

	HashNode<T>(T* val) {
		data = val;
	}

};

template <typename T>
class HashTable {

protected:
	int maxSize = 100;
	int size = 0;
	HashNode<T>** data;
	HashNode<T>* deleteMarker;

public:
	
	class TableFullException {};

	HashTable<T>() {
		init();
	}
	
	HashTable<T>(int maxSize) {
		this->maxSize = maxSize;
		init();
	}

	//Inspired by https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/?ref=rp
	virtual void addItem(T* item) {

		if (size == maxSize) {
			throw TableFullException();
		}

		int index = hash(string(*item));

		bool shouldLoop = true;

		while (shouldLoop) {
			if (data[index] != nullptr && data[index] != deleteMarker && 
				*((data[index])->data) != *item) {
				index += 1;
				index %= maxSize;
			}
			else {
				shouldLoop = false;
			}
		}

		if (data[index] == nullptr || data[index] == deleteMarker) {
			size++;
		}

		data[index] = new HashNode<T>(item);
	}

	virtual T* removeItem(T* item) {
		int index = hash(string(*item));
		int counter = 0;  //to prevent infinite loop
		HashNode<T>* curr;

		//Not found, and no value has ever been inserted with this particular key
		if (data[index] == nullptr) {
			return nullptr;
		}

		
		curr = data[index];

		while (curr != nullptr && curr != deleteMarker) {

			if (counter == maxSize) { //Was not able to find, made a complete loop
				return nullptr;
			}

			if (*(curr->data) == *item) { //item found
				T* tempData = curr->data;
				delete data[index];
				data[index] = deleteMarker;  //mark removed location as delete marker
				size--;
				return tempData;
			}

			index += 1;
			index %= maxSize;
			curr = data[index];
			counter++;
		}

		return nullptr;

	}

	virtual void display() {
		for (int i = 0; i < maxSize; i++) {
			HashNode<T>* curr = data[i];
			if (curr == deleteMarker) {
				cout << "deleted" << endl;
			}
			else if (curr == nullptr) {
				cout << "nullPTR" << endl;
			}
			else {
				cout << (string)*(curr->data) << endl;
			}
		}
	}

	virtual T* getItem(T* item) {
		int index = hash(string(*item));
		int counter = 0;  //to prevent infinite loop
		HashNode<T>* curr;

		//Not found, and no value has ever been inserted with this particular key
		if (data[index] == nullptr) {
			return nullptr;
		}


		curr = data[index];

		while (curr != nullptr && curr != deleteMarker) {

			if (counter == maxSize) { //Was not able to find, made a complete loop
				return nullptr;
			}

			if (*(curr->data) == *item) { //item found
				T* tempData = curr->data;
				return tempData;
			}

			index += 1;
			index %= maxSize;
			curr = data[index];
			counter++;
		}

		return nullptr;

	}

	int getLength() {
		return size;
	}

	virtual ~HashTable<T>() {
		delete deleteMarker;
		delete[] data;
	}


protected:
	int hash(string key) {
		int ret = 0;

		for (int i = 0; i < key.size(); i++) {
			ret += key[i];
		}

		return (ret%maxSize);
	}

	virtual void init() {
		deleteMarker = new HashNode<T>(nullptr);
		data = new HashNode<T> * [maxSize];
		size = 0;

		for (int i = 0; i < maxSize; i++) {
			data[i] = nullptr;
		}
	}

};