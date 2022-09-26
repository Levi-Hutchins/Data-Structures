/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description: Class definition for the node class containing all the necessary functions
*/
#ifndef NODE
#define NODE
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
class Node{
    public:
        typedef Student data_type; // Type def student to data_type
        Node(); // Default constructor
        ~Node(); // Deconstructor
        Node(const data_type& inData); // Specific constructor

        // Precondition: A Node or data to be added
        // Postcondition: Setter fucntions
        void setNext(Node* nextPtr);
        void setPrev(Node* prev);
        void setData(data_type& dataIn);

        // Precondition: None
        // Postcondition: Getter functions
        Node* getNext() const;
        Node* getPrev() const;
        data_type getData() const;

    // Member variables
    private:
        data_type data;
        Node* next;
        Node* prev;
};

#endif