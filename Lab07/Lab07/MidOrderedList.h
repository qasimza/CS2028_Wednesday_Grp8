/*
Task 2
	Create a derived class from the class created in Task 1.
	This version of the class is to investigate the theory that by starting from the middle (index 12),
	fewer items will need to be moved on every insert
1.	This version should have the AddItem method start from the middle
	of the array when searching for a place to insert a new item.
2.	This version may move left or right when inserting but can’t go past the end of the array.
	If there is still room in the array but not in the direction needed, you will need to shift everything over when inserting.
*/

#include "OrderedList.h"

template<class T>
class MidOrderedList : public OrderedList<T>{
	
public:
	MidOrderedList(int size) : OrderedList<T>(size){}

	void addItem(T* d) {

		if (this->size == this->maxSize) {
			throw ListFull();
		}

		int counter = (this->maxSize / 2) - 1;

		// If counter is greater than array size, the counter would be set to the position of the last item in the list
		this->moveAndCompares++;
		if (counter > this->size - 1) {		
			counter = this->size - 1;
		}

		this->moveAndCompares++;
		if (counter == -1) {
			this->data[0] = d;
			this->size++;
		}

		// Logic to move left (size of array is smaller than maxSize / 2)
		else if (counter == (this->size - 1)) { 
			this->searchLeft(d, counter);
		}

		// Logic if size of array is same as MaxSize/2 or greater
		else {
			//Determine whether to move left or right with the below condition statement
			this->moveAndCompares++;
			if (*d < *(this->data[counter])) {	
				this->searchLeft(d, counter);
			}

			else {
				this->searchRight(d, counter);
			}
		}
		this->moveAndCompares++;  //For the else if above the else block

	}

private:

	void searchLeft(T* d, int counter) {
		bool isReached = false;
		while (!isReached) {
			this->moveAndCompares++;

			this->moveAndCompares++;
			if (*d >= *(this->data[counter])) {  // Add item to middle of list once correct position is detected and shift items over

				for (int i = (this->size - 1); i > counter; i--) {
					this->data[i + 1] = this->data[i];
					this->moveAndCompares+=2;
				}
				this->data[counter + 1] = d;
				isReached = true;
				this->size++;
			}

			else {
				counter--;
			}

			this->moveAndCompares++;
			if (counter == -1) {		// Add item to front after moving everything if the counter has reached the beginning of list

				for (int i = (this->size - 1); i > counter; i--) {
					this->data[i + 1] = this->data[i];
					this->moveAndCompares+=2;
				}
				this->data[counter + 1] = d;
				isReached = true;
				this->size++;
			}
		}
	}

	void searchRight(T* d, int counter) {
		bool isReached = false;
		while (!isReached) {
			this->moveAndCompares++;

			this->moveAndCompares++;
			if (*d <= *(this->data[counter + 1])) {  // Add item to middle of list once correct position is detected and shift items over

				for (int i = (this->size - 1); i > counter; i--) {
					this->data[i + 1] = this->data[i];
					this->moveAndCompares+=2;
				}
				this->data[counter + 1] = d;
				isReached = true;
				this->size++;
			}

			else {
				counter++;
			}

			this->moveAndCompares++;
			if (counter == this->size - 1) {		// Add item to end if the counter has reached the end of list
				this->data[this->size] = d;
				isReached = true;
				this->size++;
			}
		}
	}

};

