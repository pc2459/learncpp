/********

Name: Chia, Po Linn
Date: 2014-07-24
Homework #: Lab 7

See main.cpp for sources &c.

*********/

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Node{

	string author;
	string title;
	string ISBN;
	double price;
	int quantity;
	Node *left;
	Node *right;

	//Make Tree a friend class to give it access to
	//Node's private variables (sounds wrong)
	friend class Tree;

public:
	Node();
	Node(string a, string t, string i, double p, int q);
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

	Node* addNode(Node *node, string a, string t, string i, double p, int q);
	void insert(string a, string t, string i, double p, int q);
	
	void sellBook(Node *node, string s);
	void sellBookI(Node *node, string i);
	void sellBook(string s);
	void sellBookI(string i);


	void printTree(Node *tree);

	void printBargain(Node *node, double max);
	void printBargain(double max);
	
	int CountNodes(Node *node);

	void searchISBN(Node *node, string i);
	void searchTitle(Node *node, string t);

	void searchISBN(string i);
	void searchTitle(string t);

	void printBook(Node *node);

	void deleteBook(double price);
	Node* deleteBook(Node *node, double price);
	void swapValues(Node *node, Node* replacement);
	Node* getPredecessor(Node *node);


};

#endif