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

template <class Item>
class BlankOrderedList :public OrderedList<Item> {
};