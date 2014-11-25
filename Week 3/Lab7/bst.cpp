/********

Name: Chia, Po Linn
Date: 2014-07-24
Homework #: Lab 7

See main.cpp for sources &c.

*********/

#include "bst.h"

/****
Node
****/

//Constructor
Node::Node(){

}

//Create Node with value and null left/right pointers
Node::Node(int n){

	data = n;
	left = NULL;
	right = NULL;

}

//Destructor
Node::~Node(){

}


/****
Tree
****/

//Constructor, setting root to NULL
Tree::Tree(){
	root = NULL;
}

//destructor
Tree::~Tree(){
	//recursively deallocate the tree
	deallocateTree(root);

}

//deallocate the tree from memory
void Tree::deallocateTree(Node *tree){
	if(tree != NULL){
		//recur through tree from left to right
		deallocateTree(tree->left);
		deallocateTree(tree->right);
		//delete leaf
		delete tree;
	}
}

//Return the root
Node* Tree::getRoot(){
	return root;
}

//Set the root
void Tree::setRoot(Node *node){
	root = node;

}

//Add to a tree denoted by *node a node with value
Node* Tree::addNode(Node *node, int value){

	//Create and populate the new node
	class Node *newNode = new Node;
	newNode->data = value;
	newNode->left = NULL; //set pointers to null
	newNode->right = NULL;

	//if the tree is empty, add at the root
	if(node == NULL){
		node = newNode; //set it to root
		//cout << "Adding new node " << value << endl;
	}

	else if(value < node->data){ //if smaller than the root
		node->left = addNode(node->left, value); //recur through till null
	}

	else if(value > node->data){ //if it is larger than the root
		node->right = addNode(node->right, value); //recur through till null
	}

	else if(value == node->data){ //if it is already in the tree
		cout << "Already in tree!" << endl; //do nothing
		delete newNode; //delete the new node
	}

	return node;
}

//Print the tree recursively
void Tree::printTree(Node *tree){
	if (tree == NULL)
		return;
	printTree(tree->left);
	cout << tree->data << " ";
	printTree(tree->right);
}

//Iteratively count the number of nodes in a BST
int Tree::CountNodes(Node *node){

	/* 	This code visits the tree using pre-order traversal 
		(http://www.geeksforgeeks.org/iterative-preorder-traversal/)
		and adds each visited node to a stack. It pops off
		items from the stack, counting as it goes and adding right-hand
		nodes when necessary.
	*/
	  
	if(node == NULL) //case of empty tree
	  	return 0;

	  //MAYBE CHANGE THIS TO A LINKED LIST

	Node *stack[100]; //create a stack of pointers to nodes
	int top = -1; //with the top set to -1
	int count = 0; //create a counter

	//push the root into the stack
	stack[++top] = node;

	while(top != -1) { //while there are things in the stack
		node = stack[top]; //look to the last visited node
		count++; //count it
		top--; //pop it from the stack

		//check to see if there are further nodes to be visited
		//and add them to the stack
		if(node->right)
			stack[++top] = node->right;
		if(node->left)
			stack[++top] = node->left;
	}
	return count;
}

//Recursively count the number of nodes in a BST
int Tree::CountNodes_R(Node *node){
	if (node == NULL) 
		return 0;
	else{ 
		return (CountNodes_R(node->left) + 1 + CountNodes_R(node->right));
	}
}


