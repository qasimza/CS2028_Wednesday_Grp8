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
#include "MidOrderedList.h"
#include "BlankOrderedList.h"
#include <cmath>

using namespace std;

void insert(OrderedList<int>* ol, MidOrderedList<int>* mol, BlankOrderedList<int>* bol) {
	int val = (rand() % 100) + 1;

	//cout << "Added: " << val << endl;

	ol->addItem(new int(val));
	mol->addItem(new int(val));
	bol->addItem(new int(val));
}

void remove(OrderedList<int>* ol, MidOrderedList<int>* mol, BlankOrderedList<int>* bol) {
	int rem = rand() % ol->getSize();
	//int rem = 0;

	/*cout << endl;
	cout<<"Removed from OL: "<< *(ol->removeItem(rem))<<endl;
	cout << "Removed from MOL: " << *(mol->removeItem(rem)) << endl;
	cout << "Removed from BOL: " << *(bol->removeItem(rem)) << endl;*/

	ol->removeItem(rem);
	mol->removeItem(rem);
	bol->removeItem(rem);
}

int main() {

	int loopTimes = 10;
	int insertRemoveCount = 100;
	int size = 1000;
	long seed = 123456789;  // Seeded so that it is easier to recreate experiment
	srand(seed);

	long olCount = 0;
	long molCount = 0;
	long bolCount = 0;

	int insertionCount = 0;
	int removeCount = 0;

	OrderedList<int>* ol;
	MidOrderedList<int>* mol;
	BlankOrderedList<int>* bol;

	for (int i = 0; i < loopTimes; i++) {

		ol = new OrderedList<int>(size);
		mol = new MidOrderedList<int>(size);
		bol = new BlankOrderedList<int>(size);

		int insertionCount = 0;
		int removeCount = 0;

		while (insertionCount < insertRemoveCount || removeCount < insertRemoveCount) {

			if (insertionCount == 0) {
				insert(ol, mol, bol);
				insertionCount++;
			}

			else {
				if (rand() % 2 == 1) {
					if (insertionCount < insertRemoveCount && ol->getSize() != ol->getMaxSize()) {
						insert(ol, mol, bol);
						insertionCount++;
					}
				}
				else {
					if (removeCount < insertRemoveCount && mol->getSize() != 0) {
						remove(ol, mol, bol);
						removeCount++;
					}
				}
			}

		}

		olCount += ol->getMoveAndCompares();
		molCount += mol->getMoveAndCompares();
		bolCount += bol->getMoveAndCompares();

		//cout << "TEMP RESULTS" << endl;
		//cout << "OL Moves and compares average: " << (float)olCount << endl;
		//cout << "MOL Moves and compares average: " << (float)molCount<< endl;
		//cout << "BOL Moves and compares average: " << (float)bolCount<< endl;
		//cout << endl;

		ol->makeEmpty();
		mol->makeEmpty();
		bol->makeEmpty();

		delete ol;
		delete mol;
		delete bol;
	}

	//	Print results

	cout << "--------------------------" << endl;
	cout << "OL Moves and compares average: " << (float)olCount / loopTimes << endl;
	cout << "MOL Moves and compares average: " << (float)molCount / loopTimes << endl;
	cout << "BOL Moves and compares average: " << (float)bolCount / loopTimes << endl;
	cout << endl;

}