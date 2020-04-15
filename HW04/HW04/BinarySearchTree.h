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
#include "Queue.h"  //From lab 6
#include "Stack.h"  //From lab 6

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

	~Node() {
		delete leftChild;
		leftChild = NULL;
		delete rightChild;
		rightChild = NULL;
	}

	Node() {}

	//Operators were overloaded for compatibility with Stack and Queue
	bool operator<(Node<T>* n) {
		return data < n->data;
	}

	bool operator>(Node<T>* n) {
		return data > n->data;
	}

	bool operator==(Node<T>* n) {
		return data == n->data;
	}
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
	int size = 0;

	BinarySearchTree() {
		root = nullptr;
	};
	~BinarySearchTree() {};

	int find(T val) {

		int ret = 1;

		if (root == nullptr) {
			return ret;
		}
		else {
			findNode(root, val, ret);
			return ret;
		}
	}

	int insert(T val) {

		int ret = 0;

		if (root == nullptr) {
			root = new Node<T>(val);
			size++;
			return 1;
		}

		Node<T>* parent = findNodeToInsert(root, val, ret);
		Node<T>* newNode = new Node<T>(val);

		if (newNode->data < parent->data) {
			parent->leftChild = newNode;
		}
		else {
			parent->rightChild = newNode;
		}

		size++;
		balanceTree();

		return ret;
	}

	// Remove method before submitting code. Only for debugging
	Node<T>* getRoot() {
		return root;
	}

	int getSize() {
		return size;
	}

	// Always called after every insert and remove
	void balanceTree() {
		Node<T>** nodes = getAllAscending();
		root = restructureTree(nodes, 0, getSize() - 1);
	}

	Node<T>** getAllAscending() {
		Queue<Node<T>>* q = new Queue<Node<T>>(getSize());
		addNodesInAscendingOrderToQueue(root, q);

		Node<T>** arr = new Node<T> * [q->length()];

		for (int i = 0; i < getSize(); i++) {
			arr[i] = q->pop();
			//cout << (arr[i])->data << endl;
		}
		return arr;
	}

	void emptyTree() {
		delete root;
		root = nullptr;
		size = 0;
	}

	Node<T>** getAllDescending() {
		Stack<Node<T>>* s = new Stack<Node<T>>(getSize());
		addNodesInAscendingOrderToStack(root, s);

		Node<T>** arr = new Node<T> * [getSize()];

		for (int i = 0; i < getSize(); i++) {
			arr[i] = s->pop();
			//cout << (arr[i])->data << endl;
		}
		return arr;
	}

	int remove(T val) {

		int ret = 0;

		Node<T>* parent;
		Node<T>* removedNode;
		DataPack<T>* dat = new DataPack<T>();
		dat->node = root;   //start researching from root

		dat = findNode(dat,val,ret);
		
		removedNode = dat->node;
		parent = dat->parentNode;

		//If Element couldn't be found, return nullptr
		if (removedNode == nullptr) {
			return ret;
		}

		if (removedNode == root) {

			if (removedNode->leftChild != nullptr) {    //If left node of root is not null, make it root and adjust right node of old root accordingly

				root = removedNode->leftChild;

				if (removedNode->rightChild != nullptr) {

					Node<T>* insertionPoint = findNodeToInsert(root,removedNode->rightChild->data,ret);

					if (removedNode->rightChild->data < insertionPoint->data) {
						insertionPoint->leftChild = removedNode->rightChild;
					}
					else {
						insertionPoint->rightChild = removedNode->rightChild;
					}
				}
			}
			else if (removedNode->rightChild != nullptr) {
				root = removedNode->rightChild;
			}
			else {
				root = nullptr;
			}

		}

		else if (removedNode->data < parent->data) {

			parent->leftChild = removedNode->leftChild;

			if (removedNode->rightChild != nullptr) {
				Node<T>* insertionPoint = findNodeToInsert(parent, removedNode->rightChild->data,ret);

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
				Node<T>* insertionPoint = findNodeToInsert(parent, removedNode->leftChild->data,ret);

				if (removedNode->leftChild->data < insertionPoint->data) {
					insertionPoint->leftChild = removedNode->leftChild;
				}
				else {
					insertionPoint->rightChild = removedNode->leftChild;
				}
			}
		}

		size--;
		balanceTree();
		return ret;

	}

private:

	// Find a node with a given value. This accepts and returns a datapack since it also keeps track of the parent. This function is recursive
	DataPack<T>* findNode(DataPack<T>* data, T val, int& ret) {
		ret++;
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
				return findNode(data, val,ret);

			}
			else {
				if (curr->rightChild == nullptr) {
					data->node = nullptr;
					return data;
				}
				data->node = curr->rightChild;
				return findNode(data, val,ret);
			}
		}
	}


// Find the node with a given value. This function is recursive
	Node<T>* findNode(Node<T>* curr, T val, int& ret) {

		ret++;

		if (curr->data == val) {
			return curr;
		}
		else {
			if (val < curr->data) {
				if (curr->leftChild == nullptr) {
					return nullptr;
				}
				return findNode(curr->leftChild, val,ret);

			}
			else {
				if (curr->rightChild == nullptr) {
					return nullptr;
				}
				return findNode(curr->rightChild, val,ret);
			}
		}
	}

// Find the parent node after which a new node should be inserted. This function is recursive
	Node<T>* findNodeToInsert(Node<T>* curr,T val, int& ret) {
		if (curr->data == val) {
			throw ValueAlreadyFoundException();
		}

		ret++;

		if (val < curr->data) {
			if (curr->leftChild == nullptr) {
				return curr;
			}
			return findNodeToInsert(curr->leftChild, val, ret);

		}
		else {
			if (curr->rightChild == nullptr) {
				return curr;
			}
			return findNodeToInsert(curr->rightChild, val,ret);
		}

	}

	void addNodesInAscendingOrderToQueue(Node<T>* curr, Queue<Node<T>>* q) {

		if (curr == nullptr) {
			return;
		}

		if (curr->leftChild != nullptr) {
			addNodesInAscendingOrderToQueue(curr->leftChild, q);
		}

		q->push(curr);

		if (curr->rightChild != nullptr) {
			addNodesInAscendingOrderToQueue(curr->rightChild, q);
		}

	}

	void addNodesInAscendingOrderToStack(Node<T>* curr, Stack<Node<T>>* s) {

		if (curr == nullptr) {
			return;
		}

		if (curr->leftChild != nullptr) {
			addNodesInAscendingOrderToStack(curr->leftChild, s);
		}

		s->push(curr);

		if (curr->rightChild != nullptr) {
			addNodesInAscendingOrderToStack(curr->rightChild, s);
		}

	}

	//Algorithm inspired by https ://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/ 
	Node<T>* restructureTree(Node<T>** arr, int start, int end) {

		if (start > end) {
			return NULL;
		}

		int mid = (start + end) / 2;
		Node<T>* root = arr[mid];

		root->leftChild = restructureTree(arr, start, mid - 1);
		root->rightChild = restructureTree(arr, mid + 1, end);

		return root;

	}

};