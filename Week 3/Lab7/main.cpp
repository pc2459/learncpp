/********

Name: Chia, Po Linn
Date: 2014-07-24
Homework #: Lab 7

Resources:

Friend classes: http://www.cplusplus.com/doc/tutorial/inheritance/
Deallocating tree: http://www.cprogramming.com/tutorial/lesson18.html
Iterative pre-order traversal: http://www.geeksforgeeks.org/iterative-preorder-traversal/

Discussed with Elias.
*********/

#include "bst.h"
#include <iostream>

int main(){

	int flag = 0;
	Tree bst;

	while (!flag){

		cout << "1: Add node \n2: Print tree \n3: Count iteratively \n4: Count recursively \n5: Quit" << endl;
		int choice;
		cin >> choice;

		if (choice == 1){
			cout << "Add a new node to the Binary Search Tree: ";
			int n;
			cin >> n;
			//Add a new node to the tree and update its root
			bst.setRoot(bst.addNode(bst.getRoot(),n));

		}

		if (choice == 5){
			cout << "Terminating... Your tree has " << bst.CountNodes_R(bst.getRoot()) << " nodes." << endl;
			flag = 1;
		}

		if (choice == 2) {
			bst.printTree(bst.getRoot());
			cout << endl;
		}

		if(choice == 3){
			cout << "Your tree has " << bst.CountNodes(bst.getRoot()) << " nodes." << endl;
		}

		if(choice == 4){
			cout << "Your tree has " << bst.CountNodes_R(bst.getRoot()) << " nodes." << endl;
		}
	}//end while

	return 0;
}
