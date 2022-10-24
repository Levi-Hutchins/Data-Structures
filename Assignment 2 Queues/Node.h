/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description: Class definition of node that allows data of T tyoe
*/
#ifndef NODE // Macroguard
#define NODE
#include <iostream>
#include <string>
using namespace std;

template <typename T> // Templatising the node class 
class Node{
    public:
        Node(); // Default constructor 
        ~Node(); // Deconstructor
        Node(const T& inData); // Specific constructor

        // Precondition: A Node or data to be added
        // Postcondition: Setter fucntions
        void setNext(Node* nextPtr);
        void setPrev(Node* prev);
        void setData(const T& dataIn);

        // Precondition: None
        // Postcondition: Getter functions
        Node* getNext() const;
        Node* getPrev() const;
        T getData() const;

    // Member variables. data is a of T type
    private:
        T data;
        Node* next;
        Node* prev;




};
// Inlcude the implementation file
#include "Node.hpp"

#endif // End of macroguard