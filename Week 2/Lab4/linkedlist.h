/********

Name: Chia, Po Linn
Date: 2014-07-14
Homework #: Lab 4

See main.cpp for sources &c.

*********/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;


struct City {

	string name;
	string msg;
	City *next;
};

struct Packet {
	string part;
	Packet *next;

};

//struct Packet *message;


	//struct City *head; //pointer to first node
	
	//takes a list of cities and appends a new city
void appendCity(struct City **list, string name); 


void appendWord(string *list, string s);


void transmitMsg(struct City *list, string word, struct Packet **message);
// void transmitMsg(struct City *list, string word);


void printCities(struct City *list);

void printMessage(struct Packet *list);

void deallocate(struct Packet *list);
void deallocate(struct City *list);

#endif