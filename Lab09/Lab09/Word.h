/*
	****READ MAIN FOR MORE REFERENCE****
	c.	Your program should create a class made up of a string and an int
		that will be used as the type of the templated Binary Search Tree.
		The string will be the word you are reading in and should be the key you are comparing at each level.
		The int is the count for that word.
		You may need to overload <, > and/or == operators for this class to be used in your Tree.
*/
#pragma once
#include <string>
using namespace std;

class Word
{
	private:
		string word;
		int count;

	public:
		Word() { this->word = ""; this->count = 0; }
		Word(string word, int count) { this->word = word; this->count = count; }
		string getWord() { return word; };
		int getCount() { return count; };
		bool operator<(Word);
		bool operator>(Word);
		bool operator==(Word);
		void operator++(int);
};

