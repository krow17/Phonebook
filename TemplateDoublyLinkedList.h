/*
Kyle Rowland
CSCE 221 - 505
TemplateDoublyLinkedList.h
*/

#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
template <class T> class DoublyLinkedList; // class declaration

// list node
template <class T> class DListNode 
{
	private: T obj;
	  DListNode *prev, *next;
	  friend class DoublyLinkedList<T>;
	public:
	  DListNode(T e=T(), DListNode *p = NULL, DListNode *n = NULL)
		: obj(e), prev(p), next(n) {}
	  T getElem() const { return obj; }
	  DListNode * getNext() const { return next; }
	  DListNode * getPrev() const { return prev; }
};

// doubly linked list
template <class T> class DoublyLinkedList 
{
	protected: 
		DListNode<T> header, trailer;
	public:
		DoublyLinkedList<T>() : header(), trailer() // constructor
		{ 
			header.next = &trailer; trailer.prev = &header; 
		}
		DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
		~DoublyLinkedList(); // destructor
		DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
	  // return the pointer to the first node
		DListNode<T> *getFirst() const 
		{
			return header.next; 
		} 
	  // return the pointer to the trailer
		const DListNode<T> *getAfterLast() const 
		{
			return &trailer; 
		}
	  // return if the list is empty
		bool isEmpty() const 
		{ 
			return header.next == &trailer; 
		}
		T first() const; // return the first object
		T last() const; // return the last object
		void insertFirst(T newobj); // insert to the first of the list
		T removeFirst(); // remove the first node
		void insertLast(T newobj); // insert to the last of the list
		T removeLast(); // remove the last node
		int DoublyLinkedListLength(DoublyLinkedList<T>& dll);
		void insertOrderly(T obj);
		
};
// output operator
template <class T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll); 

struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
template <class T> DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll) //O(logn)
{
	// Initialize the list
	header.next = &trailer; trailer.prev = &header;
  
	// Copy from dll
	DListNode<T> *iter = dll.getFirst();
  
	while(iter != dll.getAfterLast()) // O(logn)
	{
		this->insertLast(iter->getElem());
		iter = iter->getNext();
	}	
	iter = NULL;
}
// assignment operator
template<class T> DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll) //O(logn)
{
	DListNode<T> *iter = dll.getFirst();
  
	while(iter != dll.getAfterLast())//O(logn)
	{	
		this->insertLast(iter->getElem());
		iter = iter->getNext();
	}	
	iter = NULL;
  
  // Copy from dll
}
// insert the object to the first of the linked list
template<class T> void DoublyLinkedList<T>::insertFirst(T newobj) //O(1)
{ 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}
// insert the object to the last of the linked list
template <class T> void DoublyLinkedList<T>::insertLast(T newobj) //O(1)
{
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
// remove the first object of the list
template<class T> T DoublyLinkedList<T>::removeFirst() //O(1)
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}
// remove the last object of the list
template <class T> T DoublyLinkedList<T>::removeLast() //O(1)
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}
// destructor
template<class T> DoublyLinkedList<T>::~DoublyLinkedList()
{
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
// return the first object
template<class T> T DoublyLinkedList<T>::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}
// return the last object
template<class T> T DoublyLinkedList<T>::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}

template <class T> void DoublyLinkedList<T>::insertOrderly(T obj)
{
	DListNode<T>* pos = getFirst(); //first object of the list
	while(pos != &trailer)
	{
		if(obj<pos->getElem())
		{
			DListNode<T>* newNode= new DListNode<T>(obj, pos->prev, pos);
			pos->prev->next = newNode;
			pos->prev = newNode;
			return;
		}
		pos = pos->next;
	}
	insertLast(obj);
}
// return the list length
template <class T> int DoublyLinkedList<T>::DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
  DListNode<T> *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}
// output operator
template <class T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {

  DListNode<T> *iter = dll.getFirst();
  
	while(iter != dll.getAfterLast())
	{
		out << iter -> getElem()<<" ";
		iter = iter -> getNext();
	}
  return out;
}
