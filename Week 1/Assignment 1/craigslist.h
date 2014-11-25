/********

Name: Chia, Po Linn
Date: 2014-07-09
Homework #: Assignment 1

See main.cpp for sources &c.

*********/

#ifndef CRAIGSLIST_H
#define CRAIGSLIST_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

class Craigslist {

  private:
    struct Post{
        string type;
        double price;
        bool status; //1 for sale, 0 wanted

    };

    Post wanted[100];
    Post selling[100];
//    Post temp;
    ifstream msgs;
    ofstream docket;
    int totalLines;
    int numLines;
    int wantedCount;
    int sellingCount;
    int totalSales;
    int operations;

    //Remove or add post from array
    void RemWantedPost(int found);
    void RemSalePost(int found);


  public:


    //Constructor
    Craigslist();

    //Destructor
    ~Craigslist();

    void openFile(string file);
    void closeFile();

    // void findTotalLines(string file);

    //Get read and total lines of input file
    int getReadLines();
    int getLinesTotal();

    void RecordSale(int foundindex);
    void RecordSale(string type, double price);
    //Read next post
    void ReadNextLine();

    //Print board
    void printBoard();

    //Print docket
    void printDocket();

};

#endif
