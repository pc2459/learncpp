#ifndef LINKEDLISTEX_H_INCLUDED
#define LINKEDLISTEX_H_INCLUDED
#include <string>

using namespace std;

class City{
	private:
	string name;
	string msg;
	City *next;

	public:
	City(string);
	~City();
	City *getNext();
	void setNext(City *n);
    void setMsg(string);
    string getMsg();
    void setName(string);//probably not needed
    string getName();
    void transmitMsg();

};




#endif // LINKEDLISTEX_H_INCLUDED
