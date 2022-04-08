// Node.cpp
/******************************/
// Author: c3374491 | Ethan Davey
// Course: SENG1120
// File Description: This file outlines the creation and management for the nodes of the linked list.


#include <cstdlib>
#include "Node.h"

// constructors
// specific constructor : i = data item
Node::Node(const value_type& d) // set data item with data provided, set next and prev pointers to NULL
{
	prev = NULL; // set prev pointer to NULL
	next = NULL; // set next pointer to NULL
	data = d;  // set data of node with data item provided
}

// destructors
Node::~Node(){}

// mutator methods (setters)
void Node::setPrev(Node *p){prev = p;} // sets prev pointer to p
void Node::setNext(Node *n){next = n;} // sets next pointer to n
void Node::setData(const value_type &d){data = d;} // sets data to d

// accessor methods (getters)
Node* Node::getPrev() const{return prev;} // returns prev pointer
Node* Node::getNext() const{return next;} // returns next pointer
Node::value_type Node::getData() const{return data;} // returns data of the node