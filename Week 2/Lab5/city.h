/********

Name: Chia, Po Linn
Date: 2014-07-15
Homework #: Lab 5

See main.cpp for sources &c.

*********/

#ifndef CITY_H
#define CITY_H

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;


class City {

public:

	string name;
	string msg;
	City *next;
	City *prev;

	City();
	~City();
	
};

#endif