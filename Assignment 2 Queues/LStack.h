/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
*/

#ifndef LSTACK // Macroguard
#define LSTACK
#include "LinkedList.h"
template <typename T>
class LStack{
    public:
        // Precondition: None
        // Postcondition: A LStack is created that initalises a Linkedlist
        LStack(); 

        // Precondition: None
        // Postcondition: Set size of LStack to 0
        ~LStack();

        // Precondition: None
        // Postcondition: A new item is added to the head of the linkedlist
        void push(const T& item);

        // Precondition: None
        // Postcondition: Item from the head of the stack is removed
        T pop();

        // Precondition: The stack exists
        // Postcondition: Returns whether the stack is empty or not
        bool isEmpty() const;
        
        // Precondition: An item has been added to the head of the stack
        // Postcondition: Returns item currently at the head
        T peek() const;

    // Private memeber variables 
    private:
        LinkedList<T> data;
        int used;

};
// Overloading function to print out a stack
template <typename T>
ostream& operator<<(ostream& os, LStack<T>& myS); 

// Include the implementation file
#include "LStack.hpp"
#endif