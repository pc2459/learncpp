/********

Name: Chia, Po Linn
Date: 2014-07-09
Homework #: Assignment 1

See main.cpp for sources &c.

*********/

#include "craigslist.h"
	
	//Constructor
Craigslist::Craigslist(){
	totalLines = 0;
	numLines = 0;
	wantedCount = 0;
	sellingCount = 0;
	totalSales = 0;
	operations = 0;
	docket.open("docket.txt");

}

	//Destructor
Craigslist::~Craigslist(){
	docket.close();
}

	//Open file
void Craigslist::openFile(string file){
	string in;
	in = file;
	msgs.open(in.c_str());
	
	while(!msgs){
  		cin.clear();
  		cin.ignore(INT_MAX, '\n');
		cout << "Please enter a valid input file: \n>> ";
		cin >> in;
		msgs.open(in.c_str());
	}		
	++operations;	

	//fine the total number of lines
	string s;
	while (getline(msgs,s)){
		++totalLines;
		++operations;
	}
	msgs.close();

	//reopen the file for use
	msgs.open(in.c_str());
}

	//Close file
void Craigslist::closeFile(){
	msgs.close();
}

	//Get lines read and total lines in input file
int Craigslist::getReadLines(){
		return numLines;
}
int Craigslist::getLinesTotal(){
		return totalLines;
} 

	//Remove or add post from array
void Craigslist::RemWantedPost(int found){
	for(int i = found; i < wantedCount; i++){
			wanted[i] = wanted[i+1]; //write everything to the left
			++operations;
	}
	wantedCount--;
}

void Craigslist::RemSalePost(int found){
	for(int i = found; i < sellingCount; i++){
			selling[i] = selling[i+1];
			++operations;
	}
	sellingCount--;
}

//Write to docket
void Craigslist::RecordSale(int foundindex){
	docket << selling[foundindex].type << " was sold @ $" << selling[foundindex].price << endl;
}

void Craigslist::RecordSale(string type, double price){
	docket << type << " was sold @ $" << price <<  endl;
}

//Read next post
void Craigslist::ReadNextLine(){

	//Read and create a temporary Post from a line
	Post temp;
	string tempType;
	string tempStatus;
	double tempPrice;
	string s, s1, s2, s3;

	getline(msgs,s); //get line, store in s
	++numLines;
	++operations;
	
	stringstream ss(s); //parse through the commas		
	getline(ss,s1,',');
	tempType = s1; 
	getline(ss,s2, ',');
	s2.erase(0,1);
	tempStatus = s2; 
	getline(ss,s3, ',');
	tempPrice = atof(s3.c_str());
	//http://stackoverflow.com/questions/4754011/c-string-to-double-conversion

	//get and store values in the temp Post
	temp.type = tempType;
	temp.price = tempPrice;

	//Check to see if for sale or wanted
	if(tempStatus.compare("for sale") != 0) {
		temp.status = 0;
		++operations;
	}
	else{
		temp.status = 1;
		++operations;
	}


	/*

	I'm choosing to store wanted and for sale items in two separate arrays. Though this
	takes an extra (worst case) n number of steps to identify what sort of item they are,
	this ensures that the search for matches will be called against smaller arrays as 
	opposed to an n-sized array each time.

	I chose not to use a faster (e.g. binary) search for matches because that would require
	sorting both arrays. Sorting both arrays by copying every insertion to the right would have
	required (worst case) around n^2 number (n to find the insertion point, n to insert and 
	move everything) of operations.	The savings from using a binary search would not have 
	made up for that cost.


	*/

	int foundindex;

	// Case of adding a sale item
	if(temp.status == 1){
		bool found = false;
		for(int i=0; i < wantedCount; i++){ //check for first match in price and type
			++operations;
			if(temp.type.compare(wanted[i].type) == 0 && temp.price <= wanted[i].price){
				found = 1;
				foundindex = i;
				break;
			}          
		}

		if(found){
			RemWantedPost(foundindex);
			RecordSale(foundindex);
			++totalSales;
		}
		else{ //add it to the array
			selling[sellingCount] = temp;
			sellingCount++;
			++operations;
		}
	}

	// Case of dealing with a wanted item
	else if(temp.status == 0){
		bool found = false;
		for(int i=0; i < sellingCount; i++){ //check for first match in price and type
			++operations;
			if(temp.type.compare(selling[i].type) == 0 && temp.price >= selling[i].price){
				found = 1;
				foundindex = i;
				break;
			}          
		}
		
		if(found){
			RecordSale(temp.type, temp.price);
			RemSalePost(foundindex);
			++totalSales;
		}
		else{ //add it to the array
			wanted[wantedCount] = temp;
			wantedCount++;
			++operations;
		 //cout << "DEBUG: Wanted #: " << wantedCount << "\n \n";
		}
	}
}

	//Print board
void Craigslist::printBoard(){
	cout << "FOR SALE: \n";
	for(int i = 0; i < sellingCount; i++){
		cout << selling[i].type << " @ $" << selling[i].price << endl; 
	}
	cout << "\nWANTED: \n";
	for(int j = 0; j < wantedCount; j++){
		cout << wanted[j].type << " @ $" << wanted[j].price << endl; 
	}      
	cout << "\nSold: " << totalSales << ", for sale: " << sellingCount << ", wanted: " << wantedCount << "\n";
	cout << "Total operations: " << operations << "\n\n";
}

	//Print docket
void Craigslist::printDocket(){
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout << "                             SALES DOCKET                              ";
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";

	string s;
	ifstream opendocket ("docket.txt");
	while(getline(opendocket,s)){
		cout << s << endl;
	}
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	opendocket.close();
}

	

