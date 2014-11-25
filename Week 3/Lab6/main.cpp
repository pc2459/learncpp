/********

Name: Chia, Po Linn
Date: 2014-07-23
Homework #: Lab 6

Resources:

Friend classes: http://www.cplusplus.com/doc/tutorial/inheritance/
Deallocating tree: http://www.cprogramming.com/tutorial/lesson18.html

Discussed with Elias.
*********/

#include "bst.h"
#include <iostream>

int main(){

	int flag = 0;
	Tree bst;

	while (!flag){

		cout << "1: Add node \n2: Quit \n3: Print tree" << endl;
		int choice;
		cin >> choice;

		if (choice == 1){
			cout << "Add a new node to the Binary Search Tree: ";
			int n;
			cin >> n;
			//Add a new node to the tree and update its root
			bst.setRoot(bst.addNode(bst.getRoot(),n));

		}

		if (choice == 2){
			flag = 1;
		}

		if (choice == 3) {
			bst.printTree(bst.getRoot());
			cout << endl;
		}
	}//end while

	return 0;
}
