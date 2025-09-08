#include "BST.h"

#include<iostream>


using namespace std;


//class constructor
BST::BST() {
	root = NULL; //start root emplty
}

//public method to add value to the tree
bool BST::Add(int inputNumb) {
	TreeNode* value = new TreeNode();
	value->data = inputNumb; //set data for node to input numb
	//initialize both left/right child empty
	value->leftChild = NULL;
	value->rightChild = NULL;

	if (root == NULL) //if root is empty,
	{
		root = value; //then add value
		return true; //indicate sucessfully inserted
	}
	      
	else  //start at the root and keep moving until find a correct spot to add data
	{  
		TreeNode* pointer = root;
		while (pointer != NULL) //pointer is not empty
		{    //noduplicate allow
			if (inputNumb == pointer->data) //if value is already exist, then do not accept it
			{
				delete value; //delete the newly created node to avoid memory leak
				return false;
			}
			//handle data left/right
			else if(inputNumb < pointer->data) //if value is less than the current node value, insert left
			{
				if (pointer->leftChild == NULL) //if the left is empty, insrt it
				{
					pointer->leftChild = value; //acept the insert value
					return true; //indicate sucessfully
				}
				//if not then move pointer to the left
				else
				{
					pointer = pointer->leftChild;
				}

			}//end else if for left move

			else //if input value is greater, then move right
			{
				if (pointer->rightChild == NULL) //if pointer on right is empty, insrt it
				{
					pointer->rightChild = value;//accept it
					return true;//indicate success
				}
				//if not then keep move right
				else
				{
					pointer = pointer->rightChild; //move pointer to the right
				}
			}
		}//end while loop
		return true;
	}
}

//public method to performance inorder traverse and extend the class name
void BST::InorderTraverse()
{
	InorderTraverse(root);//call the recursive help func to start at the root
	cout << "" << endl;
}

//recursive helper func to keep moving
void BST::InorderTraverse(TreeNode* next)
{
	if (next == NULL) //base case, if node is empty,
	{
		return; //return to the previous
	}
	InorderTraverse(next->leftChild); //keep recurisvely moving to left tree
	cout<<next->data<<" "; //output data//visit the current node
	InorderTraverse(next->rightChild); //keep recursively moving to right
	
}

//impletement Max func from the class to find the biggest number
int BST::Max() {
	if (root == NULL) {//if root is empty, 
		return -1;//then return -1 to indicate no biggest numb
	}
	else
	{
		//keep go right untill find the biggest numb
		TreeNode* pointer = root;//start the the root
		while (pointer->rightChild != NULL) //if there is a right child,
		{
			pointer = pointer->rightChild; //move pointer to the right

		}
		return pointer->data; //return dataof the right
	}
}

//implemement find func to find a specific value
TreeNode* BST::Find(int value) {
	TreeNode* current = root; //start at the root
	while (current != NULL)//current is not empty, keep moving until find the value
	{
		if (value == current->data)
		{
			return current;
		}

		else if(value < current->data)//if the value if less then the current value in the node.
		{
			current = current->leftChild;//move lft
		}
		else //if greater, 
		{
			current = current->rightChild;//move right
		}
	}
	return NULL; //return empty if not find the value
}

//impletement remove
bool BST::Remove(int value)
{
	return remove(root, value);

}

// Private helper func
bool BST::remove(TreeNode*& node, int value)
{
	if (node == NULL) //if node is empty,
	{
		return false; //then indicate not found
	}//1

	if (value < node->data) //if value is less than the data in the node,
	{
		return remove(node->leftChild, value);//then keep moving on the left
	}//2

	else if (value > node->data) //if value is greater,
	{
		return remove(node->rightChild, value);//then continue moving on the right
	}//3

	//-------------------------------------------------------------
	
	//case 1: handle nodes have no child by deleting the node then set pointer to empty
	if (node->leftChild == NULL && node->rightChild == NULL)//if both left and right re empty,
	{
		delete node;//delete it
		node = NULL;//set it empty
	}

	//case2-3: nodes with 1 child right/left by replacing the node w/its child
	else if(node->leftChild == NULL)
	{
		TreeNode* temp = node; //create a temp pointer
		node = node->rightChild; //replace it w/ the right child
		delete temp;//then delete the temp
	}

	//case3: nodes with 1 child left, same as a bove
	else if (node->leftChild == NULL)
	{
		TreeNode* temp = node;
		node = node->leftChild;
		delete temp;
	}
	
	//handle nodes have 2 children by finding smallest value on right sub tree and replacing the node with sucess data then delete it
	else
	{
		TreeNode* sucessParent = node; //parent of the sucessor
		TreeNode* sucess = node->rightChild;//start on the right 

		while (sucess->leftChild != NULL) //find on the left most node of subtree
		{
			sucessParent = sucess;//update the parent to sucess
			sucess = sucess->leftChild;//then move left
		}
		//copy data to the current node
		node->data = sucess->data;

		//now delete the sucess node 
		if (sucessParent != node)//not on the right (left)
		{
			sucessParent->leftChild = sucess->leftChild;//replace
		}

		else //on the right, 
		{
			sucessParent->rightChild = sucessParent->rightChild;//change to right child
		}
		delete sucess;
	}

	return true;//indicate sucessfully remove
}//end remove func