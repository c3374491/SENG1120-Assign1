// Node.h
// Course: SENG1120
// Coded by: c3374491 | Ethan Davey

#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include "Student.h"

using namespace std; 

class Node 
{
	public:
		typedef Student value_type;

		// constructors
		// specific constructor : i = data item
		Node(const value_type& i); // set data item with null next and prev pointers
		
		// destructor
		~Node();

		// setters
		void setPrev(Node* p); // sets prev pointer
		void setNext(Node* n); // sets next pointer
		void setData(const value_type& i); // sets data of the node

		// getters
		Node* getPrev() const; // gets prev pointer
		Node* getNext() const; // gets next pointer
		value_type getData() const; // gets data from node

	// private member variables
	private:
		// stores data
		value_type data; // data of a node

		// node pointers
		Node* prev; // pointer to prev (or default: NULL)
		Node* next; // pointer to next (or default: NULL)
};
#endif