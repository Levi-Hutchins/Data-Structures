/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
*/

#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList{

    public:
        // Precondition: None
        // Postcondition: A linked list is created where tail, current and head are null
        LinkedList();

        // Precondition: None
        // Postcondition: The list is empty and both the head and tail are now null
        ~LinkedList();

        // Precondition:  None
        // Postcondition: A new node with the designated object is created and 
        //                linked in to be the new head of the list  
        void addToHead(const T& dataToHead);

        // Precondition:  The current node points to the node just after the 
        //                desired insertion point 
        // Postcondition: A new node containing the object is inserted after the node 
        //                pointed to by the current. Current then points to new node 
        void addToCurrent(const T& dataToCurrent);

        // Precondition:  The exisiting tail pointer points to the new node
        //                and the new node previous points to the old tail
        // Postcondition: A new node is containing the object is created and inserted
        //                after the old tail and new nodes previous points to the old tail
        //                while the old tails next points to the new node
        void addToTail(const T& dataToTail);
        // Precondition: None
        // Postcondition: The data stored in the current head node is returned
        T getFromHead() const ;

        // Precondition: None
        // Postcondition: The data stored in the current node is returned
        T getFromCurrent() const ; 

        // Precondition: None
        // Postcondition: The data stored in the current tail node is returned
        T getFromTail() const ; 

        // Precondition:  The list is not empty
        // Postcondition: The node at the head of the list is removed and returned to the heap
        T removeFromHead();

        // Precondition: The list is not empty
        // Postcondition: The node at the tail of the list is removed and return to the heap
        T removeFromTail();
        // Precondition:  The current node points to the node to be removed
        // Postcondition: The node preivously poointed to by the current is now removed
        //                current points to the head of the list
        T removeFromCurrent();


        // Current manipulators
        void start();
        void forward();
        void back();
        void end();
        
        // Precondition: None
        // Postcondition: Returns size of the linked list
        int getSize() const;
        // Memeber variables
    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* current;
        int listLength;
};
// Overloading function to print linked list
#include "LinkedList.hpp"
#endif
