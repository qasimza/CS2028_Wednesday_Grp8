/*
	Implements overloaded operators using the built in compare() function for strings
	compare() returns:
					   -1 if the compared string is bigger
						0 if the strings are equal
						1 if the compared string is smaller

*/


#include "Word.h"

bool Word::operator<(Word other)
{
	int comparison = word.compare(other.word);
	if (comparison == -1) return 1;
	return 0;

}

bool Word::operator>(Word other)
{
	int comparison = word.compare(other.word);
	if (comparison == 1) return 1;
	return 0;
}

bool Word::operator==(Word other)
{
	int comparison = word.compare(other.word);
	if (comparison == 0) return 1;
	return 0;
}