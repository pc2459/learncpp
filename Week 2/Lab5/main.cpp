/********

Name: Chia, Po Linn
Date: 2014-07-15
Homework #: Lab 5

Linked Lists Basics: http://cslibrary.stanford.edu/103/
Deleting linked list: http://stackoverflow.com/questions/4112905/delete-linked-list
Doubly linked lists: http://www.codeproject.com/Articles/668818/Implementing-a-Doubly-Linked-List-to-be-used-on-an
http://www.techfinite.net/2013/11/double-linked-list-program-and-algorithm.html
Stringstream: http://stackoverflow.com/questions/624260/how-to-reuse-an-ostringstream

Collaborators: Elias, especially for appending using the tail
*********/

#include "city.h"
#include "linkedlist.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){

	//Create an initally empty linked list to store the cities
	LinkedList telegraph;

	// Create the cities and add them to the array
	telegraph.appendCity("Los Angeles");
	telegraph.appendCity("Phoenix");
	telegraph.appendCity("Denver");
	telegraph.appendCity("Dallas");
	telegraph.appendCity("St. Louis");
	telegraph.appendCity("Chicago");
	telegraph.appendCity("Atlanta");
	telegraph.appendCity("Washington D.C.");
	telegraph.appendCity("New York");
	telegraph.appendCity("Boston");

	//Print transmission list
	cout << "======================================================" << endl;
	cout << "Your message will be transmitted through these cities: " << endl;
	cout << "======================================================" << endl;
	telegraph.printCities();
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
	telegraph.transmitMsg(s3);
	while(ss >> s3){ //go through the rest of the sentence
		telegraph.transmitMsg(s3);
	}

	cout << "==========================================" << endl;
	cout << "The final message (after " << telegraph.getOperations() << " operations): " << endl;
	cout << "==========================================" << endl;
	telegraph.printMessage();
	cout << "||| Thanks for using our service!\n" << endl;

	telegraph.resetOperations(); //reset the number of operations
	telegraph.killMsg(); //reset the message

	cout << " / * / * * / *" << endl;
	cout << "/ * * / * / * /" << endl;
	cout << "A huge snowstorm hits!" <<endl;


	telegraph.crushCity("Denver");
	cout << "!!!!!!! It crushed Denver. New telegraph line is as follows: \n";
	cout << "==========================================================" << endl;
	cout << "Your message will now be transmitted through these cities: " << endl;
	cout << "==========================================================" << endl;
	telegraph.printCities();
	cout << endl;

	cout << "\nAdd a new city named:\n>> ";
	string betterthandenver;
	cin.ignore(1000, '\n');
	getline(cin,betterthandenver);

	cout << "And where do you want it inserted after? \n>> ";
	string after;
	getline(cin,after);
	telegraph.appendAt(betterthandenver,after);
	cout << "==========================================================" << endl;
	cout << "Your message will now be transmitted through these cities: " << endl;
	cout << "==========================================================" << endl;
	telegraph.printCities();
	cout << endl;


	ss.str("");
	ss.clear();

	cout << "Give me another file to parse: \n>> ";
	cin >> s;
	msgs.open(s.c_str());
	string temp;
	getline(msgs, temp);
	ss << temp;
	msgs.close();
	string temp2;
	while(ss >> temp2){
		telegraph.transmitMsg(temp2);
	}

	cout << "==========================================" << endl;
	cout << "The final message (after " << telegraph.getOperations() << " operations): " << endl;
	cout << "==========================================" << endl;
	telegraph.printMessage();
	cout << "||| Thanks for using our service!\n" << endl;

	//delete the nodes/garbage collect

	telegraph.killMsg();
	telegraph.deallocate();


}; //end of main