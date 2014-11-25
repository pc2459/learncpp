/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

Sources: http://www.daniweb.com/software-development/cpp/threads/410327/removing-punctuation-from-string-issue

http://stackoverflow.com/questions/16792456/no-matching-function-for-call-to-transform
*********/

#include "bst.h"
#include "hash.h"
#include "library.h"

#include <iostream>
#include <fstream>
#include <string>


int main(){


	//Initialise the library
	Library myLibrary;

	cout << "This is the Library." << endl;


	int choice;
	int flag = 0;


	while(!flag){
		cout << "=========================================" << endl;
		cout << "0. Quit" << endl;
		cout << "1. Check in a book and get vital stats" << endl;
		cout << "2. Display all titles" << endl;
		cout << "3. Get books within a wordcount range" << endl;
		cout << "4. Get books that contain a keyword" << endl;
		cout << "=========================================" << endl;
		cout << ">> ";

		cin >> choice;

		if(choice == 1){
			cout << "Type a filename: ";

			string file;
			cin >> file;
			//Read in the file
			myLibrary.fileBook(file);

			//Get the newly loaded book and get its states
			Book *latest = myLibrary.getLast();
			cout << " * * * * * * * * * * *" << endl;
			cout << latest->getTitle() << " by " << latest->getAuthor() << endl;
			cout << "Total words: ";
			cout << latest->getWords();
			cout << "\n";
			cout << "Total unique words: ";
			cout << latest->getUniqueWords();
			cout << "\n";

			cout << "Top 5 frequent words:" << endl;
			latest->getFrequent(5);
			cout << "\n";

			cout << "Top 5 unique frequent words: " << endl;
			latest->getFrequentUnique(5);
			cout << "\n";

			cout << "That took " << latest->getOps() << " operations" << endl;
			cout << " * * * * * * * * * * *" << endl;		

		}

		else if(choice ==2){
			myLibrary.printBooks();
		}

		else if(choice == 3){
			int low, high;
			cout << "Give me a two-number word count range (e.g. 25 500): ";
			cin >> low >> high;
			cout << " * * * * * * * * * * *" << endl;			
			myLibrary.getByWords(low, high);
			cout << " * * * * * * * * * * *" << endl;			

		}

		else if(choice == 4){
			string search;
			cout << "Give me a keyword to search for: ";
			cin >> search;
			cout << " * * * * * * * * * * *" << endl;						
			myLibrary.getByKeyword(search);
			cout << " * * * * * * * * * * *" << endl;			

		}

		else if(choice == 0){
			flag = 1;
		}

	}


}


