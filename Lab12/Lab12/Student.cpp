#include "Student.h"

Student::Student(string firstName, string lastName, int MNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->MNumber = MNumber;
	key = firstName;
}

bool Student::operator<(Student other)
{
	int comparison = key.compare(other.key);
	if (comparison == -1) return 1;
	return 0;
}

bool Student::operator>(Student other)
{
	int comparison = key.compare(other.key);
	if (comparison == 1) return 1;
	return 0;
}

bool Student::operator==(Student other)
{
	int comparison = key.compare(other.key);
	if (comparison == 0) return 1;
	return 0;
}