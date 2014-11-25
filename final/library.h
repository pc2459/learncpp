/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#ifndef LIBRARY_H
#define LIBRARY_H

#include "hash.h"
#include "bst.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class Book{

	friend class Library;
	string author;
	string title;

	int wordcount;
	int size;
	
	HashTable* stoplist;
	Tree insertlist;
	Tree frequencylist;
	Node* array;

	int opcount;

public:

	Book(string s);
	~Book();

	void copyArray();
	void insertionSort();
	void buildFrequencyTree();

	bool findWord(string s);

	string getAuthor();
	string getTitle();
	void getFrequent(int i);
	void getFrequentUnique(int i);
	int getWords(); //return counter
	int getUniqueWords(); //count BST nodes
	int getOps();
	int getSearchOps();
};

class Library{

	friend class Book;
	Book** shelf;
	int bookcount;

public:
	Library();
	~Library();

	Book* getBook(int i);
	Book* getLast();
	void fileBook(string s);
	void getByWords(int low, int high);
	void getByKeyword(string s);
	void sortBooks();
	void printBooks();

};

#endif