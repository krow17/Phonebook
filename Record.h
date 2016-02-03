/*
Kyle Rowland 
csce 221 - 505
Record.h
*/

#include "TemplateDoublyLinkedList.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
class Record //class declaration
{
	private:
		string first, last;
		int uin, phone;
	public:
		Record(); // constructor
		Record(string l, string f, int id, int p); //secondary constructor
		string setFirst(string f); //set first name
		string setLast(string l); //set last name
		int setID(int id); //set UIN
		int setPhone(int p); //set phone number
		string getFirst() const; //return first name
		string getLast() const; //return last name
		int getID() const; //return UIN
		int getPhone() const; //return Phone number
		bool operator<(const Record& rec); // overloaded '<' operator
};

ostream& operator<<(ostream& out, const Record& rec); //over loaded << operator
void search(vector<DoublyLinkedList<Record>>); //search function provides user interface


