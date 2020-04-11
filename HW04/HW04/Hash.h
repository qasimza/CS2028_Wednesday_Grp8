/*
1.  Create a hash table that uses a 1D array and linear probing to handle collisions. 
	This table should have 500 available slots to hold items. 
	The hashing function can be as simple as taking the modulus of the input value for the number of available slots. 
	The hash table class should have the following members:
	a. Constructor
	b. Destructor
	c. Insert – accepts a value (integer), runs a hash function on the integer, and places it in the hash table. 
	   This function should return the number of spots it checks before inserting the item in the hash table 
	   so if it has no collisions, it should return 1 and if it has 3 collisions and then finds a spot on the 4th try, it return 4.
	d. Find – accepts a value (integer), locates the value in the hash table and returns the number of spots 
	   it checked to find the item or determine it is not in the hash table. 
	   This uses the same procedure as Insert to determine number of spots checked.
	e. Remove – accepts a value (integer), locates the value in the hash table and removes it from the hash table. 
	   It returns the number of spots it checked to find the item or determine it is not in the hash table. 
	   This uses the same procedure as Insert to determine number of spots checked.
	f. Print – prints all items in the hash table including an indication of which spots are not occupied.
*/
class Hash
{
};

