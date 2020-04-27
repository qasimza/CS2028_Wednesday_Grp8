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

using namespace std;

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
	for (int i = 0; i < 10; i++) {
		cout << *myArray[i] << " ";
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
* 
*******************************************************************/


template <class T>
T** quickSort(T** data, int start, int size) {
	if (start < size - 1) {
		//Partitioning the array
		T* pivot = data[size - 1];
		display(data, size);
		cout <<" Start " << start << " Size " << size << " Pivot " << *pivot << endl;
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
		quickSort(data, i+1, size);
	}
	return data;
}

template <class T>
T** countingSort(T** array, int size) {

}

template <class T>
T** radixSort(T** array, int size) {

}


int main() {
	int** myArray = new int* [10];
	for (int i = 0; i < 10; i++) {
		myArray[i] = new int(rand() % 20);
	}

	for (int i = 0; i < 10; i++) {
		cout << *myArray[i] << " ";
	}
	cout << endl;
	quickSort(myArray, 0, 10);
	
	display(myArray, 10);

	return 0;
}
