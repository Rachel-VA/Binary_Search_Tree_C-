/*

* MS549- Data Structure and Testing
*
*/

/*
 *Program Description:
 * --------------------
 * The program below implements a simple Binary Search Tree (BST). 
   The BST class provides:
 *
 * 1. Add: Adds a new value to the tree 
 * 2. Remove: Removes a value from the tree
 * 3. Find: Searches for a specific value in the tree and returns it
 * 4. Finding Max numb: Finds the max value stored in the tree and return it
 * 5. Inorder Traversal: Performs an inorder traversal of the tree and print them out
 *
 * The struct:  TreeNode, data, and left/right child and pointers
 *
 * **Main Function:**
 *  Part I: Inserts 100 random integers between 1 and 100 into the BST
 *  Find a Value**: Searches for a specific value 90 in the tree and display whether it was found or not
 * Find a max numb in the tree and display it
 *  Delete a Value**: Remove the specified value from the tree and display a message
 * 
 *  Part II: Measures and displays the time it take to insert 100, 1,000, 10,000, 100,000 nodes into a new BST




*/

#include "BST.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include<chrono>

using namespace std;//keep the namespace after the include, sometime it doesn't work if placed above

int main()
{
	// seed the random machine
	srand(static_cast<unsigned int>(time(NULL)));

	//-------- Part I: allow insert a random values into the tree and performce searching a specific value and find the max value in it ------------------

	BST bst; //instance
	int random, max;//create random and max variables

	for (int i = 0; i < 100; i++)//insert 100 (or any number) and loop it through
	{
		random = 1 + rand() % 100; //generate randome numbs between 1-100
		cout << "Inserting: "<<random << endl;//output the insert numbs
		bst.Add(random);//add to the tree
	}

	cout << "\n------------ Inorder traversal after insertions: ----------------------\n\n";
	bst.InorderTraverse();//performance the inorder traversal

	//set the max var to max func and get the max numb from the tree
	max = bst.Max();
	cout << "\nThe Max value found in the insertion is: "<<max << endl; //display the message if no value found


	int searchValue = 90;//define a value for searching
	TreeNode* foundNode = bst.Find(searchValue);//find the value
	if (foundNode != NULL) //if found,
	{
		cout << "\nThe search Value "<<searchValue <<" found in this tree\n" << endl;//then print it
	}
	else
	{
		cout << "\nValue "<<searchValue <<" is NOT found"<< endl;//if not show message
	}

	//remove the value
	cout << "\nTry to remove value"<<searchValue <<" from this tree" << endl;
	if (bst.Remove(searchValue))//if remove sucessfully, 
	{
		cout << "\nThe Value "<<searchValue <<" was removed sucessfully" << endl;//then show it
	}
	else
	{
		cout << "Value " << searchValue << " is NOT found in this tree\n"<<endl;
	}

	cout << "\n\n\n**************** Inorder traversal after removal: ********************\n\n\n";
	bst.InorderTraverse(); //do another reversal after removed the value


	//---------------------- Testing with data sizes and measuring performce --------

	//array of data sizes for testing insertion into the tree
	int dataSizes[] = {100,1000,10000,100000};

	//loop through sizes
	for (int size : dataSizes)
	{
		BST bst; //new instance of BST for each size
		 //start cocunting
		auto startCountingTime = chrono::high_resolution_clock::now();

		//loop the values
		for (int i = 0; i < size; i++)
		{
			int randomValue = rand();//generate random numbs
			bst.Add(randomValue);//add to tree
		}

		//end counting
		auto endCountingTime = chrono::high_resolution_clock::now();
		//calculate the duration it took in millisecond
		auto duration = chrono::duration_cast<chrono::microseconds>(endCountingTime - startCountingTime);

		cout << "\n\n=================  MEASURING TIME INSERTING NODES ====================\n" << endl;
		//display the time
		cout << "Time to insert " << size << " nodes is  " << duration.count() << " microseconds\n" << endl;
	}
	

	
		cout << "\n\n\n\n" << endl;
	return 0;

}//end main
