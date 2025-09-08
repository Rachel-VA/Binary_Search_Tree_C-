#ifndef BST_H
#define BST_H
//must keep enclose guard top and bottom, otherwise it doesn't work

#include<iostream>

//define node structure for each node in BST
struct TreeNode {
	int data; //value store in node
	TreeNode* leftChild; //pointer point to the left node
	TreeNode* rightChild; //pointer point to the right node
	
};

//create a class BST
class BST {
public:
	BST(); //default constructor
	//Node* root; //the root node
	
	
	//define funcs
	bool Add(int value);
	bool Remove(int value);
	int Max();
	void InorderTraverse();
	void InorderTraverse(TreeNode*);
	TreeNode* Find(int value); //to allow searching a value

private:

	//helper for remove func
	bool remove(TreeNode*& node, int value);
	TreeNode* root; //root node

};
#endif

