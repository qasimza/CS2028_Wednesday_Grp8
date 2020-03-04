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
class MidOrderedList: public OrderedList<T> {

public:

	MidOrderedList(int size):OrderedList<T>(size){}

	void addItem(T *d) {

		cout<<"Here"<<endl;
		if (this->size == this->maxSize) {
			throw ListFull();
		}

		bool isReached = false;
//		int counter = static_cast<int>(static_cast<float>(this->maxSize)/2);
//		cout<<static_cast<int>(this->maxSize)/2;
		int counter = 3;

		while (!isReached) {

			if (counter > this->size) {
				if (*d >= *this->data[counter] && counter <= this->size) {
					for (int i = (this->size - 1); i >= counter; i--) {
						this->data[i + 1] = this->data[i];
					}
					this->data[this->size] = d;
					isReached = true;
					this->size++;
					break;
				}

				if (counter == 0) {
					for (int i = (this->size - 1); i >= 0; i--) {
						this->data[i + 1] = this->data[i];
					}
					this->data[0] = d;
					isReached = true;
					this->size++;
					break;
				}
//				cout<<"<<etdl;
				counter--;

			} else if (*d <= *this->data[counter]) {

				if (*d > *this->data[counter - 1]) {
					for (int i = (this->size - 1); i >= counter; i--) {
						this->data[i + 1] = this->data[i];
					}

					this->data[counter] = d;
					isReached = true;
					this->size++;
					break;
				}
				counter--;
			}

			else {
				if (*d <= *this->data[counter + 1]) {
					for (int i = (this->size - 1); i >= counter; i--) {
						this->data[i + 1] = this->data[i];
					}

					this->data[counter] = d;
					isReached = true;
					this->size++;
					break;
				}
				counter++;
			}
		}

	}

};

