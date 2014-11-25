/********

Name: Chia, Po Linn
Date: 2014-07-29
Homework #: Lab 8
Instructor: I. Fleming

Sources: http://www.algolist.net/Data_structures/Hash_table/Chaining


*********/

#include "hash.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

int main(){


	//create the hash table
	HashTable table = HashTable(25);

	//get user input
	string choice;
	cout << "Welcome to the hash table. Choose an option below:\n" << endl;

	int flag = 0;
	while (flag == 0){
		
		cout << left;
		cout << setw(20) << "i: insert a name" << setw(20) <<  "d: delete a name" << endl;
		cout << left;
		cout <<  setw(20) << "f: find a name" << setw(20) << "p: print" << endl;
		cout << left;
		cout << setw(20) << "Other: quit." << endl;
		cout << ">>";

		cin >> choice;

		//insert name
		if (choice.compare("i") == 0){
			cin.ignore();
			cout << "Type in a name to add: ";
			string name;
			getline(cin,name);
			table.insert(name);
			cout << "\n" << endl;

		}

		//delete name
		else if (choice.compare("d") == 0){
			cin.ignore();
			cout << "Type in a name to delete: ";
			string del;
			getline(cin,del);
			table.del(del);
			cout << "\n" << endl;			
		}

		//find name
		else if (choice.compare("f") == 0){
			cin.ignore();
			cout << "Type in a name to find: ";
			string search;
			getline(cin,search);
			table.find(search);			
			cout << "\n" << endl;						
		}

		//print name
		else if (choice.compare("p") == 0){
			table.print();
			cout << "\n" << endl;			
		}	

		else{
			flag = 1;
		}
	}
	
}