/*
Task 3
	Create another derived class from the class created in Task 1.  
	This version of the class is to investigate leaving blank spots (points to a null) 
	in the array can reduce the number of moves when inserting.
1.	Modify the AddItem method to insert an item halfway between any two items in the array where it belongs.  
	It should only move items in the array if the inserting item sits between two items that are in contiguous locations.
2.	Modify the RemoveItem method so that it will not move any items in the array.
3.	Include in your lab submission a paragraph for each of the 3 versions of the class a 
	description of what is trying to be achieved, what the strengths and weaknesses are and how you think it will perform.
	Complete this before moving on to task 4.
*/

#include "OrderedList.h"
#include <math.h>

template <class T>
class BlankOrderedList :public OrderedList<T> {

public:
	BlankOrderedList(int size) : OrderedList<T>(size) {
		for (int i = 0; i < this->maxSize; i++) {
			this->data[i] = nullptr;
		}
	}

	void addItem(T* d) {

		// Add element to middle if array is empty
		this->moveAndCompares++;
		if (this->size == 0) {
			this->data[(this->maxSize / 2) - 1] = d;
			this->size++;
			//cout << *d << " added to index pos: " << ((this->maxSize / 2) - 1) << endl;
			return;
		}

		if (this->size == this->maxSize) {
			throw ListFull();
		}

		bool isReached = false;
		int counter = 0;
		int lowerBound = -1;
		int upperMoveBound = 0;
		int counted = 0;

		while (!isReached) {
			this->moveAndCompares++;

			if (this->data[counter] != nullptr) {

				//	Logic if item being added is the largest item so far
				this->moveAndCompares + 2;
				if (counted == this->size && !isReached) {
					this->data[lowerBound + (((this->maxSize - 1) - lowerBound) / 2)] = d;
					isReached = true;
					this->size++;
					return;
					//cout << *d << " added to index pos: " << lowerBound + (((this->maxSize - 1) - lowerBound) / 2) << endl;
				}

				this->moveAndCompares++;
				if (*d <= *this->data[counter]) {

					int diff = abs(counter - lowerBound);  //Difference between index of last value encoutered and current positon

					 // If there is/are empty spot(s) at and before the required position
						this->moveAndCompares++;
						if (diff > 1) {
							this->data[lowerBound + (diff / 2)] = d;
							isReached = true;
							this->size++;
							return;
							//cout << *d << " added to index pos: " << lowerBound + (diff / 2) << endl;
						}

						else {

						//	Logic to detect upto which point to shift everything over (Until an emtpy spot is encoutered)
							upperMoveBound = counter;
							for (int i = counter+1; i < this->maxSize; i++) {
								this->moveAndCompares++;
								if (this->data[i] == nullptr) {
									break;
								}
								upperMoveBound++;
							}

						//  Shift everything upto an empty spot
							for (int i = (upperMoveBound); i >= counter; i--) {
								this->data[i + 1] = this->data[i];
								this->moveAndCompares+2;
							}
							this->data[counter] = d;
							isReached = true;
							this->size++;
							return;
							//cout << *d << " added to index pos: " << counter << endl;
						}
				}
				else {

					//Logic to shift everything to the left if end of array is reached
					if (counter == this->maxSize - 1) {
						upperMoveBound = counter;
						//	Logic to detect upto which point to shift everything over (Until an emtpy spot is encoutered)
						lowerBound = counter - 1;
						for (int i = counter - 1; i >= 0; i--) {
							this->moveAndCompares++;
							if (this->data[i] == nullptr) {
								break;
							}
							lowerBound--;
						}

						//  Shift everything upto an empty spot
						for (int i = (lowerBound + 1); i < upperMoveBound; i++) {
							this->data[i - 1] = this->data[i];
							this->moveAndCompares + 2;
						}
						this->data[counter] = d;
						isReached = true;
						this->size++;
						return;
						//cout << *d << " added to index pos: " << counter << endl;
					}
				}
				lowerBound = counter;
				counted++;

			}
			
			counter++;
		}

	}

	T* removeItem(int ind) {
		if (this->size == 0) {
			throw ListEmpty();
		}

		if (ind < 0 || ind > this->size) {
			throw OutOfBoundsIndex();
		}

		int count = 0;
		int requiredIndex = 0;

		for (int i = 0; i < this->maxSize; i++) {
			this->moveAndCompares++;
			requiredIndex = i;

			if ((this->data[i]) != nullptr) {
				
				//cout << *(this->data[i])<< " : "<<i<<" - ";
				count++;

				if (count - 1 == ind)
					break;

			}
		}

		cout << endl;

		T* ans = this->data[requiredIndex];
		this->data[requiredIndex] = nullptr;

		if (ans == nullptr) {
			cout << "something wrong here: Index: " <<ind << " :requiredIndex: "<<requiredIndex<<": count : "<<count<<": current Size: "<<this->size<< endl;
		}

		this->size--;
		return ans;
	}

};