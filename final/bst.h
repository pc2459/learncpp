/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Node{

	string data;
	int freq;
	Node *left;
	Node *right;

	//Make Tree a friend class to give it access to
	//Node's private variables (sounds wrong)
	friend class Tree;
	friend class Book;

public:
	Node();
	Node(string n);
	~Node();

};


class Tree{

	Node *root;
	int opcount;
	int searchcount;

public:
	Tree();
	//Tree(Node *node);
	~Tree();

	Node* arrayToBST(Node array[], int start, int end);

	void deallocateTree(Node *tree);
	
	Node* getRoot();
	void setRoot(Node *node);

	void copyToArray(Node array[], int* index);
	void copyToArray(Node *node, Node array[], int* index);

	Node* addNode(Node *node, string value);

	void insert(string value);
	
	void print();
	void printTree(Node *tree);

	void lookup(string s, bool *found);
	void lookup(Node *node, string s, bool *found);
	
	int count();
	int CountNodes(Node *node);

	int getOps();
	int getSearchOps();
	void resetSearchOps();


};

#endif