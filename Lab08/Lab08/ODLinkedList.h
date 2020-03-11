#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
Task 1:  Create an ordered double linked list class.
1.   Create a new project.  You can name this whatever you like.
2.   Design and implement an ordered linked list class as described in class.  
	 This class should be a template.  
	 The template is expected to have overloaded the >, < and == operators.
a.   The class should have the following methods fully implemented.
		i.     Constructor
		ii.    AddItem – adds an item from the list
		iii.   GetItem – searches the list for the given item.  If found, it removes it from the list and returns it.  
			   If not found, it returns a null pointer.
		iv.    IsInlist – returns a bool indicating if the given item is in the list.
		v.     IsEmpty – returns a bool indicating if the list is empty.
		vi.    Size – returns an int indicating the number of items in the list.
		vii.   SeeNext – returns the item without removing it from the list at a given location in the list.  
			   The class will maintain the next location and will start at the first item in the list.  
			   When it gets to the last item in the list, it will return a null pointer after it gets past the last item.  
			   If the list is empty, this will throw an error.  
			   2 calls to SeeNext will return the 2 items next to each other in the list 
			   unless SeeAt or Reset is called in between the 2 calls (or the first call returns the last 
			   item in the list).
		viii.  SeePrev – Same as SeeNext except in the other direction.
		ix.    SeeAt – Finds an item at a location in the list (int passed in from user) and
			   returns the item without removing it.  If the location passed by the user is 
			   past the end of the list, this will throw an error.  
			   This will set the location used by SeeNext to point at the item after the item returned.
		x.     Reset – resets the location that the SeeNext function uses to point at the 
			   first item in the list.
		xi.    Destructor – make sure you remove all items to avoid memory leaks
b.   All items passed to or from the class should be done so via a pointer rather than by value.
c.   Make sure you don’t have any memory leaks.
Complete this before moving on to task 2.
*/



template <class T>
class Node {
public:
	T value;
	Node<T> *next;
	Node<T> *prev;
	//Constructor
	Node<T>(T newValue) {
		value = newValue;
		prev = nullptr;
		next = nullptr;
	}
};

template <class T>
class ODLinkedList{
private:
	Node<T> *head;
	Node<T> *curr;
	int len; //Number of items
public:
	//Constructor
	ODLinkedList() {
		head = nullptr;
		curr = nullptr;
		len = 0;
	}
	//Oprator overloads


	//Exceptions
	class ListUnderFlow {};
	class OutOfBounds {};
	class NonUniqueKey {};
	//Other functions

	void addItem(T *item) {
		Node<T>* newNode = new Node<T>(*item);
		if (head == nullptr) { //Adding when there are no items
			head = newNode;
			curr = newNode;
		}
		else if (newNode->value < head->value) { // If adding at the beginning of the list
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else { // Look for position to add the pointer at
			Node<T> *position = head;
			while (position->next != nullptr && newNode->value > position->value) {
				position = position->next;
			}
			if (newNode->value > position->value) { //Adding at the end
				newNode->prev = position;
				newNode->next = position->next;
				position->next = newNode;
			}
			else {	//Adding in the middle
				newNode->next = position;
				newNode->prev = position->prev;
				position->prev = newNode;
				newNode->prev->next = newNode;
			}
			
		}			
		len++; //Increment size after successful addition
		}
		
	
	T* getItem(T* item) {
		T *returnItem = nullptr;
		Node<T>* position = head;

		if (head->value == *item) { //If item is at the beginning
			returnItem = &head->value;
			head = head->next;
			delete position;
			len--;
		}
		else if (head != nullptr){ //If list is not-empty
			for (int i = 0; i < len; i++) {
				if (position->value == *item) {
					returnItem = &position->value;
					position->prev->next = position->next;
					if (position->next != nullptr) position->next->prev = position->prev;
					delete position;
					len--;
					break;
				}
				position = position->next;
			}
		}
		return returnItem;
		
	}
	
	bool isInList(T* item) {
		Node<T>* position = head;
		for (int i = 0; i < len; i++) {
			if (position->value == *item) {
				return true;
			}
		}
		return false;
	}

	bool isEmpty() { return head == nullptr; };
	int size() { return len; };
	void reset() { curr = head->next; };
	
	~ODLinkedList(){

	}

	T seeNext() {
		
		if(len == 0) {
			throw ListUnderFlow();
		}

		if(curr == nullptr) {
			return nullptr;
		}
		curr = curr->next;
		return curr;
	}

	T seePrev() {
		
		if(len == 0) {
			throw ListUnderFlow();
		}

		if(curr == nullptr) {
			return nullptr;
		}

		curr = curr->previous;
		return curr;
	}

	T seeAt(int location)
	{
		if(location > (len - 1) || location < 0) throw OutOfBounds();
		
		Node<T>* iterator = head;
		while(location != 0)
		{
			iterator = iterator->next;
			location--;
		}
		return iterator->value;
	}

	//Function for printing list
	void printList() {
		
		if (isEmpty()) {
			cout << "Empty List" << endl;
		}
		else {
			Node<T>* position = head;
			for (int i = 0; i < len; i++) {
				cout << position->value << " ";
				position = position->next;
			}
		}
	}
};

