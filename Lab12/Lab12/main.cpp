/*
1.	Create a program that generate an array of sizes n= 10, 100, 500, 5000, 25,000, and 100,000 items.  
	Your program should populate those arrays with randomly generated integers 
	with a value between 0 and the 2n where n is the size of the array.  
	Create an implementation for the following sort operations.
	a.	Bubble sort
	b.	Insertion sort
	c.	Merge-sort
	d.	Quicksort
	e.	Counting sort
	f.	Radix-sort
2.	Test each of the sort operations and record the time the sort takes to complete.  
	You should test each on the same unsorted array to get the best comparison.  
	You should do this for each array size (from requirement 1) a minimum of 10 times.  
	Your test should use the chrono library’s high_resolution_clock class.  
	The following example of how to do this in nanoseconds is found on Stack Overflow. 
	Only the time in the 7 sort functions should be measured.
*/

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <iomanip>
#include "LinkedList.h"
#include "Student.h"

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

static string THIN_LINE = "--------------------------------------------------------------------------------------------------\n";
static string THICK_LINE = "==================================================================================================\n";

// Swap function  
template <class T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

//Display Function
template < class T>
void display(T** myArray, const int size) {
	for (int i = 0; i < size; i++) {
		cout << (string)(*myArray[i]) << endl;
	}
}

// Completed
template<class T>
T** bubbleSort(T** data, int size) {
	bool hasSwapped = false;

	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < size - i; j++) {

			T* curr = data[j];
			T* next = data[j + 1];

			if(*curr > *next) {
				swap(curr, next);
				hasSwapped = true;
			}
		}
		if(!hasSwapped) { //finished sorting
			break;
		}
	}
	return data;
}

template <class T>
T** insertionSort(T** data, int size) {

	for (int i = 1; i < size; i++) {
		T* curr = data[i];
		
		for (int j = i - 1; j >= 0; j--) {
			T* previous = data[j];

			if (*curr < *previous) {
				swap(curr, previous);
				curr = data[j];
			}
			else {
				break; //reached correct spot
			}

		}
	}

	return data;
}

template <class T>
T** merge(T** firstHalf, int size1, T** secondHalf, int size2) {
	T** result = new T * [size1 + size2];

	for (int i = 0; i < size1; i++) {
		result[i] = firstHalf[i];
	}

	for (int i = 0; i < size2; i++) {
		result[i + size1] = secondHalf[i];
	}

	result = insertionSort(result, size1 + size1);

	return result;
}

template <class T>
T** mergeSort(T** data, int size) {

	if (size <= 1) {
		return data;
	}

	int size1 = size / 2;
	int size2 = size - size1;

	T** firstHalf = new T * [size1];
	T** secondHalf = new T * [size2];
	
	for (int i = 0; i < size; i++) {
		if (i < size1) {
			firstHalf[i] = data[i];
		}
		else {
			secondHalf[i - size1] = data[i];
		}
	}

	T** firstSorted = mergeSort(firstHalf,size1);
	T** secondSorted = mergeSort(secondHalf,size2);
	
	T** res = merge(firstSorted, size1, secondSorted, size2);
	return res;
}	

/*******************************************************************
* QUICK SORT - Always picks last element of the array as pivot    *
*******************************************************************/
template <class T>
T** quickSort(T** data, int start, int size) {
	if (start < size - 1) {
		//Partitioning the array
		T* pivot = data[size - 1];
		int i = start - 1;
		for (int j = start; j < size - 1; j++) {
			T* curr = data[j];
			if (*curr < *pivot)
			{
				i++;
				T* prev = data[i];
				swap(prev, curr);
			}
		}
		T* next = data[i + 1];
		//Moving pivot to correct position
		swap(next, pivot);
		//Sorting partitions
		quickSort(data, start, i);
		quickSort(data, i+2, size);
	}
	return data;
}

template <class T>
T** countingSort(T** data, const int size) {
	
	//Finding maximum and minimum elements
	T min = *(data[0]);
	T max = *(data[0]);
	for (int i = 0; i < size; i++) {
		T* curr = data[i];
		min = min < *curr ? min : *curr;
		max = max > *curr ? max : *curr;
	}

	//memset from : http://www.cplusplus.com/reference/cstring/memset/ (will set each element to 0)
	int *count = new int[max+1];
	memset(count, 0, (max + 1) * sizeof(int));
	
	//Caculating frequency of each element in data
	for (int i = 0; i < size; i++) {
		T* curr = data[i];
		count[*curr - min]++;
	}

	//Calculating cumulative frequency (accumulating counts)
	for (int i = 1; i < max+1; i++) {
		count[i] = count[i] + count[i - 1];
	}

	//Creating sorted array
	T** sorted = new T * [size];
	for (int i = size - 1; i >= 0; i--) {
		T* curr = data[i];
		sorted[count[*curr]-1] = curr;
		count[*curr]--;
		
	}

	//Copy sorted values onto previous array
	for (int i = 0; i < size; i++)
		data[i] = sorted[i];

	return data;
}

template <class T>
T** radixSort(T** data, int size) {
	
	int i = 0;
	
	//Calculate element with the maximum number of digits 
	T max = *(data[0]);
	for (int i = 0; i < size; i++) {
		T* curr = data[i];
		max = max > * curr ? max : *curr;
	}

	//Perform Radix Sort by doing Counting Sort for each digit in max
	for (int e = 1; max/e>0; e*=10){	
		
		T** sorted = new T*[size];
		int* count = new int[10];
		memset(count, 0, (10) * sizeof(int));

		for (i = 0; i < size; i++) {
			T* curr = data[i];
			count[(*curr / e) % 10]++;
		}

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)	{
			T* curr = data[i];
			sorted[count[(*curr / e) % 10] - 1] = data[i];
			count[(*curr / e) % 10]--;
		}

		// Copy sorted array onto data
		for (i = 0; i < size; i++)
			data[i] = sorted[i];
	}
	return data;
}

LinkedList<Student> buildRandomList(const int size) {
	long seed = 123456789;
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int firstNameRange[2] = {5,10};
	int lastNameRange[2] = {7,15};
	int mNumberRange = 900000 - 1;
	int mNumberStartingValue = 100000;

	Student** students = new Student*[size];

	srand(seed);

	for (int i = 0; i < size;i++) {
		string firstName = "";
		string lastName = "";
		int mNumber;

		mNumber = rand() % mNumberRange + mNumberStartingValue;

		while (firstName.size() < firstNameRange[1]) {
			firstName.append(letters.substr(rand()%26,1));

			if (firstName.size() >= firstNameRange[1]) {
				break;
			}

			if (firstName.size() >= firstNameRange[0]) {
				if (rand() % 2 == 0) {
					break;
				}
			}
		}

		while (lastName.size() < lastNameRange[1]) {
			lastName.append(letters.substr(rand() % 26, 1));

			if (lastName.size() >= lastNameRange[1]) {
				break;
			}

			if (lastName.size() >= lastNameRange[0]) {
				if (rand() % 2 == 0) {
					break;
				}
			}
		}

		students[i] = new Student(firstName, lastName, mNumber);

	}

	return LinkedList<Student>(students,true,size);

}

int test1() {

	int arraySizes[6] = {10, 100, 500, 5000, 25000, 100000};
	double averageTimes[6][6];
	
	cout << THICK_LINE << "TESTING BUBBLE SORT\n" << THIN_LINE;
	for (int i = 0; i < 6; i++) { 
		cout << "Array Size: " << arraySizes[i] << endl;
		double totalTime = 0;
		double time;
		cout << "\nTest Run Times (in ms): " << endl;
		for (int num = 0; num < 10; num++) {
			//Generate random array
			srand(0);
			int** myArray = new int* [arraySizes[i]];
			for (int j = 0; j < arraySizes[i]; j++) {
				myArray[j] = new int(rand() % (arraySizes[i] * 2));
			}
			auto start = Clock::now();
			bubbleSort(myArray, arraySizes[i]);
			auto end = Clock::now();
			time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000;
			cout << time << "\t\t";
			totalTime += time;
			if (num == 4)
				cout << endl;
		}
		cout << endl << "\nTotal Time: " << totalTime << " ms,  Average Time: " << (totalTime / 10) << " ms" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		averageTimes[0][i] = totalTime / 10;
		cout << THIN_LINE;
	}

	cout << THICK_LINE << "TESTING INSERTION SORT\n" << THIN_LINE;
	for (int i = 0; i < 6; i++) {
		cout << "Array Size: " << arraySizes[i] << endl;
		double totalTime = 0;
		double time;
		cout << "\nTest Run Times (in ms): " << endl;
		for (int num = 0; num < 10; num++) {
			//Generate random array
			srand(0);
			int** myArray = new int* [arraySizes[i]];
			for (int j = 0; j < arraySizes[i]; j++) {
				myArray[j] = new int(rand() % (arraySizes[i] * 2));
			}
			auto start = Clock::now();
			insertionSort(myArray, arraySizes[i]);
			auto end = Clock::now();
			time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000;
			cout << time << "\t\t";
			totalTime += time;
			if (num == 4)
				cout << endl;
		}
		cout << endl << "\nTotal Time: " << totalTime << " ms,  Average Time: " << (totalTime / 10) << " ms" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		averageTimes[1][i] = totalTime / 10;
		cout << THIN_LINE;
	}

	cout << THICK_LINE << "TESTING MERGE SORT\n" << THIN_LINE;
	for (int i = 0; i < 6; i++) {
		cout << "Array Size: " << arraySizes[i] << endl;
		double totalTime = 0;
		double time;
		cout << "\nTest Run Times (in ms): " << endl;
		for (int num = 0; num < 10; num++) {
			//Generate random array
			srand(0);
			int** myArray = new int* [arraySizes[i]];
			for (int j = 0; j < arraySizes[i]; j++) {
				myArray[j] = new int(rand() % (arraySizes[i] * 2));
			}
			auto start = Clock::now();
			mergeSort(myArray, arraySizes[i]);
			auto end = Clock::now();
			time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000;
			cout << time << "\t\t";
			totalTime += time;
			if (num == 4)
				cout << endl;
		}
		cout << endl << "\nTotal Time: " << totalTime << " ms,  Average Time: " << (totalTime / 10) << " ms" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		averageTimes[2][i] = totalTime / 10;
		cout << THIN_LINE;
	}

	cout << THICK_LINE << "TESTING QUICK SORT\n" << THIN_LINE;
	for (int i = 0; i < 6; i++) {
		cout << "Array Size: " << arraySizes[i] << endl;
		double totalTime = 0;
		double time;
		cout << "\nTest Run Times (in ms): " << endl;
		for (int num = 0; num < 10; num++) {
			//Generate random array
			srand(0);
			int** myArray = new int* [arraySizes[i]];
			for (int j = 0; j < arraySizes[i]; j++) {
				myArray[j] = new int(rand() % (arraySizes[i] * 2));
			}
			auto start = Clock::now();
			quickSort(myArray, 0, arraySizes[i]);
			auto end = Clock::now();
			time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000;
			cout << time << "\t\t";
			totalTime += time;
			if (num == 4)
				cout << endl;
		}
		cout << endl << "\nTotal Time: " << totalTime << " ms,  Average Time: " << (totalTime / 10) << " ms" << endl;
		averageTimes[3][i] = totalTime / 10;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << THIN_LINE;

	}

	cout << THICK_LINE << "TESTING COUNTING SORT\n" << THIN_LINE;
	for (int i = 0; i < 6; i++) {
		cout << "Array Size: " << arraySizes[i] << endl;
		double totalTime = 0;
		double time;
		cout << "\nTest Run Times (in ms): " << endl;
		for (int num = 0; num < 10; num++) {
			//Generate random array
			srand(0);
			int** myArray = new int* [arraySizes[i]];
			for (int j = 0; j < arraySizes[i]; j++) {
				myArray[j] = new int(rand() % (arraySizes[i] * 2));
			}
			auto start = Clock::now();
			countingSort(myArray, arraySizes[i]);
			auto end = Clock::now();
			time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000;
			cout << time << "\t\t";
			totalTime += time;
			if (num == 4)
				cout << endl;
		}
		cout << endl << "\nTotal Time: " << totalTime << " ms,  Average Time: " << (totalTime / 10) << " ms" << endl;
		averageTimes[4][i] = totalTime / 10;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << THIN_LINE;

	}

	cout << THICK_LINE << "TESTING RADIX SORT\n" << THIN_LINE;
	for (int i = 0; i < 6; i++) {
		cout << "Array Size: " << arraySizes[i] << endl;
		double totalTime = 0;
		double time;
		cout << "\nTest Run Times (in ms): " << endl;
		for (int num = 0; num < 10; num++) {
			//Generate random array
			srand(0);
			int** myArray = new int* [arraySizes[i]];
			for (int j = 0; j < arraySizes[i]; j++) {
				myArray[j] = new int(rand() % (arraySizes[i] * 2));
			}
			auto start = Clock::now();
			radixSort(myArray, arraySizes[i]);
			auto end = Clock::now();
			time = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000;
			cout << time << "\t\t";
			totalTime += time;
			if (num == 4)
				cout << endl;
		}
		cout << endl << "\nTotal Time: " << totalTime << " ms,  Average Time: " << (totalTime / 10) << " ms" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		averageTimes[5][i] = totalTime / 10;
		cout << THIN_LINE;
	}
	
	cout << THICK_LINE;

	cout << "DATA SUMMARY" << endl;
	cout << THIN_LINE << left << setw(30) << "Number of Array Elements";
	for (int i = 0; i < 6; i++) {
		cout << left << setw(12) << setfill(' ') << arraySizes[i];
	}
	cout << endl << THIN_LINE;
	string sortType[6] = { "Bubble","Insertion","Merge","Quick","Counting","Radix" };
	for (int row = 0; row < 6; row++) {
		cout << left << setw(30) << setfill(' ') << sortType[row];
		for (int column = 0; column < 6; column++) {
			cout << left << setw(12) << setfill(' ') << averageTimes[row][column];
		}
		cout << endl << THIN_LINE;
	}
	return 0;
}

int main() {
	int choice = 0;
	int studentsListSize = 50;
	do {
		cout << THICK_LINE << "MENU\n" <<
			"1. Run Prelimary Tests (Allow enough time for these\n" <<
			"2. Student Linked List - Quick sort\n" <<
			"3. Student Linked List - Bubblesort \n" <<
			"4. Student Linked List - Insertion sort\n" <<
			"5. Quit" << endl;
		cout << THIN_LINE << "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1: 
			cout << THICK_LINE << "RUNNING PRELIMNARY TESTS" << endl << "This may take time..." << endl;;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			test1();
			break;

		case 2: {

			cout << THICK_LINE << endl;

			int sortingOrder, keyMode;

			cout << "Enter 0 for ascending order, otherwise for descending order" << endl;
			cin >> sortingOrder;
			cout << "Enter 0 to sort by firstName, 1 to sort by lastName, other wise to sort by mNumber" << endl;
			cin >> keyMode;

			if (keyMode > 1) {
				keyMode = 2;
			}

			LinkedList<Student> data = buildRandomList(studentsListSize);
			cout << "original : " << endl;
			data.display();
			cout << endl;
			
			Student** sorted = quickSort(data.toArray(keyMode), 0, studentsListSize);

			if (sortingOrder == 0) {
				cout << "asc" << endl;
				LinkedList<Student> sortedList = LinkedList<Student>(sorted, true, studentsListSize);
				cout << "sorted: " << endl;
				sortedList.display();
				cout << endl;
			}

			else {
				LinkedList<Student> sortedList = LinkedList<Student>(sorted, false, studentsListSize);
				cout << "sorted: " << endl;
				sortedList.display();
				cout << endl;
			}

			break;
		}
		case 3: {
			cout << THICK_LINE << endl;

			int sortingOrder, keyMode;

			cout << "Enter 0 for ascending order, otherwise for descending order" << endl;
			cin >> sortingOrder;
			cout << "Enter 0 to sort by firstName, 1 to sort by lastName, other wise to sort by mNumber" << endl;
			cin >> keyMode;

			if (keyMode > 1) {
				keyMode = 2;
			}

			LinkedList<Student> data = buildRandomList(studentsListSize);
			cout << "original : " << endl;
			data.display();
			cout << endl;

			Student** sorted = bubbleSort(data.toArray(keyMode), studentsListSize);

			if (sortingOrder == 0) {
				LinkedList<Student> sortedList = LinkedList<Student>(sorted, true, studentsListSize);
				cout << "sorted: " << endl;
				sortedList.display();
				cout << endl;
			}

			else {
				LinkedList<Student> sortedList = LinkedList<Student>(sorted, false, studentsListSize);
				cout << "sorted: " << endl;
				sortedList.display();
				cout << endl;
			}

			break;
		}
		case 4: {

			cout << THICK_LINE << endl;

			int sortingOrder, keyMode;

			cout << "Enter 0 for ascending order, otherwise for descending order" << endl;
			cin >> sortingOrder;
			cout << "Enter 0 to sort by firstName, 1 to sort by lastName, other wise to sort by mNumber" << endl;
			cin >> keyMode;

			if (keyMode > 1) {
				keyMode = 2;
			}

			LinkedList<Student> data = buildRandomList(studentsListSize);
			cout << "original : " << endl;
			data.display();
			cout << endl;

			Student** sorted = insertionSort(data.toArray(keyMode), studentsListSize);

			if (sortingOrder == 0) {
				cout << "asc" << endl;
				LinkedList<Student> sortedList = LinkedList<Student>(sorted, true, studentsListSize);
				cout << "sorted: " << endl;
				sortedList.display();
				cout << endl;
			}

			else {
				LinkedList<Student> sortedList = LinkedList<Student>(sorted, false, studentsListSize);
				cout << "sorted: " << endl;
				sortedList.display();
				cout << endl;
			}

			break;
		}
		default:
			cout << THICK_LINE << "Incorrect Choice" << endl;
		}
	} while (choice!= 5);
	return 0;
}