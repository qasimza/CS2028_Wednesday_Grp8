/*
Task 4:  Create a test program.
1.	Create a test program to test the 3 classes performance.
a.	This should instantiate each of the three classes.
b.	This should insert 30 randomly generated items into the array 
	(using integers as the list data type might be the easiest way to do this).
c.	This should remove 25 items from the array.
d.	Individual inserts and removes from steps from b and c should be randomly selected rather than done sequentially.
e.	Every comparison and move operation in the AddItem and RemoveItem methods should be counted 
	(except checks to see if an array location holds a nullptr).  
	The total at the end of the run should be displayed to measure efficiency of the class.
f.	Every insert/remove operation should be identically performed against all 3 of the class instances.
2.	Run the program 100 times against the 3 versions of the class.  
	Describe your results and how they compare with your expected results from the end of Task 3
3.	Increase the size of the array to hold 50 items. And rerun the program 100 times.  
	Describe your results and how they compare with the previous step.
4.	Decrease the size of the array to hold 10 items and rerun the program 100 times.  
	Describe your results and how they compare with the previous step.
5.	Include in the lab report a screen shot(s) of the output of a test. 
	Include a discussion of how you designed your program to simplify running it and reporting results 100 times. 
	Discuss your methods for analyzing the results and why you believe those methods are valid.  
	Discuss other methods you discussed as a group and decided not to use.
*/

#include "OrderedList.h"
#include <iostream>

using namespace std;

int main() {

	int size = 7;
	OrderedList<int>* ol = new OrderedList<int>(size);

	ol->addItem(new int(10));
	ol->addItem(new int(9));
	ol->addItem(new int(8));
	ol->addItem(new int(7));
	ol->addItem(new int(13));
	ol->addItem(new int(1));
	ol->addItem(new int(-2));

	cout<<ol->isFull()<<endl;
	cout<<*(ol->removeItem(2))<<": returned"<<endl;
	cout<<ol->isFull()<<endl;

	for(int i = 0;i<size;i++) {
		cout<<*(ol->data[i])<<endl;
	}
