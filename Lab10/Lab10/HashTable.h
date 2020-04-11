/*
Task 1:  Create a Hash Table that uses linear probing.
		 1.	Create a new project.  You can name this whatever you like.
		 2.	Design and implement Hash Table class using linear probing as described in class.  
			This class should be a template.  
			The template is expected to have overloaded the == operator 
			and the string object conversion  (you don’t need to write these overloads as part of your Hash table, 
			it will be in the data type you are storing in your hash table).
			a.	The class should have the following methods fully implemented.
				i.	Constructor – This should have an overload indicating the maximum number of items 
					the Hash table can store.  The default value is 100.
				ii.	Hash – This should be a private function that accepts a string and returns an int.  
					For this, we are going to add the sum of all the ASCII values for the passed in string 
					and modulus by the maximum size of the table.
				iii.AddItem – adds an item from the list.
				iv.	RemoveItem – searches the list for the given item.  
					If found, it removes it from the list and returns it.  
					If not found, it returns a null pointer.
				v.	GetItem – searches the list for a given item.  
					If found, it returns a pointer to the item but doesn’t remove it from the list.
				vi.	GetLength – returns an int indicating the number of items in the table.
				vii.	Destructor
			b.	All items passed to or from the class should be done so via a 
				pointer rather than by value.
			c.	Make sure you don’t have any memory leaks.
		Complete this before moving on to task 2.
*/