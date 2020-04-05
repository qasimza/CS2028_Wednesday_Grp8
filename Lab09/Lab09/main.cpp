/*
	Modify your program from Homework 1 to:
	a.	Read the input file 
	b.	count the frequency of each word using the Binary Search Tree in step 1  
		This is likely not the best data structure for performing this function but 
		this is the data structure we are currently learning about so we will use it.
		*****CLASS FOR PART C IN SEPERATE FILE*****
	c.	Your program should create a class made up of a string and an int 
		that will be used as the type of the templated Binary Search Tree.  
		The string will be the word you are reading in and should be the key you are comparing at each level.  
		The int is the count for that word.  
		You may need to overload <, > and/or == operators for this class to be used in your Tree.  
		You can use the Find function to find the word in the tree then update the count via the returned node pointer.  
		If Find returns a null pointer, you will need to call Insert.  
		Once the file is read and loaded to the tree, let the user search for a word. 
		If it is found, return the count.  If it is not, indicate such.  
		Also, allow the user to see a list of all words with count in alphabetic order 
		both ascending and descending (Task 1-part f and g)
*/

#include "BinarySearchTree.h";
#include <iostream>

using namespace std;

int main() {

	BinarySearchTree<int>* tree = new BinarySearchTree<int>();
	tree->insert(5);
	tree->insert(6);
	tree->insert(1);
	tree->insert(7);
	tree->remove(6);

	cout << tree->find(1)->rightChild->data << endl;


}