
#include <iostream>
#include "HashTable.h"
#include "ChainedHashTable.h"

using namespace std;

int main() {
	
	ChainedHashTable<string> test(10);
	test.addItem(new string("asfh"));
	test.addItem(new string("ASFH"));
	test.addItem(new string("ALfjdghvkjghi"));
	test.addItem(new string("ALfjdghvkjghiw"));
	test.addItem(new string("SASUKE"));
	cout << test.getLength();
	test.display();
	cout << "----------" << endl;
	cout << *test.removeItem(new string("asfh")) << endl;
	cout << "----------" << endl;
	test.display();
	////
	//string* ret = test.getItem(new string("alan"));
	////
	//cout << "--------------" << endl;
	//
	//if (ret != nullptr) {
	//	cout << *ret << endl;
	//}
	//else {
	//	cout << "ret is mullptr" << endl;
	//}
	//cout << test.getLength() << endl;

}