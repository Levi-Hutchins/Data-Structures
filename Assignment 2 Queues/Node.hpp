/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description: hpp template implementation of the node header. Allows for nodes
of all types
*/

#include "Node.h"

// Templatise the Node constructor
template <typename T> 
Node<T>:: Node(){
    T data;
    next = NULL;
    prev = NULL;
}
// Templatised destructor 
template <typename T>
Node<T>:: ~Node(){
    prev = NULL;
    next = NULL;
}
// Templatised Specific constructor
template <typename T>
Node<T>:: Node(const T& dataIn){
    data = dataIn;
    next = NULL;
    prev = NULL;
}
// Setter functions that have been templatised 
template <typename T>
void Node<T>::setData(const T& dataIn){ data = dataIn; }
template <typename T>
void Node<T>::setNext(Node* nextPtr){ next = nextPtr; }
template <typename T>
void Node<T>::setPrev(Node* prevPtr){ prev = prevPtr; }

// Getter functions that have been templatised
template <typename T>
Node<T>* Node<T>:: getNext() const{ return next; }
template <typename T>
Node<T>* Node<T>:: getPrev() const{ return prev; }
template <typename T>
T Node<T>::getData() const{ return data; }