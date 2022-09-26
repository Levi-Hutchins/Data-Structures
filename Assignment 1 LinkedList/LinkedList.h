/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description:  Class definiton for the linked list. Contains all the required functions
with a couple extras
*/
#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

class LinkedList{

    public:
        typedef Node::data_type dataType; //  chaining Typedef statement

        // Precondition: None
        // Postcondition: A linked list is created where tail, current and head are null
        LinkedList();

        // Precondition: None
        // Postcondition: The list is empty and both the head and tail are now null
        ~LinkedList();

        // Precondition: None
        // Postcondition: Moves the current to the next node
        void forward();

        // Precondition: None
        // Postcondition: The current is set to the head node
        void start();

        //Precondition: A Node to be added next to the current node
        // Postcondition: A Node is added next to the current node and linked to surrounding nodes
        void setCurrent(Node* temp);

        //Precondition: A Node to be added next to the head node
        // Postcondition: A Node is added infront of the head node and linked to the previous node
        void setHead(Node* temp);

        // Precondition:  None
        // Postcondition: A new node with the designated object is created and 
        //                linked in to be the new head of the list  
        void addToHead(const dataType& dataToHead);

        // Precondition:  The current node points to the node just after the 
        //                desired insertion point 
        // Postcondition: A new node containing the object is inserted after the node 
        //                pointed to by the current. Current then points to new node 
        void addToCurrent(const dataType& dataToCurrent);

        // Precondition:  The exisiting tail pointer points to the new node
        //                and the new node previous points to the old tail
        // Postcondition: A new node is containing the object is created and inserted
        //                after the old tail and new nodes previous points to the old tail
        //                while the old tails next points to the new node
        void addToTail(const dataType& dataToTail);

        // Precondition: A node within the linkedlist contains the name to remove
        // Postcondition: A node containing the target name is removed from the list and the node remove
        //                is returned
        dataType remove(const string nameToRemove);

        // Precondition: None
        // Postcondition: The data stored in the current head node is returned
        dataType getFromHead() const ;

        // Precondition: None
        // Postcondition: The data stored in the current node is returned
        dataType getFromCurrent() const ; 

        // Precondition: None
        // Postcondition: The data stored in the current tail node is returned
        dataType getFromTail() const ; 

        // Precondition:  The list is not empty
        // Postcondition: The node at the head of the list is removed and returned to the heap
        dataType removeFromHead();

        // Precondition: The list is not empty
        // Postcondition: The node at the tail of the list is removed and return to the heap
        dataType removeFromTail();

        // Precondition:  The current node points to the node to be removed
        // Postcondition: The node preivously poointed to by the current is now removed
        //                current points to the head of the list
        dataType removeFromCurrent();
        
        // Precondition: None
        // Postcondition: The end of the list
        bool end() const;

        // Precondition: None
        // Postcondtion: The average of all the scores in the list
        const double calcAverage();

        // Precondition: None
        // Postcondition: Currents data contains name to count, increment counter
        int count(const string nameToCount) const;

        // Precondition: None
        // Postcondition: a count of nodes within the list is returned
        int getSize() const;


        // Precondition:  None
        // Postcondition: Adds two lists together 
        LinkedList& operator+= (LinkedList& tempList);

    // Memeber variables
    private:
        Node* head;
        Node* tail;
        Node* current;
        int listLength;
};
// Overloading function to print linked list
ostream& operator<<(ostream& os, LinkedList& temp); 

#endif