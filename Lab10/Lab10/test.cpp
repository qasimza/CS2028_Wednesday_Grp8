/*
Task 3:  Modify your test program from Lab 8, Task 3 (test program) to test your Hash Table class.  
		 Include a screen shot of some of this testing in your lab report.
		 Complete this before moving on to task 4.

Task 5: Measure the performance of the linear probing and chained linking implementations of a hash table 
		(similar to Lab 7 task 4). To do this, modify both classes to keep track of the 
		number of times an item is compared in the chain for chained linking and the number 
		of times an additional index is checked for linear probing 
		(you only need to do this for the GetItem but you can do it for both if that is easier). 
		Create a test program that adds 50 randomly generated students (follow appropriate SKU Number rules) 
		to both hash tables then calls GetItem on the same student.  
		Record the total number of times the Hash Table needed to complete the 50 operations.  
		Repeat this measurement with an array size of 150, 200 and 250.  
		Include a table of the results from the 4 trials for the 2 different classes in your lab report.

****************FROM LAB 07*******************
Task 4:  Create a test program.
		 1.   Create a test program to test the 3 classes performance.
			  a.   This should instantiate each of the three classes.
			  b.   This should insert 30 randomly generated items into the array 
				   (using integers as the list data type might be the easiest way to do this).
			  c.   This should remove 25 items from the array.
			  d.   Individual inserts and removes from steps from b and c should be randomly selected 
				   rather than done sequentially.
			  e.   Every comparison and move operation in the AddItem and RemoveItem methods should be counted 
				   (except checks to see if an array location holds a nullptr).  
				   The total at the end of the run should be displayed to measure efficiency of the class.
			  f.   Every insert/remove operation should be identically performed against all 3 of the class instances.
		 2.   Run the program 100 times against the 3 versions of the class.  
			  Describe your results and how they compare with your expected results from the end of Task 3
		 3.   Increase the size of the array to hold 50 items. And rerun the program 100 times.  
			  Describe your results and how they compare with the previous step.
		 4.   Decrease the size of the array to hold 10 items and rerun the program 100 times.  
			  Describe your results and how they compare with the previous step.
		
****************FROM LAB 08*******************

Task 3:  Create a test program that has a menu allowing you to test each of the functions in your linked last class (Task 1).
1.   This should present the user with a choice of public member functions of 
	 your linked list class and ask which the user would like to try.
2.   When the user selects a member function, the program will prompt the user for any required information.  
	 For example, the GetItem function only requires a SKU as that is what is being compared 
	 but the AddItem requires the user to enter a SKU, Description, Price, UOM and optionally a QuantityOnHand.
3.   Test your program.  Include a screen shot of some of this testing in your lab report.
Complete this before moving on to task 4.

Task 4:  Create a visualization of your list using ASCII art.
1.  Modify your part class to include a display method that will output to the screen the contents of the class
	a.   This method should write directly to the screen.
	b.   This method does not need to display all members of the item, 
		 just key members (explain your choice of key members in your lab report).
	c.   This method should reuse members of the class as much as possible.
2.  Modify your linked list class to add a new public method to display the list.
	a.   This method should write directly to the screen.
	b.   This method should walk through the list and display every item in the list on the screen.  
		 The format of the output is up to you.
	c.   To display the contents of the item in the list, it should call the display member 
		 of the item (created in step 1 of this task).
	d.   This method should reuse members of the class as much as possible.
	e.   This method should not change the results of SeeNext method meaning it should not have a 
		 different value for the internal variable used by SeeNext after this method completes.
3.  Modify your test program from task 3 to include an option that calls this new method.
4.  Test your modifications.  Include in your lab report a screen shot showing the results of this new method with at least 4 items in your list.
*/

#include "HashTable.h"
#include "Item.h"
#include <iostream>

using namespace std;

int main() {
	string line = "---------------------------------------------------------";
	bool shouldRun = true;
	HashTable<Item>* list = new HashTable<Item>();

	while (shouldRun) {
		int selected = -1;
		// Get user to select a function or quit program
		cout << "Please select an option:" << endl;
		cout << "0 - Create new List" << endl;
		cout << "1 - Call addItem()" << endl;
		cout << "2 - Call removeItem()" << endl;
		cout << "3 - Call getItem()" << endl;
		cout << "4 - Call getLength()" << endl;
		cout << "5 - Display List" << endl;
		cout << "6 - Quit Test Program" << endl;
		cout << line << endl;
		cin >> selected;

		switch (selected) {
			case 6: {
				shouldRun = false;
				break;
			}
			case 5: {
				list->display();
				break;
			}

			case 4: {
				cout<<"Current list size: " << list->getLength() << endl;
				cout << line << endl;
				break;
			}

			case 2: {
				int SKU = -1;
				cout << "Enter the value of SKU: ";
				cin >> SKU;
				Item* item = list->removeItem(new Item(SKU, "", 0.0, ""));
				if (item == nullptr) {
					cout << "ERROR: Item Not Found" << endl;
				}
				else {
					item->display();
					cout << "Item removed from list" << endl;
				}
				cout << line << endl;
				break;
			}

			case 3: {
				int SKU = -1;
				cout << "Enter the value of SKU: ";
				cin >> SKU;
				Item* item = list->getItem(new Item(SKU, "", 0.0, ""));
				if (item == nullptr) {
					cout << "ERROR: Item Not Found" << endl;
				}
				else {
					item->display();
				}
				cout << line << endl;
				break;
			}
			case 1: {
				int SKU = -1;
				cout << "Enter the value of SKU: ";
				cin >> SKU;

				string description;
				cout << "Enter a description: ";
				cin.ignore();
				getline(cin,description);

				double price = -1;
				cout << "Enter the price: ";
				cin >> price;

				string UOM = "";
				cout << "Enter the UOM: ";
				cin >> UOM;

				int quantityOnHand = -1;
				cout << "Enter the quantity on hand. Enter -1 if you don't want to add it: ";
				cin >> quantityOnHand;

				Item* item;

				if (quantityOnHand == -1) {
					item = new Item(SKU,description,price,UOM);
				}
				else {
					item = new Item(SKU, description, price, UOM, quantityOnHand);
				}

				list->addItem(item);
				cout << "Item added" << endl;
				cout << line << endl;
				break;
			}
			case 0: {
				delete list;
				list = new HashTable<Item>();
				cout << "New list created" << endl;
				cout << line << endl;
				break;
			}
			default: {
				cout << "Enter a valid option" << endl;
				break;
			}
		}

	}

}