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
    length = 0; // set length counter to 0
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
    Node* newNode = new Node(d); // creates a new node
    newNode->setPrev(NULL); // sets prev pointer to NULL
    newNode->setNext(NULL); // sets next pointer to NULL
    tail = newNode; // sets tail of the list to the new node
    head = newNode; // sets head of the list to the new node
    current = head; // sets current of the list to the head of the list
    length++; // increase the length count of the list by 1
}

// precondition: none
// postcondition: a new node storing the supplied item is created and linked in to be the new head of the list
void LinkedList::addToHead(const Node::value_type& d)
{
    // for dealing with existing lists
    if (head != NULL) // checks if the list is not empty, if this is true the indented code will execute
    {
        Node* newNode = new Node(d); // creates new node
        head->setPrev(newNode); // sets the previous pointer of the current head to the new node
        newNode->setNext(head); // sets the next pointer of the new node to the current head
        newNode->setPrev(NULL); // sets the previous pointer of the new node to NULL
        head = newNode; // sets the head pointer to the new node
        current = head; // sets the current pointer to head
        length++; // increase the length count of the list by 1
    }
    // for dealing with empty lists
    else{addToEmptyList(d);} // moves to be handled by the addToEmptyList method
}

// precondition: the current pointer is on the node immediately prior to where the node is to be inserted
// postcondition: a new node storing the supplied item is created and linked in to be placed behind the current pointer node
void LinkedList::addToCurrent(const Node::value_type& d)
{
    // for dealing with existing lists
    if (current != NULL) // checks if the list is not empty, if this is true the indented code will execute
    {
        Node* newNode = new Node(d); // creates new node
        newNode->setNext(current->getNext()); // sets the next pointer of the new node to the next node from the current node
        current->setNext(newNode); // sets the next pointer of the current node to the new node
        newNode->setPrev(current); // sets the prev pointer of the new node to the current node
        newNode->getNext()->setPrev(newNode); // sets the prev node of the node directly next to the current node to new node
        current = head; // sets current pointer to head
        length++; // increase the length count of the list by 1
    }
    // for dealing with empty lists
    else{addToEmptyList(d);} // moves to be handled by the addToEmptyList method
}

// precondition: none
// postcondition: a new node storing the supplied item is created and linked in to be the new tail of the list
void LinkedList::addToTail(const Node::value_type& d)
{
    // for dealing with existing lists
    if (tail != NULL)
    {
        Node* newNode = new Node(d); // creates new node
        tail->setNext(newNode); // sets next of tail to the new node
        newNode->setPrev(tail); // sets prev of new node to tail
        newNode->setNext(NULL); // sets next of new node to NULL
        tail = newNode; // sets tail to the new node
        current = head; // sets current pointer to head
        length++; // increase the length count of the list by 1
    }
    // for dealing with empty lists
    else{addToEmptyList(d);}
}

// precondition: none
// postcondition: the current pointer of the list is moved to the head of the list
void LinkedList::start(){current = head;}

// precondition: none
// postcondition: the current pointer of the list is moved to the tail of the list
void LinkedList::end(){current = tail;}

// precondition: none
// postcondition: the current pointer of the list is moved to the next node of the list
void LinkedList::forward(){current = current->getNext();}

// precondition: none
// postcondition: the current pointer of the list is moved to the previous node of the list
void LinkedList::back(){current = current->getPrev();}


// accessor methods (getters)

// precondition: none
// postcondition: the data of the current poitner is returned
Node::value_type LinkedList::getCurrent() const{
    return current->getData();
}

// precondition: the list is not empty
// postcondition: the lowest score of the list is returned
const int LinkedList::getLowestScore()
{
    int lowestScore = head->getData().get_score(); // sets lowestScore to the score from the head of the list
    for(start(); current!=NULL; forward()) // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {   
        // if the score of the current node is less then lowestScore, record it as lowestScore
        if(getCurrent().get_score()<lowestScore) 
        {
            lowestScore = getCurrent().get_score();
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
    for(start(); current!=NULL; forward())  // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {   
        total += getCurrent().get_score(); // add the score of the current node to total
        counter++; // increase counter total by 1
    }
    averageScore = (total/counter); // caluclate the average of the list using the count of the list and the total score of the entire list
    return averageScore;
}

// precondition: the list is not empty
// postcondition: the highest score of the list is returned
const int LinkedList::getHighestScore()
{
    int highestScore = head->getData().get_score();// sets highestScore to the score from the head of the list
    for(start(); current!=NULL; forward()) // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {   
        // if the score of the current node is greater then highestScore, record it as highestScore
        if(getCurrent().get_score()>highestScore)
        {
            highestScore = getCurrent().get_score();
        }
    }
    return highestScore;
}

// precondition: tnone
// postcondition: the length of the list is returned
const int LinkedList::getLength(){return length;}

// remove methods

// precondition: the list is not empty
// postcondition: the first node of the list is removed
void LinkedList::removeFromHead()
{
    Node* temp = current->getNext(); // set temp node pointer to next of current
    temp->setPrev(NULL); // set prev of temp node to NULL
    delete current; // remove the current node
    head = temp; // set head to the temp node
    start(); // set current to head
    length--; // decrease length counter of the list by 1
}

// precondition: the list is not empty
// postcondition: the current node of the list is removed
void LinkedList::removeFromCurrent()
{
    Node* temp = current->getNext(); // set temp node pointer to next of current
    Node* temp2 = current->getPrev(); // set temp2 node pointer to prev of current
    temp->setPrev(temp2); // set prev of temp node to temp2
    temp2->setNext(temp); // set next of temp2 node to temp
    delete current; // remove the current node
    start(); // set current to head
    length--; // decrease length counter of the list by 1
}

// precondition: the list is not empty
// postcondition: the last node of the list is removed
void LinkedList::removeFromTail()
{
    Node* temp = current->getPrev(); // set temp node pointer to prev of current
    temp->setNext(NULL); // set next of temp node to NULL
    delete current; // remove the current node
    tail = temp; // set tail to the temp node
    start(); // set current to head
    length--; // decrease length counter of the list by 1
}

// precondition: the list is not empty
// postcondition: the node is removed from its corresponding position
void LinkedList::remove(const string s)
{
    for(start(); current!=NULL; forward()) // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {
        // if the name of the node is the same as the string inputted to the method execute the indented code
        if(s==getCurrent().get_name()) 
        {
            // if the prev and next node are NULL the node is the only item in the list and it can be deleted
            if (current->getPrev()==NULL && current->getNext()==NULL)
            {
                delete current; // remove current node
                length--; // decrease length counter by 1
            }
            else if (current->getPrev()==NULL){removeFromHead();} // if prev == NULL then the node must be on the head, therefore call the removeFromHead method
            else if (current->getNext()==NULL){removeFromTail();} // if next == NULL then the node must be on the tail, therefore call the removeFromTail method
            else{removeFromCurrent();} // if no other argument is matched then the node must be in the middle of the list with surrounding nodes, therefore call the removeFromCurrent method
        }
    }
}

// precondition: the list is not empty
// postcondition: the list is cleared of all nodes
void LinkedList::clear()
{
    for(start(); current!=NULL; forward()) // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {
        removeFromHead(); // call removeFromHead method
    }
}

// other methods

// precondition: none
// postcondition: the number of items with data matching that string is returned 
const int LinkedList::count(const string s)
{
    int counter = 0; // set counter to 0
    for(start(); current!=NULL; forward()) // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {   
        // if the name of the current node matches the string inputted to the method increase the counter by 1
        if(s==getCurrent().get_name()){counter++;}
    }
    return counter;
}

// precondition: the list is not empty
// postcondition: the statistics (lowest score, average score, highest score) for the list are returned
void LinkedList::printStatistics()
{
    // call relevant methods and output in this specific layout
    cout << "(" << getLowestScore() << " / " << getAverageScore() << " / " << getHighestScore() << ")" << endl;
}


// overloaded operators

// precondition: none
// postcondition: returns the data of each node from the linked list
ostream& operator << (ostream& out, LinkedList& list)
{
    list.start(); // set list current to head
    // arguments of the for list (create int "i" and set its value to 0 / complete until "i" equals or is greater then the value returned by getLength() / increase "i" by 1)
    for(int i=0;i<list.getLength();i++) 
    {
        out << list.getCurrent(); // output the data of the current node
        list.forward(); // move to the next node in the list
    }
    list.start();
    return out;
}

// precondition: none
// postcondition: returns a linked list with all of the nodes from the two inputted linked lists
LinkedList& operator += (LinkedList& list, LinkedList& listTwo)
{
    list.start(); // set list current to head
    listTwo.start(); // set listTwo current to head
    // arguments of the for list (create int "i" and set its value to 0 / complete until "i" equals or is greater then the value returned by getLength() / increase "i" by 1)
    for(int i=0; i<listTwo.getLength(); i++)
    {
        list.addToTail(listTwo.getCurrent()); // add the node from listTwo to the tail of List
        listTwo.forward(); // move to the next node in the list
    }
    listTwo.start();
    list.start();
    return list;
}