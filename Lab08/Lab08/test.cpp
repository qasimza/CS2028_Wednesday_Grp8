/*
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

#include "ODLinkedList.h"
#include "Item.h"
#include <iostream>

using namespace std;

int main() {
	string line = "---------------------------------------------------------";
	bool shouldRun = true;
	ODLinkedList<Item>* list = new ODLinkedList<Item>();

	while (shouldRun) {
		int selected = -1;
		// Get user to select a function or quit program
		cout << "Please select an option:" << endl;
		cout << "0 - Create new List" << endl;
		cout << "1 - Call addItem()" << endl;
		cout << "2 - Call getItem()" << endl;
		cout << "3 - Call isInList()" << endl;
		cout << "4 - Call isEmpty()" << endl;
		cout << "5 - Call size()" << endl;
		cout << "6 - Call seeNext()" << endl;
		cout << "7 - Call seePrev()" << endl;
		cout << "8 - Call seeAt()" << endl;
		cout << "9 - Call reset()" << endl;
		cout << "10 - Display List" << endl;
		cout << "11 - Quit Test Program" << endl;
		cout << line << endl;
		cin >> selected;

		switch (selected) {
			case 11: {
				shouldRun = false;
				break;
			}
			case 10: {
				list->display();
				break;
			}
			case 9: {
				list->reset();
				break;
			}
			case 8: {
				int tempOption = -1;
				cout << "Enter index position: ";
				cin >> tempOption;
				cout << line << endl;
				Item* temp = list->seeAt(tempOption);
				if (temp != nullptr) {
					temp->display();
				}
				else {
					cout << "Could not retreive item from given index position" << endl;
				}
				break;
			}
			case 7: {
				cout << "Previous item: " << endl;
				Item* ret = list->seePrev();

				if (ret != nullptr) {
					ret->display();
				}
				else {
					cout << "Reached end of List" << endl;
				}

				cout << line << endl;
				break;
			}
			case 6: {
				cout << "Next item: " << endl;
				Item* ret = list->seeNext();

				if (ret != nullptr) {
					ret->display();
				}
				else {
					cout << "Reached end of List" << endl;
				}

				cout << line << endl;
				break;
			}
			case 5: {
				cout<<"Current list size: " << list->size() << endl;
				cout << line << endl;
				break;
			}
			case 4: {
				if (list->isEmpty()) {
					cout << "List is empty" << endl;
				}
				else {
					cout << "List is not empty" << endl;
				}
				cout << line << endl;
				break;
			}
			case 3: {
				int SKU = -1;
				cout << "Enter the value of SKU: ";
				cin >> SKU;

				Item* item = new Item(SKU, "", 0.0, "");
				if (list->isInList(item)) {
					cout << "Item is in list" << endl;
				}
				else {
					cout << "Item is not in list" << endl;
				}
				cout << line << endl;
				break;
			}
			case 2: {
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
				list = new ODLinkedList<Item>();
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