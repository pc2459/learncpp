/********

Name: Chia, Po Linn
Date: 2014-07-23
Homework #: Lab 6

See main.cpp for sources &c.

*********/

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Node{

	int data;
	Node *left;
	Node *right;

	//Make Tree a friend class to give it access to
	//Node's private variables (sounds wrong)
	friend class Tree;

public:
	Node();
	Node(int n);
	~Node();

};


class Tree{

	Node *root;

public:
	Tree();
	~Tree();

	void deallocateTree(Node *tree);
	Node* getRoot();
	void setRoot(Node *node);
	Node* addNode(Node *node, int value);
	void printTree(Node *tree);

};

#endif