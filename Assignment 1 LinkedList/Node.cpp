/*
Author: Levi Hutchins
Student Number: C3386116\
Course: SENG1120
Description: This node class defines the foundation for a linked list. Each node stores
an object which in this case is a Student object (data), a pointer to the next node (next)
and a pointer to the previous node (prev). 
*/
#include "Node.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

Node::Node(){
    data = data_type(); // Create data_type object
    next = NULL; // next pointer to null
    prev = NULL; // previous pointer to null
    
}
Node::~Node(){
    prev = NULL; // previous pointer to null
    next = NULL; // next pointer to null
}
Node::Node(const data_type& inData){
    data = inData; // Create data_type object with parameter object
    next = NULL; // next pointer to null
    prev = NULL; // previous pointer to null
}

// Setter functions
void Node::setNext(Node* nextPtr){ next = nextPtr;}
void Node::setPrev(Node* prevPtr){ prev = prevPtr;}
void Node::setData(data_type& inData){ data = inData;}

// Getter functions
Node* Node::getNext()const { return next;}
Node* Node::getPrev() const { return prev; }
Node:: data_type Node:: getData() const { return data;}


