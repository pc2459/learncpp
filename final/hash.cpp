/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#include "hash.h"
//#include "library.h"

//Default constructor
HashEntry::HashEntry(){
	key = '\0';
	next = NULL;
}

//Constructor with args
HashEntry::HashEntry(string word){
	key = word;
	next = NULL;
}

//Destructor
HashEntry::~HashEntry(){

}

//Get a key
string HashEntry::getKey(){
	return key;

}

//Get next pointer
HashEntry* HashEntry::getNext(){
	return next;
}

//Set next pointer
void HashEntry::setNext(HashEntry *entry){
	this->next = entry;
}

//======= HashTable 

//Default constructor
HashTable::HashTable(){

}

//Constructor
HashTable::HashTable(int size){
	tablesize = size;
	//create table
	opcount = 0;
	table = new HashEntry*[size];
	//populate with null pointers
	for(int i = 0; i < size; i++){
		table[i] = NULL;
	}
}

HashTable::~HashTable(){
	for(int i = 0; i < tablesize; i++){
		if(table[i] != NULL){
			//create a pointer to the bucket 
			HashEntry *current = table[i];
			//create a temp pointer to delete items 
			HashEntry *temp; 
			while(current){
				temp = current;
				current = current->getNext();
				delete temp;
			}
		}
	}

	delete[] table;
}

/*

To generate my hash, I added every second (character * 33) and then 
found the mod of the sum. I hoped to generate a random spread even 
with name that have the same starting letters (Charles, Charlie).
Taking every other letter helps keep the size down on really long names.

*/

//Generate a hash given a key string value
int HashTable::hash(const string &value){
	unsigned int h = 0;
	int length = value.length(); //reduce the number of calls on length

	//take every second character to reduce size
	for(int i = 0; i < length; i+=2){
		//multiply by some prime value and add
		h = h + value[i]*33;
	}
	//mod to get a bucket
	h = h % tablesize;
	//cout << h << endl;
	return h;

}

//Insert a value into a hash table.
void HashTable::insert(string value){

	//hash the key
	int h;
	h = hash(value);

	//check if bucket is empty at that hash
	if (table[h] == NULL){
		//insert if so
		table[h] = new HashEntry(value);
		opcount++;

	}

	//if the hash is not empty, chain it
	else{
		//get the old head
		HashEntry* oldhead = table[h];
		//set the new entry as head
		table[h] = new HashEntry(value);
		//link it to the old head
		table[h]->setNext(oldhead);
		opcount += 2;
	}
}

//Delete a value from a hash table
void HashTable::del(string value){
	//hash the key
	int h;
	h = hash(value);

	//case if hash bucket is empty
	if (table[h] == NULL){
		cout << "Nothing to delete" << endl;
	}
	//if there is something at the bucket
	else {
		HashEntry *temp = table[h];
		HashEntry *prev = NULL;

		//iterate until you get a match
		while(temp->getNext() != NULL && value.compare(temp->getKey()) != 0){
			prev = temp; //keep track of the previous node
			temp = temp->getNext();
		} 
		//if the values compare correctly, delete
		if (value.compare(temp->getKey()) == 0){

			//IF ENTRY IS THE HEAD OF THE CHAIN
			//Set a new head and delete old entry 
			if(prev == NULL){
				HashEntry *head = temp->getNext();
				table[h] = head;
				cout << "Deleting " << temp->getKey();
				delete temp;

			}
			//OTHERWISE 
			//delete the entry and reattach the chain 
			else{
				prev->setNext(temp->getNext());
				cout << "Deleting " << temp->getKey();
				delete temp;
			}
		}	
	}
}

//find a value in the table
bool HashTable::find(string value){
	int h;
	h = hash(value);

	//case if hash bucket is empty
	if (table[h] == NULL){
		opcount++;
		return 0;

//		cout << "No" << endl;

	}

	//if there is something at the bucket
	else {

		HashEntry *temp = table[h];

		//iterate until you get a match
		while(temp->getNext() != NULL && value.compare(temp->getKey()) != 0){
			temp = temp->getNext();
			opcount++;

		} 
		//if the values compare correctly, print
		if (value.compare(temp->getKey()) == 0){
			opcount++;
			return 1;
			//cout << "Yes, found at table index " << h << endl;
		}
		//else report not found
		else{
			opcount++;
			return 0;
			//cout << "No such person." << endl;
		}
	}
}

//Print the table
void HashTable::print(){
	//iterate down the array
	for(int i = 0; i < tablesize; i++){
		if (table[i] != NULL){
			//Iterate through the chains
			HashEntry *head = table[i];
			while (head != NULL){
				cout << head->getKey() << endl;
				head = head->getNext();
			}
		}
		else{ //do nothing if bucket is empty
		}
	}
}


int HashTable::getOps(){
	return opcount;
}