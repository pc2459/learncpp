/********

Name: Chia, Po Linn
Date: 2014-07-14
Homework #: Lab 4

Linked Lists Basics: http://cslibrary.stanford.edu/103/
Deleting linked list: http://stackoverflow.com/questions/4112905/delete-linked-list

*********/

#include "linkedlist.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){

	//Create an initally empty list to store the cities
	struct City *list = NULL;

	//Initially empty list to store the message
	struct Packet *message = NULL;

	// Create the cities and add them to the array

	appendCity(&list, "Los Angeles");
	appendCity(&list, "Phoenix");
	appendCity(&list, "Denver");
	appendCity(&list, "Dallas");
	appendCity(&list, "St. Louis");
	appendCity(&list, "Chicago");
	appendCity(&list, "Atlanta");
	appendCity(&list, "Washington D.C.");
	appendCity(&list, "New York");
	appendCity(&list, "Boston");

	//Print transmission list
	cout << "====================================" << endl;
	cout << "Your message will be transmitted through these cities: " << endl;
	cout << "====================================" << endl;
	printCities(list);
	cout << endl;

	//Open the message file and get the line
	ifstream msgs; 
	cout << "Give me a file to parse: " << endl;
	string s;
	cin >> s;
	msgs.open(s.c_str());

	string s2;
	getline(msgs, s2); //get the line
	stringstream ss(s2); //store it in a ss for parsing
	msgs.close(); 

	string s3;
	ss >> s3; //get the first element
	transmitMsg(list, s3, &message);
	while(ss >> s3){ //go through the rest of the sentence
		transmitMsg(list, s3, &message);
	}

	cout << "====================================" << endl;
	cout << "The final message: " << endl;
	cout << "====================================" << endl;
	printMessage(message);
	cout << "\n|||| Thanks for using our service! Goodbye.\n" << endl;

	//Deallocate the lists

	deallocate(list);
	deallocate(message);



	//don't need to store it at this time


	//delete the nodes/garbage collect


}; //end of main