/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>

using namespace std;

class HashEntry{

private:

	string key;
	HashEntry* next;

public:

	HashEntry();
	HashEntry(string word);
	~HashEntry();
	string getKey();
	HashEntry* getNext();
	void setNext(HashEntry *entry);

};

class HashTable{

private:

	HashEntry** table; //pointer to a table of pointers to entries
	int tablesize;
	int opcount;

public: 

	HashTable();
	HashTable(int size);
	~HashTable();

	int hash(const string &value);

	void insert(string value);
	void del(string value);
	bool find(string value);
	void print();

	int getOps();

};

#endif

