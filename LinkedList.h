// LinkedList.h
// Course: SENG1120
// Coded by: c3374491 | Ethan Davey

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include "Node.h"

using namespace std; 

class LinkedList 
{
	public:
		typedef Node::value_type value_type;
		
		// Constructors
		LinkedList();

		// Destructor
		~LinkedList();

        // mutator methods (setters)
        void setHead(Node* newHead);
        void setCurrent(Node* newCurrent);
        void setTail(Node* newTail);
        void addToEmptyList(const value_type& d);
        void addToHead(const value_type& d);
        void addToCurrent(const value_type& d);
        void addToTail(const value_type& d);

        // accessor methods (getters)
        Node* getHead() const;
        Node* getCurrent() const;
        Node* getTail() const;
        const int getLowestScore();
        const double getAverageScore();
        const int getHighestScore();

        // remove methods
        void removeFromHead();
        void removeFromCurrent();
        void removeFromTail();
        void remove(const string s);
        void clear();

        // other methods
        const int count(const string s);
        void printStatistics();

    // private member variables
    private:
        // node pointers
		Node* head;
		Node* tail;
		Node* current;
};

ostream& operator << (ostream& out, LinkedList& list);

LinkedList& operator += (LinkedList& list, LinkedList& listTwo);

#endif