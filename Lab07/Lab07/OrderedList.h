#pragma once
/*
Task 1:
1.	Create a new project.  You can name this whatever you like.
2.	Design and implement an ordered list class using an array of pointers as described in class. 
	This class should be a template.  The template is expected to have overloaded the >, < and == operators.
a.	The class should have an array that holds 25 items.
b.	The AddItem method should start at the front of the array (index 0) when searching for a place to insert a new item.
c.	The RemoveItem method should ensure that the items in the array are still in order and there are no empty spots between items.
d.	The class should include IsEmpty, IsFull and MakeEmpty methods.
3.	Any error conditions encountered such as the item to be removed doesn’t exist or
	the list is full when trying to add an item should throw a custom error class.
*/

template <class Item>
class OrderedList {
};