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

template <class Item>
class MidOrderedList:public OrderedList<Item>{
};