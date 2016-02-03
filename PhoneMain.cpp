/*
Kyle Rowland
CSCE 221 - 505
PhoneMain.cpp
*/

#include "Record.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <fstream>
int main()
{
	vector<DoublyLinkedList<Record>> phoneBook; // create vector of doubly linked lists containing records
	phoneBook.resize(26);
	
	string line;
	ifstream myFile;
	ifstream phoneFile;
	ofstream outFile;
	phoneFile.open("PhoneBook.txt");
	 ///////////////////////////////////////// display phonebook entirely
	if (phoneFile.is_open())
	{
		while ( getline (phoneFile,line) )
		{
			cout << line << '\n';
		}
	}
	else cout << "Unable to open file"; 
	///////////////////////////////////////// read phonebook into vector
	myFile.open("PhoneBook.txt");
	if(myFile)
	{
		string l, f, temp; 
		int id, p;
		while(!myFile.eof())
		{
			getline(myFile, l);
			getline(myFile, f);
			getline(myFile, temp); stringstream ss(temp);
			ss >> id;
			getline(myFile, temp); stringstream s2(temp);
			s2 >> p;
			getline(myFile, temp);
			Record r(l,f,id,p);
			phoneBook[r.getLast().at(0)-65].inserFirst(r);
		}
	}
	else cout<< "Unable to open file"<<endl;
	
	search(phoneBook); // begin user interface
	
}
