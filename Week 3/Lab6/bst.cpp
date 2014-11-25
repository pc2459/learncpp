/********

Name: Chia, Po Linn
Date: 2014-07-23
Homework #: Lab 6

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
	}

	return node;
}//end addNode()

void Tree::printTree(Node *tree){
	if (tree == NULL)
		return;
	printTree(tree->left);
	cout << tree->data << " ";
	printTree(tree->right);
}


