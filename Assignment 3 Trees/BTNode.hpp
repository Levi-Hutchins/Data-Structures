/* Author: Levi Hutchins
   Course: SENG 1120
   Description: 
   This file is the implementation of the BTNode
   Contains all the appropriate getters and setters
   for the member variables as well as a constructors and 
   destructor.
   The file has also been templatised to allow for creation 
   of BTNodes of any data type.
*/
#include "BTNode.h" // Include Node file
template <typename E>
// Default Constructor
BTNode<E>::BTNode(){
    E data;
    parent = NULL;
    right = NULL;
    left = NULL;
    
}
// Specific Constructor
template <typename E>
BTNode<E>::BTNode(E& dataIn){
    data = dataIn;
    parent = NULL;
    right = NULL;
    left = NULL;
    
}
// Destructor
template <typename E>
BTNode<E>::~BTNode(){
  parent = NULL;
  left = NULL;
  right =  NULL;

}
// Setter for BTNode data
template <typename E>
void BTNode<E>::setData(const E& newData){ data = newData;}

// Setter for BTNode parent
template <typename E>
void BTNode<E>::setParent(BTNode<E>* newParent){ parent = newParent;}

// Setter for BTNode left
template <typename E>
void BTNode<E>::setLeft(BTNode<E>* newLeft){ left = newLeft;}

// Setter for BTNode right
template <typename E>
void BTNode<E>::setRight(BTNode<E>* newRight){ right = newRight;}

// Getter for BTNode data
template <typename E>
E BTNode<E>:: getData(){ return data;}

// Getter for BTNode parent
template <typename E>
BTNode<E>* BTNode<E>::getParent(){ return parent;}

// Getter for BTNode left
template <typename E>
BTNode<E>* BTNode<E>::getLeft(){ return left;}

// Getter for BTNode right
template <typename E>
BTNode<E>* BTNode<E>::getRight(){ return right;}