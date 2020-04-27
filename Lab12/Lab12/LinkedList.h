/*
3.	Create a linked list class that can store Student information.  
	The Student information must include First Name, Last Name, MNumber 
	and may include any other additional information you wish.  
	In addition to any required members to make the linked list work, 
	include 3 of the above sort algorithms to support sorting by First Name, Last Name and MNumber 
	(each algorithm sorts by 1 of the 3) and includes a parameter for ascending or descending.  
	Seed your linked list with data for 50 students that will result in a different order for each of the fields.  
	Include a menu interface that allows the user to select the sort method and 
	direction and will display the sorted students on the screen.
*/

#include <iostream>

template <class T>
struct Node 
{ 
	Node* next;
	T data;

	Node<T>(T data) { this->data = data; }
};

template <class T>
class LinkedList 
{
	private:
		Node<T>* head;
		bool isAsc;
		int len;

	public:
		LinkedList() { head = nullptr; isAsc = false; len = 0; }
		LinkedList(bool isAsc) { head = nullptr; this->isAsc = isAsc; len = 0; }

		// Array to Linked List Constructor
		LinkedList(T** arr, int arrSize, bool isAsc) 
		{ 
			head = nullptr; 
			this->isAsc = isAsc; 
			len = 0; 
			
			if (isAsc)
			{
				for (int i = 0; i < arrSize; i++)
				{
					addItem(new T(*arr[i]));
				}
			}

			else
			{
				for (int i = arrSize-1; i >= 0; i--)
				{
					addItem(new T(*arr[i]));
				}
			}
		}

		//	Linked List to Array Helper Function
		T** toArray()
		{
			T** returnArr = new T*[size()];
			Node<T>* curr = head;
			for (int i = 0; i < size(); i++)
			{
				returnArr[i] = &curr->data;
				curr = curr->next;
			}
			return returnArr;
		}

		// Error Classes
		class ListUnderFlow {};
		class OutOfBounds {};
		class NonUniqueKey {};

		// Add Item Function
		void addItem(T* item) {
			Node<T>* newNode = new Node<T>(*item);
			if (head == nullptr) head = newNode;
			else 
			{
				newNode->next = head;
				head = newNode;
			}
			len++;
		}

		// Display Function
		void display()
		{
			Node<T>* curr = head;
			for (int i = 0; i < len; i++)
			{
				cout << curr->data << endl;
				curr = curr->next;
			}
		}

		// Size Getter Function
		int size() { return len; }


		// Destructor
		~LinkedList() 
		{
			Node<T>* curr = head;
			for (int i = 0; i < len; i++)
			{
				head = head->next;
				delete curr;
				curr = head;
				len--;
			}
			head = nullptr;
		}


};

