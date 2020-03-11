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

//private:
//	T* max = nullptr;
//	int maxInd = 0;

public:
	BlankOrderedList(int size) : OrderedList<T>(size) {
		for (int i = 0; i < this->maxSize; i++) {
			this->data[i] = nullptr;
		}
	}

	//void addItem(T* d) {
	//	if (this->size == this->maxSize) {
	//		throw ListFull();
	//	}

	//	if (this->size == 0) {
	//		this->maxInd = (this->maxSize / 2) - 1;
	//		this->max = d;
	//		this->data[maxInd] = d;
	//		this->size++;
	//		//cout << *d << " added to index pos: " << ((this->maxSize / 2) - 1) << endl;
	//		return;
	//	}

	//	if (*d > *max) {
	//		this->max = d;
	//	}

	//	// Add element to middle if array is empty
	//	this->moveAndCompares++;

	//	//Logic when item being added is the largest item
	//	if (*d >= *max) {
	//		
	//		// If maximum value should be inserted at the end of the array
	//		if (this->maxInd == this->maxSize - 1) {

	//			//Shift to left
	//			//	Logic to detect upto which point to shift everything over (Until an emtpy spot is encoutered)
	//				int lowerBound = this->maxSize - 2;
	//				for (int i = lowerBound; i >= 0; i--) {
	//					if (this->data[i] == nullptr) {
	//						break;
	//					}
	//					lowerBound--;
	//				}
	//				//  Shift everything upto an empty spot
	//				for (int i = lowerBound+1; i < this->maxSize; i++) {
	//					this->data[i-1] = this->data[i];
	//				}

	//				// Add value to correct position
	//				this->data[this->maxInd] = d;
	//				this->size++;
	//				this->max = d;
	//				this->size++;
	//				return;
	//				//cout << *d << " added to index pos: " << counter << endl;
	//			}

	//		// If current value should be inserted between the current largest value in the last and the end of list
	//		else {
	//			
	//			int ind = this->maxInd + (((this->maxSize - 1) - this->maxInd) / 2);
	//			if (ind == this->maxInd) {
	//				ind++;
	//			}
	//			this->data[ind] = d;
	//			this->maxInd = ind;
	//			this->max = d;
	//			this->size++;
	//			return;
	//		}

	//	}

	//	// Logic for when the new value is definitely not the largest value
	//	bool isReached = false;
	//	int counter = 0;
	//	int indexOfPreviousValue = -1;

	//	while (!isReached) {
	//		//Check values only if current value is not null
	//	
	//		if (this->data[counter] != nullptr) {

	//			if (counter == this->maxSize) {
	//				this->printEverything();
	//				cout << "Max: "<<*this->max << endl;
	//				cout << *d << endl;
	//			}

	//			if (*d <= *this->data[counter]) {
	//				int diff = abs(counter - indexOfPreviousValue);  //Difference between index of last value encoutered and current positon

	//				 // If there is/are empty spot(s) at and before the required position
	//				this->moveAndCompares++;
	//				if (diff > 1) {
	//					int ind = indexOfPreviousValue + (diff / 2);

	//					if (ind == counter) {
	//						ind--;
	//					}

	//					if (ind == indexOfPreviousValue) {
	//						ind++;
	//					}

	//					this->data[ind] = d;
	//					isReached = true;
	//					this->size++;
	//					return;
	//					//cout << *d << " added to index pos: " << lowerBound + (diff / 2) << endl;
	//				}

	//				else {

	//					//	Logic to detect upto which point to shift everything over (Until an emtpy spot is encoutered)
	//					int upperMoveBound = counter;
	//					for (int i = counter + 1; i < this->maxSize; i++) {
	//						this->moveAndCompares++;
	//						if (this->data[i] == nullptr) {
	//							break;
	//						}
	//						upperMoveBound++;
	//					}

	//					if (upperMoveBound > this->maxInd) {
	//						this->maxInd++;
	//					}

	//					//  Shift everything upto an empty spot
	//					for (int i = (upperMoveBound); i >= counter; i--) {
	//						this->data[i + 1] = this->data[i];
	//						//this->moveAndCompares + 2;
	//					}
	//					this->data[counter] = d;
	//					isReached = true;
	//					this->size++;
	//					return;
	//					//cout << *d << " added to index pos: " << counter << endl;
	//				}
	//			}
	//			indexOfPreviousValue = counter;
	//		}
	//		counter++;
	//	}


	//}

	void addItem(T* d) {

		if (this->size == this->maxSize) {
			throw ListFull();
		}

		// Add element to middle if array is empty
		this->moveAndCompares++;
		if (this->size == 0) {
			this->data[(this->maxSize / 2) - 1] = d;
			this->size++;
			//cout << *d << " added to index pos: " << ((this->maxSize / 2) - 1) << endl;
			return;
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
				if (counted == this->size) {
					int ind = lowerBound + (((this->maxSize - 1) - lowerBound) / 2);

					if (this->data[ind] != nullptr) {
						ind++;
						cout << "being called" << endl;
					}
					/*if (*d == 80) {
						cout <<"80 index: "<< (((this->maxSize - 1) - lowerBound) % 2) << endl;
						cout << counter << endl;
					}*/
					this->data[ind] = d;
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

	T* removeItem(int ind, bool shouldDisplay) {
		if (this->size == 0) {
			throw ListEmpty();
		}

		if (ind < 0 || ind > this->size - 1) {
			cout << "requested index to be removed: "<<ind << endl;
			throw OutOfBoundsIndex();
		}

		int count = 0;
		int currentIndex = 0;

		for (int i = 0; i < this->maxSize; i++) {
			this->moveAndCompares++;
			currentIndex = i;

			if ((this->data[i]) != nullptr) {
				if (shouldDisplay) {
					cout << "hit at index: " << i << "for index: " << ind<<endl;
				}
				//cout << *(this->data[i])<< " : "<<i<<" - ";

				if (count == ind) {
					break;
				}

				count++;
			}
		}

		//cout << endl;

		//Make sure the recalculate max Value index and set max pointer
		//if (currentIndex == this->maxInd) {
		//	if (shouldDisplay) {
		//		cout << "current Index" << currentIndex << endl;
		//		cout << "max index: " << this->maxInd << endl;
		//		cout << "count: " << count << endl;
		//		cout << "max equals: "<<*this->max << endl;
		//	}
		//	for (int i = maxInd - 1; i > 0; i--) {
		//		if (this->data[i] != nullptr) {
		//			this->maxInd = i;
		//			this->max = this->data[i];
		//		}
		//	}
		//}

		/*if (shouldDisplay) {
			cout << "removing from index pos: " << currentIndex << endl;
			cout << "removed Value: " << *(this->data[currentIndex])<< endl;
		}*/

		T* ans = this->data[currentIndex];
		this->data[currentIndex] = nullptr;

		if (ans == nullptr) {
			printEverything();
			cout << "something wrong here: requiredIndex: " <<ind << " :currentIndex: "<<currentIndex<<": Number of values encountered: "<<count<<": current Size: "<<this->size<< endl;
			this->printEverything();
			exit(1);
		}

		else {
			this->size--;
		}
		return ans;
	}
	
	void printEverything() {
		cout << "---------------------------------" << endl;
		for (int i = 0; i < this->maxSize; i++) {
			if (this->data[i] == nullptr) {
				cout << "null" << " || ";
			}
			else {
				cout << *this->data[i] << " || ";
			}
		}
		cout << endl;
	}

};