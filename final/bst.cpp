/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#include "bst.h"
//#include "library.h"

/****
Node
****/

//Constructor
Node::Node(){

}

//Create Node with value and null left/right pointers
Node::Node(string n){

	data = n;
	freq = 1;
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
	opcount = 0;
	searchcount = 0;
}

// Tree::Tree(Node *node){
// 	root = node;
// }

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

Node* Tree::arrayToBST(Node array[], int start, int end){
	if (start > end)
		return NULL;

	//set the middle element as root
	int mid = (start + end)/2;

	//Copy value to a new node, otherwise deallocation will suffer
	Node *node = new Node;
	node->data = array[mid].data;
	node->freq = array[mid].freq;

	opcount += 3;

	node->left = arrayToBST(array, start, mid-1);
	node->right = arrayToBST(array, mid+1, end);

	return node;

}

void Tree::copyToArray(Node array[], int* index){
	copyToArray(root,array,index);
}

void Tree::copyToArray(Node *node, Node array[], int* index){
	
	if(node == NULL){
		return;
	}
	
	//store left
	copyToArray(node->left, array,index);

	//copy root
	array[*index] = *node;
	//cout << "Copied " << node->data << " to " << *index << endl;
	(*index)++;
	opcount++;

	//copy right
	copyToArray(node->right, array,index);


}
//Add to a tree denoted by *node a node with value
Node* Tree::addNode(Node *node, string value){

	//if the tree is empty, add at the root
	if(node == NULL){
		//Create and populate the new node
		class Node *newNode = new Node;
		newNode->data = value;
		newNode->freq = 1;
		newNode->left = NULL; //set pointers to null
		newNode->right = NULL;
		node = newNode; //set it to root
		opcount += 5;
		//cout << "Adding new node " << value << endl;
	}

	else if(value < node->data){ //if smaller than the root
		node->left = addNode(node->left, value); //recur through till null
	}

	else if(value > node->data){ //if it is larger than the root
		node->right = addNode(node->right, value); //recur through till null
	}

	else if(value == node->data){ //if it is already in the tree
		node->freq++;
		opcount++;
		//cout << "Already in tree!" << endl; //do nothing
		//delete newNode; //delete the new node
	}

	return node;
}

void Tree::insert(string value){
	root = addNode(root, value);
}

void Tree::print(){
	printTree(root);
}

//Print the tree recursively
void Tree::printTree(Node *tree){
	if (tree == NULL)
		return;
	printTree(tree->left);
	cout << tree->data << " " << tree->freq << "\n";
	printTree(tree->right);
}

int Tree::count(){

	return CountNodes(root);
}

//Recursively count the number of nodes in a BST
int Tree::CountNodes(Node *node){
	if (node == NULL) 
		return 0;
	else{ 
		opcount++;
		return (CountNodes(node->left) + 1 + CountNodes(node->right));
	}
}

void Tree::lookup(string s, bool *found){
	return lookup(root,s,found);
}

void Tree::lookup(Node *node, string s, bool *found){
	
	if (node == NULL){		
	}

	else if(s.compare(node->data) == 0){
		searchcount++;
		*found = 1;
	}
	else{
		 
		 lookup(node->left, s, found);
		 lookup(node->right, s, found);
		 if(*found == 0)	
			searchcount++;

		}
}

int Tree::getOps(){
	return opcount;
}

int Tree::getSearchOps(){
	return searchcount;
}

void Tree::resetSearchOps(){
	searchcount = 0;
}