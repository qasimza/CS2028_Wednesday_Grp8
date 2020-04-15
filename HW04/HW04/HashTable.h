/*
1.  Create a hash table that uses a 1D array and linear probing to handle collisions. 
	This table should have 500 available slots to hold items. 
	The hashing function can be as simple as taking the modulus of the input value for the number of available slots. 
	The hash table class should have the following members:
	a. Constructor
	b. Destructor
	c. Insert – accepts a value (integer), runs a hash function on the integer, and places it in the hash table. 
	   This function should return the number of spots it checks before inserting the item in the hash table 
	   so if it has no collisions, it should return 1 and if it has 3 collisions and then finds a spot on the 4th try, it return 4.
	d. Find – accepts a value (integer), locates the value in the hash table and returns the number of spots 
	   it checked to find the item or determine it is not in the hash table. 
	   This uses the same procedure as Insert to determine number of spots checked.
	e. Remove – accepts a value (integer), locates the value in the hash table and removes it from the hash table. 
	   It returns the number of spots it checked to find the item or determine it is not in the hash table. 
	   This uses the same procedure as Insert to determine number of spots checked.
	f. Print – prints all items in the hash table including an indication of which spots are not occupied.
*/

#pragma once
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
	int maxSize = 500;
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
	virtual int insert(T* item) {

		if (size == maxSize) {
			throw TableFullException();
		}

		int ret = 1;

		int index = hash(*item);

		bool shouldLoop = true;

		while (shouldLoop) {
			if (data[index] != nullptr && data[index] != deleteMarker && *((data[index])->data) != *item) {
				index += 1;
				index %= maxSize;
				ret++;
			}
			else {
				shouldLoop = false;
			}
		}

		if (data[index] == nullptr || data[index] == deleteMarker) {
			size++;
		}

		data[index] = new HashNode<T>(item);
		return ret;
	}

	virtual int remove(T* item) {
		int ret = 1;
		int index = hash(*item);
		int counter = 0;  //to prevent infinite loop
		HashNode<T>* curr;

		//Not found, and no value has ever been inserted with this particular key
		if (data[index] == nullptr) {
			return 0;
		}


		curr = data[index];

		while (curr != nullptr && curr != deleteMarker) {

			if (counter == maxSize) { //Was not able to find, made a complete loop
				return ret;
			}

			if (*(curr->data) == *item) { //item found
				T* tempData = curr->data;
				delete data[index];
				data[index] = deleteMarker;  //mark removed location as delete marker
				size--;
				return ret;
			}

			ret++;
			index += 1;
			index %= maxSize;
			curr = data[index];
			counter++;
		}

		return ret;

	}

	virtual void print() {
		for (int i = 0; i < maxSize; i++) {
			HashNode<T>* curr = data[i];
			if (curr == deleteMarker) {
				cout << "deleted" << endl;
			}
			else if (curr == nullptr) {
				cout << "nullPTR" << endl;
			}
			else {
				cout << * (curr->data) << endl;
			}
		}
	}

	virtual int find(T* item) {
		int index = hash(*item);
		int counter = 0;  //to prevent infinite loop
		HashNode<T>* curr;
		int ret = 1;

		//Not found, and no value has ever been inserted with this particular key
		if (data[index] == nullptr) {
			return 0;
		}


		curr = data[index];

		while (curr != nullptr && curr != deleteMarker) {

			if (counter == maxSize) { //Was not able to find, made a complete loop
				return ret;
			}

			if (*(curr->data) == *item) { //item found
				T* tempData = curr->data;
				return ret;
			}

			ret++;
			index += 1;
			index %= maxSize;
			curr = data[index];
			counter++;
		}

		return ret;

	}

	int getLength() {
		return size;
	}

	virtual ~HashTable<T>() {
		delete deleteMarker;
		delete[] data;
	}


protected:
	int hash(int key) {
		return (abs(key) % (maxSize+1 - size));   //+1 to make sure division by zero doesn't occur
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