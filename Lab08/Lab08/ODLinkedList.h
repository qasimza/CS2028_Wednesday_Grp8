#pragma once
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
class ODLinkedList{
private:
	T* head;
public:
	//Constructor
	ODLinkedList(T);
	//AddItem – adds an item from the list
	void addItem(T);
	//GetItem – searches the list for the given item.  If found, it removes it from the list and returns it
	T geteItem(T);


};