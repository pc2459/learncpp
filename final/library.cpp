/********

Name: Chia, Po Linn
Date: 2014-08-05
Homework #: Final Project
Instructor: I. Fleming

See main.cpp for sources &c.

*********/

#include "library.h"


//========== LIBRARY ===========/

//*** LIBRARY INITIALISERS

//Constructor
Library::Library(){
	//Set up the "stack" of books
	bookcount = -1;
	shelf = new Book*[50];
}

//Destructor
Library::~Library(){
	for(int i = 0; i <= bookcount; i++){
		Book *temp = shelf[i];
		delete temp;
	}
	delete [] shelf;
}

//Initialise a book and store it in the library
void Library::fileBook(string s){
	bookcount++;
	shelf[bookcount] = new Book(s);
}

//**** LIBRARY ACCESSORS

//Get the last book to be put in the library
Book* Library::getLast(){
	return shelf[bookcount];
}

//Get a book at the nth location in the library
Book* Library::getBook(int i){
	return shelf[i];
}

//**** LIBRARAY FUNCTIONS

//Get books that fit within a wordcount range
void Library::getByWords(int low, int high){
	//Iterate through the library
	for(int i = 0; i <= bookcount; i++){
		//If a book falls within a wordcount range
		if(shelf[i]->getWords() > low && shelf[i]->getWords() < high){
			//Print it
			cout << shelf[i]->getTitle() << " by " << shelf[i]->getAuthor();
			cout << " (" << shelf[i]->getWords() << " words)" << endl; 
		}
		else{
			//do nothing
		}
	}
}

//Get books that contain a keywords
void Library::getByKeyword(string s){
	for(int i = 0; i <= bookcount; i++){
		if(shelf[i]->findWord(s)){
			cout << shelf[i]->getTitle() << " by " << shelf[i]->getAuthor() << endl;
		}
	}
}

//Print everything on your shelf
void Library::printBooks(){
	for(int i = 0; i <= bookcount; i++){
		cout << shelf[i]->getTitle() << " by " << shelf[i]->getAuthor();
		cout << " (" << shelf[i]->getWords() << " words)" << endl;
	}
}


//================ BOOK ================//

//**** BOOK INITIALISERS

Book::Book(string s){

	opcount = 0;

	//Build list of common words into a hashtable for quick lookup

	//Create hashtable
	stoplist = new HashTable(30);
	//Open stoplists file
	ifstream c;
	c.open("common.txt");
	string stopword;
	//Insert into hashtable
	while(getline(c, stopword, ',')){
		stoplist->insert(stopword);
	}
	c.close();

	//Build the book

	//Open file
	ifstream b;
	b.open(s.c_str());
	string temp;
	getline(b, temp);

	//Get title and author
	//Read the first line which is in the format title;author
	stringstream ss(temp);
	string a, t;
	getline(ss, t, ';');
	getline(ss, a, ';');
	author = a;
	title = t;

	//Read words into a tree
	string word;
	while(b >> word){
		//strip common punctuation
		int len = word.length();
		for(int i = 0; i < len; i++){
			if(ispunct(word[i])){
				word.erase(i,1);
				opcount++;
				i--;
			}
		}
		//transform words to lowercase for easier matching
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		opcount++;

		//register the word if it is valid after scrubbing
		if(word.length() > 0){
			//add to the wordcount
			wordcount++;
			//pipe into the binary tree
			insertlist.insert(word);
			//increment operations 
			opcount++;
		}
	}

	b.close();

	//set the number of unique words
	size = insertlist.count();
	//copy tree into an array
	copyArray();
	//sort array by frequency (low-to-high)
	insertionSort();
	//read array into a balanced BST
	buildFrequencyTree();

}

Book::~Book(){
	delete [] array;
	delete stoplist;

}

//Copy the initial Book tree into an array
void Book::copyArray(){

	if (insertlist.getRoot() == NULL)
		return;

	//Create array of the needed size
	array = new Node[size];

	//Call the BST function to copy the tree
	int i = 0;
	insertlist.copyToArray(array, &i);

}


//Perform an insertion sort on the array
void Book::insertionSort(){
	int j;
	Node temp;

	for(int i = 1; i < size; i++){
		j = i;
		while (j>0 && array[j].freq < array[j-1].freq){
			temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
			j--;
			//increment operator count
			opcount += 2;
		}
	}
}


//Build a balanced tree with the n/2th most frequent word as the root
void Book::buildFrequencyTree(){
	frequencylist.setRoot(frequencylist.arrayToBST(array,0,size-1));
}


//Search for a word in the book
bool Book::findWord(string s){
	//Feed address of a bool in to keep track of whether the word is found
	//since the search traverses the entire tree
	bool found = 0;
	frequencylist.resetSearchOps();
	frequencylist.lookup(s, &found);
	if(found)
		cout << "Found on the " << frequencylist.getSearchOps() << "th operation in ";
	if(!found)
		cout << "Not found in " << title << " ): Wasted " << frequencylist.getSearchOps() << " operations." << endl;
	return found;
}

//Get i number of frequent words
void Book::getFrequent(int i){

	//check to make sure there are enough words
	if(i > size){
		cout << "You've asked for more words than are in the book" << endl;
	}
	else{
		for(int j = size-1; j > (size - 1 - i); j--){
		cout << array[j].data << " (" << array[j].freq << " uses)" << endl;
		opcount++;
		}
	}

}

//Get i number of unique frequent words
void Book::getFrequentUnique(int i){

	//check to make sure there are enough words
	if (i > size)
		return;

	int found = 0;
	int j = size-1;
	while(found < i){	
		if(j > 0 && stoplist->find(array[j].data)){
			
		}
		else{
			cout << array[j].data << " (" << array[j].freq << " uses)" << endl;
			opcount++;
			found++;	
		}
		j--;
	}
}

//Return author
string Book::getAuthor(){
	return author;
}

//Return title
string Book::getTitle(){
	return title;
}

//Return word count
int Book::getWords(){
	return wordcount;
}

//Return count of BST nodes ==> unique words
int Book::getUniqueWords(){
	return size;
}

//Return count of operations
int Book::getOps(){
	opcount = opcount + frequencylist.getOps() + insertlist.getOps() + stoplist->getOps();
	return opcount;
}

int Book::getSearchOps(){
	return frequencylist.getSearchOps();
}