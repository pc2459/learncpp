/********

Name: Chia, Po Linn
Date: 2014-07-24
Homework #: Lab 7

Resources:

Friend classes: http://www.cplusplus.com/doc/tutorial/inheritance/
Deallocating tree: http://www.cprogramming.com/tutorial/lesson18.html
Iterative pre-order traversal: http://www.geeksforgeeks.org/iterative-preorder-traversal/
Ignore: http://www.cplusplus.com/reference/istream/istream/ignore/
Remove BST node: http://dev-faqs.blogspot.com/2012/03/remove-node-from-binary-search-tree.html

Discussed with Elias.


*********/

#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>

int main(){

	Tree bookstore; //create the tree

	cout << bookstore.getRoot() << endl;
	ifstream inventory; //create the inventory

	cout << "Welcome to the Bookstore!" << endl;

//get the inventory file
	string file;
	cout << "What is your inventory file?" << endl;
	cin >> file;

//open the file
	inventory.open(file.c_str());

	string temp;
//read the lines
	while(getline(inventory,temp)){ //while there are lines

		stringstream ss(temp); //parse with a stringstream
		string a, t, i, p1, q1; //strings to store author, title
		//ISBN stored as string to preserve leading 0s

		int q; //ints to store quantity
		double p; //double for price

		getline(ss,a,';'); //get the author into a
		ss.ignore(2, ' '); //ignore everything until the space

		getline(ss,t,';'); //get title into t
		ss.ignore(7); //ignore everything until the space

		getline(ss,i,';');
		ss.ignore(2); //ignore the  $

		ss >> p;
		ss.ignore(1); //ignore the space

		getline(ss,q1, ';');

		//convert quantity to int
		q = atof(q1.c_str());

		bookstore.insert(a, t, i, p, q);


	}

	inventory.close(); //shut off the stream

	bool flag = 0;
	while(!flag){

		//menu of choices
		cout << "1: Print in-order\n2: Search ISBN\n3: Search Title\n";
		cout << "4: Search for a bargain\n5: Buy a book\n";
		cout << "9: Quit" << endl;
		int choice;
		cin >> choice;

		//Print tree
		if(choice == 1){
			bookstore.printTree(bookstore.getRoot());
		}

		//Search by ISBN
		if (choice == 2){
	  		cin.clear();
	  		cin.ignore(INT_MAX, '\n');
			cout << "Input ISBN: ";
			string input;
			cin >> input;

			bookstore.searchISBN(input);
		}
		//Search by Title
		if (choice == 3){

	  		cin.clear();
	  		cin.ignore(INT_MAX, '\n');
			cout << "Input title: ";
			string s;
			getline(cin,s);

			bookstore.searchTitle(s);
		}
		//Get bargain
		if (choice == 4){
			cin.clear();
			cout << "Give me a maximum amount you're willing to pay: ";
			double max;
			cin >> max;
			bookstore.printBargain(max);
		}
		//Sell a book by ISBN or title
		if (choice==5){
			cin.clear();
			cout << "Give me a title (1) or ISBN (2): ";
			int method;
			string s2;
			string i2;
			cin >> method;
			if(method==1){
				cout << "Give me the title to buy: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, s2);
				bookstore.sellBook(s2);
			}
			else if (method == 2){
				cout << "Give me the ISBN of the book to buy: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin,i2);
				bookstore.sellBookI(i2);
			}
		}
		//Exit by setting the flag
		if (choice == 9){
			flag = 1;
		}

	}


}
