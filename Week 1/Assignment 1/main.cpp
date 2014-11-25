/********

Name: Chia, Po Linn
Date: 2014-07-09
Homework #: Assignment 1

Sources consulted:

* http://en.wikipedia.org/wiki/Include_guard
* Input/output http://www.cplusplus.com/doc/tutorial/files/
* Reading in comma separate values http://www.daniweb.com/software-development/cpp/threads/196219/help-reading-a-text-file-separated-by-commas-into-different-arrays
* Counting lines in file http://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
* Jump to Nth line of file http://stackoverflow.com/questions/7273326/getting-the-nth-line-of-a-text-file-in-c
* Compare strings http://www.cplusplus.com/reference/string/string/compare/
* Check for valid integer input http://stackoverflow.com/questions/18567483/c-checking-for-an-integer

Collaborator: Elias, for input parsing and sharing of the above resources

*********/

#include "craigslist.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){

  //welcome message
  	cout << "This is the Board!" << endl;

  //create board
  	Craigslist board;

  //get messages
  	string file;
  	cout << "What is your input file? ";
  	cin >> file;

  //open the file
  	board.openFile(file);

  //start reading the lines
  	while(board.getLinesTotal() > board.getReadLines()){
  	cout << "\nWhat would you like to do? \n";
	cout << " 1 : Read next post\n 2 : Read all remaining posts\n 3 : Print the Board \n 4 : Print the sales docket\n>> ";
	int choice;
	cin >> choice;
	while(cin.fail()){
  		cin.clear();
  		cin.ignore(INT_MAX, '\n');
  		cout << "Invalid input! Try again." << endl;
		cout << " 1 : Read next post\n 2 : Read all remaining posts\n 3 : Print the Board \n 4 : Print the sales docket\n>> ";
	  	cin >> choice;

	}
	switch (choice){
	  	case 1 : 
			board.ReadNextLine();
			break;
		case 2 :
			while(board.getLinesTotal() > board.getReadLines()){
			  board.ReadNextLine();
			}
			break;
		case 3 :
			board.printBoard();
			break;
		case 4 : 
			board.printDocket();
			break;
	} //end switch
  } //end readline while loop

  //finished reading lines
  	while(board.getLinesTotal() == board.getReadLines()){
	  	cout << "You've reached the end of the Board. What do you want to do? \n";
	  	cout << "1 : Print the Board\n2 : Print the sales docket\n3 : Terminate\n>> ";
	  	int choice;
	  	cin >> choice;

	  	while(cin.fail()){
	  		cin.clear();
	  		cin.ignore(INT_MAX, '\n');
	  		cout << "Invalid input! Try again." << endl;
		  	cout << "1 : Print the Board\n2 : Print the sales docket\n3 : Terminate\n>> ";
		  	cin >> choice;
	  	}
	  	switch (choice){
			case 1 :
				board.printBoard();
				break;
			case 2 :
				board.printDocket();
				break;
			case 3 :
		  		goto stop;
	  	}
  	}

  	stop:
  	board.closeFile();

} //end of main