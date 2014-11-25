/********

Name: Chia, Po Linn
Date: 2014-07-14
Homework #: Lab 4

See main.cpp for sources &c.

*********/

#include "linkedlist.h"
#include <cstdlib>
#include <string>

void appendCity(struct City **list, string name){

	City *head = *list;

	City *newCity = new City;
	newCity->name = name;
	newCity->next = NULL;

	if (head == NULL){ //add new city in if the list is empty
		*list = newCity;

	}
	else{ //otherwise...
		while(head->next != NULL){ //iterate through to the last city
			head = head->next;
		}
		head->next = newCity; //attach the new city

	}	
}

void appendWord(struct Packet **list, string s){

	Packet *head = *list;
	
	Packet *newPacket = new Packet;
	newPacket->part = s;
	newPacket->next = NULL;

	if (head == NULL) { //if the list is empty
		*list = newPacket; //assign the word as the first item
	}
	else{
		while(head->next != NULL){
			head = head->next; //iterate to find last place
		}
		head->next = newPacket; //fill in new word
	}
}

void transmitMsg(struct City *list, string word, struct Packet **message){

	//Transmit function. Enable to comments to see the flow during execution.

	City *head;
	head = list;
	head->msg = word;
	//cout << "DEBUG: Transmitted " << head->msg << " to " << head->name << endl;
	while(head->next != NULL){
		head->next->msg = head->msg;
		head->msg = '\0';
		head = head->next;
		//cout << "DEBUG: Transmitted " << head->msg << " to " << head->name << endl;

	}

	//Append to final sentence after passing through the last city
	appendWord(message, head->msg);

}

void printCities(struct City *list){

    City *p; 
    p = list;
    cout << p->name << endl;
    while ( p->next != NULL){
        p = p->next;
        cout << p->name << endl;
    }

}

void printMessage(struct Packet *list){
	Packet *p;
	p = list;
	cout << p->part;
	while (p->next != NULL){
		p = p->next;
		cout << " " << p->part;
	}
	cout << endl;

}

void deallocate(struct City *list){

	while(list){
		City *trash = list;
		list = list->next;
		delete trash;

	}
}


void deallocate(struct Packet *list){


	while(list){
		Packet *trash = list;
		list = list->next;
		delete trash;

	}
}