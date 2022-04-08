// LinkedList.cpp
/******************************/
// Author: c3374491 | Ethan Davey
// Course: SENG1120
// File Description: This file outlines the creation and management of the linked list.

#include "LinkedList.h"
#include "Node.h"
#include <cstdlib>

// constructors
LinkedList::LinkedList(){ // creates an empty linked list. sets pointes to NULL
    head = NULL; // set head pointer to NULL
    tail = NULL; // set tail pointer to NULL
    current = NULL; // set current pointer to NULL
}

// destructors
LinkedList::~LinkedList(){clear();} // linked list destructor calls node desctuctors to not leave a trail of nodes not in a list

// mutator methods (setters)

// precondition: none
// postcondition: the head of the linked list is changed to newHead
void LinkedList::setHead(Node* newHead){
    head = newHead;
}

// precondition: none
// postcondition: the current of the linked list is changed to newCurrent
void LinkedList::setCurrent(Node* newCurrent){
    current = newCurrent;
}

// precondition: none
// postcondition: the tail of the linked list is changed to newTail
void LinkedList::setTail(Node* newTail){
    tail = newTail;
}

// precondition: none
// postcondition: a new node storing the supplied item is created and linked in to be the new head, tail, and current of the list
void LinkedList::addToEmptyList(const Node::value_type& d)
{
    Node* newNode = new Node(d);
    newNode->setPrev(NULL);
    newNode->setNext(NULL);
    tail = newNode;
    head = newNode;
    current = head;
}

// precondition: none
// postcondition: a new node storing the supplied item is created and linked in to be the new head of the list
void LinkedList::addToHead(const Node::value_type& d)
{
    // for dealing with existing lists
    if (head != NULL)
    {
        Node* newNode = new Node(d);
        head->setPrev(newNode);
        newNode->setNext(head);
        newNode->setPrev(NULL);
        head = newNode;
        current = head;
    }
    // for dealing with empty lists
    else{addToEmptyList(d);}
}

// precondition: the current pointer is on the node immediately prior to where the node is to be inserted
// postcondition: a new node storing the supplied item is created and linked in to be placed behind the current pointer node
void LinkedList::addToCurrent(const Node::value_type& d)
{
    // for dealing with existing lists
    if (current != NULL)
    {
        Node* newNode = new Node(d);
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        newNode->setPrev(current);
        newNode->getNext()->setPrev(newNode);
        current = head;
    }
    // for dealing with empty lists
    else{addToEmptyList(d);}
}

// precondition: none
// postcondition: a new node storing the supplied item is created and linked in to be the new tail of the list
void LinkedList::addToTail(const Node::value_type& d)
{
    // for dealing with existing lists
    if (tail != NULL)
    {
        Node* newNode = new Node(d);
        tail->setNext(newNode);
        newNode->setPrev(tail);
        newNode->setNext(NULL);
        tail = newNode;
        current = head;
    }
    // for dealing with empty lists
    else{addToEmptyList(d);}
}

// accessor methods (getters)

// precondition: none
// postcondition: the head of the list is returned
Node* LinkedList::getHead() const{
    return head;
}

// precondition: none
// postcondition: the current pointer of the list is returned
Node* LinkedList::getCurrent() const{
    return current;
}

// precondition: none
// postcondition: the tail of the list is returned
Node* LinkedList::getTail() const{
    return tail;
}

// precondition: the list is not empty
// postcondition: the lowest score of the list is returned
const int LinkedList::getLowestScore()
{
    int lowestScore = head->getData().get_score();
    for(current=head; current!=NULL; setCurrent(getCurrent()->getNext()))
    {   
        if(current->getData().get_score()<lowestScore)
        {
            lowestScore = current->getData().get_score();
        }
    }
    return lowestScore;
}

// precondition: the list is not empty
// postcondition: the average score of the list is returned
const double LinkedList::getAverageScore()
{
    double averageScore;
    double total = 0;
    int counter = 0;
    for(current=head; current!=NULL; setCurrent(getCurrent()->getNext()))
    {   
        total += current->getData().get_score();
        counter++;
    }
    averageScore = (total/counter);
    return averageScore;
}

// precondition: the list is not empty
// postcondition: the highest score of the list is returned
const int LinkedList::getHighestScore()
{
    int highestScore = head->getData().get_score();
    for(current=head; current!=NULL; setCurrent(getCurrent()->getNext()))
    {   
        if(current->getData().get_score()>highestScore)
        {
            highestScore = current->getData().get_score();
        }
    }
    return highestScore;
}

// remove methods

// precondition: the list is not empty
// postcondition: the first node of the list is removed
void LinkedList::removeFromHead()
{
    Node* temp;
    temp = current->getNext();
    temp->setPrev(NULL);
    current->~Node();
    head = temp;
    setCurrent(head);
}

// precondition: the list is not empty
// postcondition: the current node of the list is removed
void LinkedList::removeFromCurrent()
{
    Node* temp = current->getNext();
    Node* temp2 = current->getPrev();
    temp->setPrev(temp2);
    temp2->setNext(temp);
    current->~Node();
    setCurrent(head);
}

// precondition: the list is not empty
// postcondition: the last node of the list is removed
void LinkedList::removeFromTail()
{
    Node* temp;
    temp = current->getPrev();
    temp->setNext(NULL);
    current->~Node();
    tail = temp;
    setCurrent(head);
}

// precondition: the list is not empty
// postcondition: the node is removed from its corresponding position
void LinkedList::remove(const string s)
{
    for(current=head; current!=NULL; setCurrent(getCurrent()->getNext()))
    {
        if(s==current->getData().get_name())
        {
            if (current->getPrev()==NULL && current->getNext()==NULL)
            {
                current->~Node();
            }
            else if (current->getPrev()==NULL){removeFromHead();}
            else if (current->getNext()==NULL){removeFromTail();}
            else{removeFromCurrent();}
        }
    }
}

// precondition: the list is not empty
// postcondition: the list is cleared of all nodes
void LinkedList::clear()
{
    for(current=head; current!=NULL; setCurrent(getCurrent()->getNext()))
    {
        removeFromHead();
    }
}

// other methods

// precondition: none
// postcondition: the number of items with data matching that string is returned 
const int LinkedList::count(const string s)
{
    int counter = 0;
    for(current=head; current!=NULL; setCurrent(getCurrent()->getNext()))
    {   
        if(s==current->getData().get_name()){counter++;}
    }
    return counter;
}

// precondition: the list is not empty
// postcondition: the statistics (lowest score, average score, highest score) for the list are returned
void LinkedList::printStatistics()
{
    cout << "(" << getLowestScore() << "/" << getAverageScore() << "/" << getHighestScore() << ")" << endl;
}


// overloaded operators

// precondition: none
// postcondition: returns the data of each node from the linked list
ostream& operator << (ostream& out, LinkedList& list)
{
    for(list.setCurrent(list.getHead()); list.getCurrent() != NULL; list.setCurrent(list.getCurrent()->getNext()))
    {
        out << list.getCurrent()->getData();
    }
    list.setCurrent(list.getHead());
    return out;
}

// precondition: none
// postcondition: returns a linked list with all of the nodes from the two inputted linked lists
LinkedList& operator += (LinkedList& list, LinkedList& listTwo)
{
    for(listTwo.setCurrent(listTwo.getHead()); listTwo.getCurrent() != NULL; listTwo.setCurrent(listTwo.getCurrent()->getNext()))
    {
        list.addToTail(listTwo.getCurrent()->getData());
    }
    listTwo.setCurrent(listTwo.getHead());
    list.setCurrent(list.getHead());
    return list;
}