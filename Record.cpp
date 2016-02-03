/*
Kyle Rowland
CSCE 221 - 505
Record.cpp
*/
#include "Record.h"
#include <iostream>

Record::Record(): last(""), first(""), uin(0), phone(0){}
Record::Record(string l, string f, int id, int p):last(l), first(f), uin(id), phone(p){}

string Record::getFirst() const //O(1)
{
	return first;
} 

string Record::getLast() const //O(1)
{
	return last;
}

int Record::getID() const //O(1)
{
	return uin;
}

int Record::getPhone() const //O(1)
{
	return phone;
}

string Record::setLast(string l)
{
	last = l;
}

string Record::setFirst(string f)
{
	first = f;
}

int Record::setID(int id)
{
	uin = id;
}

int Record::setPhone(int p)
{
	phone = p;
}

bool Record::operator<(const Record& rec) //comparison operator, O(1)
{
	if(this->getLast() <  rec.getLast())
		return true;
	else if(this->getLast() == rec.getLast())
		{
			if(this->getFirst() < rec.getFirst())
				return true;
			else if(this->getFirst() == rec.getFirst())
				{
					if(this->getID() < rec.getID())
						return true;
				}
		}
	else return false;
				
}

void search(vector<DoublyLinkedList<Record>> phoneBook) // implementation of user interface
{
	DoublyLinkedList<Record> short_list;
	string search_string;
	cout<<"Last Name: "; cin>>search_string;
	short_list = phoneBook[toupper(search_string.at(0))-65];
	while(!short_list.isEmpty() && short_list.getFirst()->getElem().getLast() < search_string)
	{
		short_list.removeFirst();
	}
	while(!short_list.isEmpty() && short_list.getAfterLast()->getPrev()->getElem().getLast() > search_string)
	{
		short_list.removeLast();
	}
	if(short_list.isEmpty())
		cout<<"\nEntry not found!"<<endl;
	else if(short_list.getFirst() == short_list.getAfterLast()->getPrev())
		cout<<'\n'<<short_list.getFirst()->getElem()<<'\n';
	else
	{
		cout<<"First Name: "; cin>>search_string;
		while(!short_list.isEmpty() && short_list.getFirst()->getElem().getLast() < search_string)
		{
			short_list.removeFirst();
		}	
		while(!short_list.isEmpty() && short_list.getAfterLast()->getPrev()->getElem().getLast() > search_string)
		{
			short_list.removeLast();
		}
		if(short_list.isEmpty())
			cout<<"\nEntry not found!"<<endl;
		else if(short_list.getFirst() == short_list.getAfterLast()->getPrev())
			cout<<'\n'<<short_list.getFirst()->getElem()<<'\n';
		else
		{
			long search_n;
			cout<<"UIN: "; cin>>search_n;
			while(!short_list.isEmpty() && short_list.getFirst()->getElem().getID() < search_n)
			{
				short_list.removeFirst();
			}	
			while(!short_list.isEmpty() && short_list.getAfterLast()->getPrev()->getElem().getID() > search_n)
			{
				short_list.removeLast();
			}
			if(short_list.isEmpty())
				cout<<"\nEntry not found!\n";
			else
				cout<<'\n'<<short_list.getFirst()->getElem()<<'\n';
		}
	}
}

ostream& operator<<(ostream& out, const Record& rec) // overloaded << operator, O(1)
{
	out<<rec.getLast()<<", "<<rec.getFirst()<<" UIN: "<<rec.getID()<<" Phone Number: "<<rec.getPhone()<<endl;
	return out;
}
