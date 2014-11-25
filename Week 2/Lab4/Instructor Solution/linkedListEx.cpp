#include <iostream>
#include "linkedListEx.h"
#include <string>
using namespace std;

City::City(string n){
	name = n;
    next = 0;
}

City::~City(){
    cout<<"calling destructor"<<endl;
}

void City::setNext(City *n){
    next = n;
}
City* City::getNext(){
	return next;
}

void City::setMsg(string msgIn){
    msg = msgIn;
}

string City::getMsg(){
    return msg;
}
void City::setName(string msgIn){
    name = msgIn;
}
void City::transmitMsg(){
    City *n;
    n = next;
    cout<<"message handed to "<<n->getName()<<endl;
    n->setMsg(msg);
    msg = "";
}

string City::getName(){
    return name;
}
