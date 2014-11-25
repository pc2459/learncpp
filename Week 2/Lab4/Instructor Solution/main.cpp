#include <iostream>
#include <fstream>
#include <string>
#include "linkedListEx.h"

using namespace std;

int main()
{
    int i = 2;
    string strArray[] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C", "New York", "Boston"};

    //build City network first
    City *city;
    city = new City(strArray[0]);
    City *head;
    head = city;

    City *next;
    next = new City(strArray[1]);
    city->setNext(next);

    while (i < 10){
     next = new City(strArray[i]);
     city = city->getNext();
     city->setNext(next);
     i++;
    }
    //start back at the beginning
    city = head;
    while(city->getNext()!=0){
        cout<<city->getName()<<endl;
        city = city->getNext();
    }
    cout<<city->getName()<<endl; //the last one
    //this printing just verifies names are correct

    //set city back to beginning to transmit through all cities
    ifstream infile;
    infile.open("messageIn.txt"); // open file
    string token;
    while(getline(infile, token, ' ')){
        city = head;
        city->setMsg(token);
//        cout<<token<<endl;
        while(city->getNext()!=0){
            city->transmitMsg();
            city = city->getNext();
        }
        //print message received in Boston
        cout<<city->getMsg()<<endl;

    }


    return 0;
}
