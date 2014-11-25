/********

Name: Chia, Po Linn
Date: 2014-07-29
Homework #: Lab 8
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#include <string>
#include <iostream>

using namespace std;

class HashEntry{

private:

	string key;
	HashEntry* next;

public:

	HashEntry();
	HashEntry(string name);
	~HashEntry();
	string getKey();
	HashEntry* getNext();
	void setNext(HashEntry *entry);

};

class HashTable{

private:

	HashEntry** table; //pointer to a table of pointers to entries
	int tablesize;

public: 

	HashTable();
	HashTable(int size);
	~HashTable();

	int hash(const string &value);

	void insert(string value);
	void del(string value);
	void find(string value);
	void print();

};

