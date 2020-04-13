/*
3. Create a main function that will be used to test your 2 data structures. 
   This should generate a list of 100 random, unique integers that will be used to test both data structures 
   (both should get the same set of integers in the same order). Then perform the following tasks:
    a. Insert the first 50 values in both data structures, keeping a running sum of spots checked 
       to insert those items. This value after inserting 50 should be recorded.
    b. Remove all the items from the data structures where the index of the value in the main function % 7 == 0.
       Record the running sum of spots checked to remove those items.
    c. Insert the remaining 50 values from both data structures. Record the running sum
    of spots checked to remove those items.
    d. Attempt to find all the items in the hash table where the index value in the main
       function % 9 == 0 and the item wasn’t removed previously.
     
4. Write unit tests for your two classes. You can learn more about unit tests for Visual Studio at
   https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-ccpp?view=vs-2019.
*/

#include <iostream>
#include <random>
#include "BinarySearchTree.h"
#include "HashTable.h"
using namespace std;

int main()
{
    // Initialize an empty array of integers
    const int SIZE = 100;
    int randomNumbers[SIZE] = { 0 };

    // Fill array with unique integers
    for (int i = 0; i < SIZE; ++i)
    {
        bool isUnique = false;
        while (!isUnique)
        {
            // Create a random integer
            int random = (rand() * (rand() % 2 == 0 ? -1 : 1));

            // Check if the integer is unique
            for (int j = 0; j < SIZE; j++)
            {
                // If the end is reached and nothing matches, it is unique
                if (random != randomNumbers[j] && j == (SIZE - 1))
                {
                    isUnique = true;
                    randomNumbers[i] = random;
                }
            }
        }

    }

    // Initialize Data Structures
    BinarySearchTree<int> bst;
    HashTable<int> ht;

    // Intialize sums
    int bstSum = 0;
    int htSum = 0;

    // Insert 50 items into both data structures
    for (int i = 0; i < SIZE / 2; i++)
    {
        bst.insert(randomNumbers[i]);
        //ht.insert(randomNumbers[i]);
    }

    // Output sum and reset
    cout << "Inserting 50 items..." << endl;
    cout << "BST: " << bstSum << endl;
    cout << "HT: " << htSum << endl;
    bstSum = 0;
    htSum = 0;
    cout << endl;

    // Remove items at intervals of 7 from both data structures
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 7 == 0)
        {
            bst.remove(randomNumbers[i]);
            //ht.remove(randomNumbers[i]);
        }
    }

    // Output sum and reset
    cout << "Removing mod7 indexed items..." << endl;
    cout << "BST: " << bstSum << endl;
    cout << "HT: " << htSum << endl;
    bstSum = 0;
    htSum = 0;
    cout << endl;

    // Insert remaining 50 items into both data structures
    for (int i = SIZE / 2; i < SIZE; i++)
    {
        bst.insert(randomNumbers[i]);
        //ht.insert(randomNumbers[i]);
    }

    // Output sum and reset
    cout << "Inserting remaining 50 items..." << endl;
    cout << "BST: " << bstSum << endl;
    cout << "HT: " << htSum << endl;
    bstSum = 0;
    htSum = 0;
    cout << endl;

    // Finds items at intervals of 9 from both data structures
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 9 == 0)
        {
            bst.find(randomNumbers[i]);
            //ht.find(randomNumbers[i]);
        }
    }

    // Output sum and reset
    cout << "Finding mod9 items..." << endl;
    cout << "BST: " << bstSum << endl;
    cout << "HT: " << htSum << endl;
    bstSum = 0;
    htSum = 0;
    cout << endl;
}