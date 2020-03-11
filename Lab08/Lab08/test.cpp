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