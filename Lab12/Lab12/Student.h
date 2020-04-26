/*
3.	Create a linked list class that can store Student information.
	The Student information must include First Name, Last Name, MNumber
	and may include any other additional information you wish.
	In addition to any required members to make the linked list work,
	include 3 of the above sort algorithms to support sorting by First Name, Last Name and MNumber
	(each algorithm sorts by 1 of the 3) and includes a parameter for ascending or descending.
	Seed your linked list with data for 50 students that will result in a different order for each of the fields.
	Include a menu interface that allows the user to select the sort method and
	direction and will display the sorted students on the screen.
*/

#include <string>

using namespace std;

class Student
{
	string firstName;
	string lastName;
	int MNumber;
};

