/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
*/


#ifndef LQUEUE
#define LQUEUE
#include "LinkedList.h"
#include <iostream>
using namespace std;
template <typename T>
class LQueue{
    public:
        // Precondition: None
        // Postcondition: A LQueue is created that initialises a LinkedList
        LQueue();

        // Precondition: None
        // Postcondition: Set size of LQueue to 0
        ~LQueue();

        // Precondition: None
        // Postcondition: A new item is added to the tail of the Queue
        void enqueue(const T& inData);
        
        // Precondition: The Queue is not empty
        // Postcondition: The item at the front of the Queue is removed
        T dequeue();

        // Precondition: The Queue is not empty
        // Postcondition: Item at the front (head) of the Queue is returned
        T front() const;

        // Precondition: The Queue exists 
        // Postcondition: Return if the Queue is empty or not
        bool isEmpty() const; 

        // Precondition: The Queue exists
        // Postcondition: Returns the size of the Queue
        int size() const; 

    // Private member variables
    private:
        LinkedList<T> data;
        int used;





};
// Overloading function to print out a Queue
template <typename T>
ostream& operator<<(ostream& os, LQueue<T>& temp); 

// Incldue the implementation file
#include "LQueue.hpp"
#endif