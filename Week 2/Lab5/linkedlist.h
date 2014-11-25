
/********

Name: Chia, Po Linn
Date: 2014-07-15
Homework #: Lab 5

See main.cpp for sources &c.

*********/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "city.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class LinkedList {

private:

	struct Packet {
		string part;
		Packet *next;
	};

	City *first;
	City *last;
	Packet *message;
	int operations;

public:
	LinkedList();
	~LinkedList();

void appendCity(string name); 

void appendAt(string noob, string key);

void crushCity(string s);

void appendWord(string s);

void transmitMsg(string word);

void printCities();

void printMessage();

int getOperations();

void resetOperations();

void killMsg();

void deallocate();

};

#endif