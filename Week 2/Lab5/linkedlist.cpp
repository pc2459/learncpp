/********

Name: Chia, Po Linn
Date: 2014-07-15
Homework #: Lab 5

See main.cpp for sources &c.

*********/

#include "linkedlist.h"

LinkedList::LinkedList(){
	first = NULL;
	last = NULL;
	operations = 0;
	message = new Packet;
}

LinkedList::~LinkedList(){

}

void LinkedList::appendCity(string name){

	City *head;
	head = first;
	City *tail;
	tail = last;

	City *newCity = new City;
	newCity->name = name;
	newCity->next = NULL;

	 if (head == NULL){ //add new city in if the list is empty
	 	newCity->prev = NULL;
	 	first = newCity;
	 	last = newCity;

	 	++operations;

	}
	else{
		// while(head->next != NULL){
		// 	head = head->next;
		// }
		tail->next = newCity;
		newCity->prev = tail;
	 	last = newCity;

	 	++operations;
	}
}

// Append a new city after another city
void LinkedList::appendAt(string noob, string key){

	City *temp = first;
	while (temp != NULL){ //iterate and find the key
		if((temp->name).compare(key) == 0 ){
			break;
		}
		else{ 
			temp=temp->next;
		}
	}
	City *newCity = new City; //create and insert new city

	newCity->name = noob;
	newCity->next = temp->next;
	newCity->prev = temp;
	temp->next = newCity;
	++operations;
}


// Search for a city and it delete
void LinkedList::crushCity(string s){

	if((first->name).compare(s) == 0){
		first=first->next; //make the next city in list the head
		first->prev = NULL; //null the old head pointer
		++operations;
		return;
	}
	if((last->name).compare(s) == 0){
		last = last->prev; //ditto on the back end of the list
		last->next = NULL;
		++operations;
		return;
	}

	City *temp = first->next;
	while(temp != NULL){
		if((temp->name).compare(s) == 0){
			break;
		}
		else {
			temp=temp->next;
		}
	}
	(temp->prev)->next = temp->next; //reset the pointers
	(temp->next)->prev = temp->prev;
	++operations;
}

// Insert new city after <key>, reset the pointers 
void LinkedList::appendWord(string s){

	Packet *head = message;
	
	Packet *newPacket = new Packet;
	newPacket->part = s;
	newPacket->next = NULL;

	if (head == NULL) { //if the list is empty
		message = newPacket; //assign the word as the first item
	}
	else{
		while(head->next != NULL){
			head = head->next; //iterate to find last place
		}
		head->next = newPacket; //fill in new word
	}
}

void LinkedList::transmitMsg(string word){

	//Transmit function. Enable to comments to see the flow during execution.
	City *head;
	head = first;
	head->msg = word;
	//cout << "DEBUG: Transmitted " << head->msg << " to " << head->name << endl;
	while(head->next != NULL){
		head->next->msg = head->msg;
		head->msg = '\0';
		head = head->next;
		++operations;
		//cout << "DEBUG: Transmitted " << head->msg << " to " << head->name << endl;

	}
	//Have hit the end of the line... retransmit from last
	//cout << "************* TURNAROUND ***********" << endl;
	head = last;
	head->msg = word;

	while(head->prev != NULL){
		head->prev->msg = head->msg;
		head->msg = '\0';
		head = head->prev;
		++operations;
		//cout << "DEBUG: RE-Transmitted " << head->msg << " to " << head->name << endl;
	}
	//Append to final sentence after passing through the last city
	appendWord(head->msg);
}

//Iterate through and print cities on the line
void LinkedList::printCities(){

    City *p; 
    p = first;
    cout << p->name << endl;
    while ( p->next != NULL){
        p = p->next;
        cout << p->name << endl;
    }

}

//Iterate through and print the message
void LinkedList::printMessage(){
	Packet *p;
	p = message;
	cout << p->part;
	while (p->next != NULL){
		p = p->next;
		cout << " " << p->part;
	}
	cout << endl;

}

//Return number of operations
int LinkedList::getOperations(){
	return operations;
}

//Reset number of operations to 0
void LinkedList::resetOperations(){
	operations = 0;
}

//Reset the message to null
void LinkedList::killMsg(){
	while(message){
		Packet *trash = message;
		message = message->next;
		delete trash;
	}
}

//Deallocate the linked list
void LinkedList::deallocate(){

	while(first){
		City *trash = first;
		first = first->next;
		delete trash;
	}
}
