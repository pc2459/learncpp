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
Node::Node(string a, string t, string i, double p, int q){

	author = a;
	title = t;
	ISBN = i;
	price = p;
	quantity = q;
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
Node* Tree::addNode(Node *node, string a, string t, string i, double p, int q){

	//Create and populate the new node
	class Node *newNode = new Node(a, t, i, p, q);

	//if the tree is empty, add at the root
	if(node == NULL){
		node = newNode; //set it to root
		//cout << "Adding new node " << value << endl;
	}

	else if(p < node->price){ //if smaller than the root
		node->left = addNode(node->left, a, t, i, p, q); //recur through till null
	}

	else if(p > node->price){ //if it is larger than the root
		node->right = addNode(node->right, a, t, i, p, q); //recur through till null
	}

	else if(t == node->title){ //if it is already in the tree
		cout << "Already in tree!" << endl; //do nothing
		delete newNode; //delete the new node
	}

	return node;
}

//helper function to simplify adding items to the tree
void Tree::insert(string a, string t, string i, double p, int q){
	root = addNode(root, a, t, i, p, q);
	// cout << root << endl;
}

//Print the tree recursively in order
void Tree::printTree(Node *tree){
	if (tree == NULL) //Return nothing if tree is empty
		return;
	printTree(tree->left);

	printBook(tree);
	// cout << tree->title << " by " << tree->author << endl;
	// cout <<"Price: $" << tree->price << " In Stock: " << tree->quantity;
	cout << "\n" << endl;
	printTree(tree->right);
}


void Tree::printBargain(Node *node, double max){
	

	if(node == NULL){
		return;
	}
	
	Node *temp = node;

	while(temp->price > max){
		temp = temp->left;
	}
	printBargain(temp->left, max);
	printBook(temp);
	cout << endl;
	printBargain(temp->right, max);
	
	
}
//Helper function for easier wrangling
void Tree::printBargain(double max){
	printBargain(root, max);
}

//Sell a book of a title t from a tree
void Tree::sellBook(Node *node, string s){

	if (node == NULL){
		//do nothing if store is empty
	}

	//find the book
	else if (s.compare(node->title) == 0){ //if title matches
		(node->quantity)--; 	//decrement the stock
		cout << "\nSelling " << node->title << ". Remaining stock: " << node->quantity << endl;
		if(node->quantity == 0){ //delete the book if the stock is now 0
			cout  << "\nNOTICE: " << node->title << " is no longer available at this store.\n" << endl;
			deleteBook(root, node->price);

		}
	}
	else{
		sellBook(node->left, s); //keep searching to the left
		sellBook(node->right, s); //keep searching to the right
	}
}

//Sell a book of ISBN i from a tree 
void Tree::sellBookI(Node *node, string i){

	if (node == NULL){
		//do nothing if store is empty
	}

	//find the book
	else if (i.compare(node->ISBN)==0){ //if ISBN matches
		(node->quantity)--; 	//decrement the stock
		cout << "\nSelling " << node->title << ". Remaining stock: " << node->quantity << endl;
		if(node->quantity == 0){ //delete the book if the stock is now 0
			cout << "\nNOTICE: " << node->title << " is no longer available at this store." << endl;
			deleteBook(root, node->price);
			
		}		
	}
	else{
		sellBookI(node->left, i); //keep searching to the left
		sellBookI(node->right, i); //keep searching to the right
	}
}

//Helper functions for selling
void Tree::sellBook(string s){
	sellBook(root, s);
}

void Tree::sellBookI(string i){
	sellBookI(root, i);
}


//Delete a book of a certain price from a tree
Node* Tree::deleteBook(Node *node, double price){
	if (root == NULL){//do nothing if the tree is empty

	}

	else {//since all the prices are unique...


	/*
			[FOUND]
			/	   \
		[left]	[right]	

	*/

		if (price == node->price) { //first node is the one to be deleted
			Node *replacement = NULL;

			//case if first node is the only node
			if(node->left == NULL && node->right == NULL){
				delete node;
				// cout << "DELETED CHILDLESS" << endl;
				return replacement; //delete it and return null
			}

			//case if only the left leaf is null
			else if(node->left == NULL){
				replacement = node->right; //replace with the right-hand child
				delete node;
				// cout << "DELETED SINGLE CHILD" << endl;
				return replacement;
			}

			//case if only the right leaf is null 
			else if(node->right == NULL){
				replacement = node->left; //replace with the left-hand child
				delete node;
				// cout << "DELETED SINGLE CHILD" << endl;
				return replacement;
			}

			//case if there are two or more children
			//Replace the node to be deleted with its predecessor

/*
			[root]
			/  \
		[FOUND]	[right]
		/
	[Child1]
	/  	   \
[Child2]   [Predecessor]	


*/

			else{
				//get the predecessor
				replacement = getPredecessor(node->left);
				//replace the data in the node to be deleted with the predecessor
				swapValues(node, replacement);
				//delete the predecessor, which may be a few nodes away (see diagram)
				node->left = deleteBook(node->left, replacement->price);

			}

		}//end first node is desired node if


		//case if we have to look for the node elsewhere
		else if (price < node->price) {//recur down the left if cheaper
			node->left = deleteBook(node->left, price);
		}
		else{ //or down the right if more expensive
			node->right = deleteBook(node->right, price);
		}

	}//end non-null cases

	return node;

}

//Swap the values of two nodes
void Tree::swapValues(Node* node, Node* replacement){
	node->price = replacement->price;
	node->quantity = replacement->quantity;
	node->title = replacement->title;
	node->author = replacement->author;
	node->ISBN = replacement->ISBN;

}

//Get the predecessor of a node (MUST take node->left as the argument)
Node* Tree::getPredecessor(Node *node){
	while(node->right != NULL){ //traverse down to the rightmost node
		node = node->right;
	}
	return node;
}

//Helper function for delete book
void Tree::deleteBook(double price){
	root = deleteBook(root, price);

}

//Search for item by ISBN (visit all nodes, print when found)
void Tree::searchISBN(Node *node, string i){
	if (node == NULL){ //Do nothing if we hit a null node
	
	}
	else if (i.compare(node->ISBN)==0){ //print the node if found
		printBook(node);
	}
	else {
		searchISBN(node->left, i); //Keep searching left
		searchISBN(node->right, i); //Keep searching right
	}
}

//Search for item by Title (visit all nodes, print when found)
void Tree::searchTitle(Node *node, string t){
	if (node == NULL){ //Do nothing if we hit a null node
	
	}
	else if (t.compare(node->title) == 0){ //print the node if found
		printBook(node);
	}
	else {
		searchTitle(node->left, t); //Keep searching left
		searchTitle(node->right, t); //Keep searching right
	}
}

//Helper functions to make searches easier in main
void Tree::searchISBN(string i){
	searchISBN(root, i);
}

void Tree::searchTitle(string t){
	searchTitle(root, t);
}


//Print all the information about a book out
void Tree::printBook(Node *node){
	cout << node->title << " (ISBN: " << node->ISBN << ") by " << node->author << endl;
	cout << "$" << node->price << ". Quantity in stock: " << node->quantity << endl;
}





