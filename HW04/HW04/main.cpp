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