/*
1.	Create a templated Binary Search Tree class with the following methods.  
	You may need or find it easier to create private methods and variable to simplify 
	or eliminate duplicate code in the methods below such as RotateRight, RotateLeft or NodeHeight.
a.	Constructor
b.	Destructor
c.	Insert – accepts a value, creates a node and inserts the node into the tree in the appropriate location.  
	This should rebalance the tree as necessary, so the tree remains balanced at all times.  
	If the value already exists in the tree, this should throw an error.
d.	Find – accepts a value, locates the value in the tree and returns a pointer to the node.  
	If the value isn’t in the tree, it will return a null pointer.
e.	Size – returns the number of elements in the tree as an integer.
f.	GetAllAscending – returns an array with each node stored in order from smallest to largest 
	(based on the sorting value, not the other data in the node).
g.	GetAllDescending – returns an array with each node stored in order from largest to smallest 
	(based on the sorting value, not the other data in the node).
h.	EmptyTree – removes all nodes in the tree in a way to avoid memory leaks.
i.	Remove – accepts a value, finds the value and removes it from the tree.  
	A pointer to the removed node is returned.  This should rebalance the tree as necessary,
	so the tree remains balanced at all times.
*/

#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
	Node<T>* leftChild;
	Node<T>* rightChild;
	T data;

	Node(T data) {
		this->data = data;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	Node() {}
};

// Data structure to return multiple objects. Used in helper method
template <typename T>
class DataPack {
public:
	Node<T>* parentNode;
	Node<T>* node;

	DataPack() {}
};

template <typename T>
class BinarySearchTree {

public:

	//Exceptions
	class ValueAlreadyFoundException {};

	Node<T>* root;
	BinarySearchTree() {
		root = nullptr;
	};
	~BinarySearchTree() {};

	Node<T>* find(T val) {
		return findNode(root, val);
	}

	void insert(T val) {

		if (root == nullptr) {
			root = new Node<T>(val);
			return;
		}

		Node<T>* parent = findNodeToInsert(root, val);
		Node<T>* newNode = new Node<T>(val);

		if (newNode->data < parent->data) {
			parent->leftChild = newNode;
		}
		else {
			parent->rightChild = newNode;
		}
	}

	Node<T>* remove(T val) {

		Node<T>* parent;
		Node<T>* removedNode;
		DataPack<T>* dat = new DataPack<T>();
		dat->node = root;   //start researching from root

		dat = findNode(dat,val);
		
		removedNode = dat->node;
		parent = dat->parentNode;

		if (removedNode->data < parent->data) {

			parent->leftChild = removedNode->leftChild;

			if (removedNode->rightChild != nullptr) {
				Node<T>* insertionPoint = findNodeToInsert(parent, removedNode->rightChild->data);

				if (removedNode->rightChild->data < insertionPoint->data) {
					insertionPoint->leftChild = removedNode->rightChild;
				}
				else {
					insertionPoint->rightChild = removedNode->rightChild;
				}
			}

		}
		else {
			parent->rightChild = removedNode->rightChild;

			if (removedNode->leftChild != nullptr) {
				Node<T>* insertionPoint = findNodeToInsert(parent, removedNode->leftChild->data);

				if (removedNode->leftChild->data < insertionPoint->data) {
					insertionPoint->leftChild = removedNode->leftChild;
				}
				else {
					insertionPoint->rightChild = removedNode->leftChild;
				}
			}
		}

		return removedNode;

	}

private:

	// Find a node with a given value. This accepts and returns a datapack since it also keeps track of the parent. This function is recursive
	DataPack<T>* findNode(DataPack<T>* data, T val) {
		if (data->node->data == val) {
			return data;
		}
		else {
			Node<T>* curr = data->node;
			data->parentNode = data->node;

			if (val < curr->data) {
				if (curr->leftChild == nullptr) {
					data->node = nullptr;
					return data;
				}
				data->node = curr->leftChild;
				return findNode(data, val);

			}
			else {
				if (curr->rightChild == nullptr) {
					data->node = nullptr;
					return data;
				}
				data->node = curr->rightChild;
				return findNode(data, val);
			}
		}
	}


// Find the node with a given value. This function is recursive
	Node<T>* findNode(Node<T>* curr, T val) {
		if (curr->data == val) {
			return curr;
		}
		else {
			if (val < curr->data) {
				if (curr->leftChild == nullptr) {
					return nullptr;
				}
				return findNode(curr->leftChild, val);

			}
			else {
				if (curr->rightChild == nullptr) {
					return nullptr;
				}
				return findNode(curr->rightChild, val);
			}
		}
	}

// Find the parent node after which a new node should be inserted. This function is recursive
	Node<T>* findNodeToInsert(Node<T>* curr,T val) {
		if (curr->data == val) {
			throw ValueAlreadyFoundException();
		}

		if (val < curr->data) {
			if (curr->leftChild == nullptr) {
				return curr;
			}
			return findNodeToInsert(curr->leftChild, val);

		}
		else {
			if (curr->rightChild == nullptr) {
				return curr;
			}
			return findNodeToInsert(curr->rightChild, val);
		}

	}

};