/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description: This is the implmentation of the templatised linkedlist
allows a linked list to be formed of any T type.
*/

#include "LinkedList.h"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList(){
    // Set all memeber variables to default values
    head = NULL; 
    tail = NULL;
    current  = NULL;
    listLength = 0; 
}
template <typename T>
LinkedList<T>::~LinkedList(){
     while(head != NULL)  // Loop till head is NULL
       {
            Node<T>* temp; // Create temp node that stores head
            temp = head; 
            head = head->getNext();
                    
            if (head != NULL) 
            {
                head->setPrev(NULL); // If head is not null set previous to null
            }           
            else 
            {
                tail = NULL; // Otherwise tail is set to null
            }
            // Delete temp node after every loop and decrease list length by one
            // set current back to head  
            delete temp;
            listLength--;
            current = head;
        }
}
template <typename T>
void LinkedList<T>::forward(){
    current = current->getNext();
}

template <typename T>
void LinkedList<T>::start(){
    current = head;
}
template <typename T>
void LinkedList<T>::addToHead(const T& dataToHead){
    Node<T>* newNode = new Node<T>(dataToHead); // Create new new node with object parameter and set previous to null

    newNode->setPrev(NULL);
    
    if(head!=NULL){ // If head is not currently null set the current heads previous to the new nodes
        head->setPrev(newNode);
    }
    
    newNode->setNext(head); // New nodes next becomes the old head and new node then becomes the head
    head = newNode;
    listLength++; // Increment list 
}

template <typename T>
void LinkedList<T>::addToCurrent(const T& dataToCurrent){
    Node<T>* newNode = new Node<T>(dataToCurrent); // Create new node with object parameter
    // Set all the appropriate pointers for the new nodes so it is linked to the surrounding nodoes
    newNode->setNext(current); 
    newNode->setPrev(current->getPrev()); 
    current->setPrev(newNode); 
    newNode->getPrev()->setNext(newNode);
    current = head;
    listLength++; // Increment list 
}
template <typename T>
void LinkedList<T>::addToTail(const T& dataToTail){
    // If the head is null the list is empty therefore head, current and tail are the same node
    if(head == NULL){
        Node<T>* newNode = new Node<T>(dataToTail);
        head = newNode;
        current = head;
        tail = newNode;
    
    }else{
        // If head is not null set existing tails next pointer to the new node
        Node<T>* newNode = new Node<T>(dataToTail);
        tail->setNext(newNode);
        newNode->setPrev(tail); // Set the new nodes previous pointer to the tail
        tail = newNode; // Set tail of the list to the new node
        newNode = NULL; // New node to null
    }
    listLength++; // Increment list 
}

template <typename T>
T LinkedList<T>::removeFromHead(){
    // Temporary node and set it to head
    Node<T>* temp;
    temp = head;
    
    T returnObj = head->getData(); // Storing the heads object to return later

    
    head = head->getNext(); // New head is now the node after the current head
    
    if(head != NULL) head->setPrev(NULL);// If the list is not empty set the heads previous pointer to null                  
    else tail = NULL;                   // otherwise tail to null
    
    // Delete temp, decrease list length and return the old head object
    delete temp;
    listLength--;
    current = head;
    return returnObj; // Return the object we deleted
}
template <typename T>
T LinkedList<T>::removeFromTail(){
    Node<T>* temp; // Temp node set it equal to the tail   
   
    temp = tail;
    T returnObj = tail->getData();

      // Storing the tail nodes data to return later
    tail = temp->getPrev(); 
                    
    if (tail != NULL) tail -> setNext(NULL); // If tail is not null then set tails next to null      
    else head = NULL;                       // Otherwise head is now null
    
    // Delete temp, decrease list length and current is now null    
    delete temp;
    listLength --;
    current = NULL;
    
    return returnObj; // Return the object we deleted

}
template <typename T>
T LinkedList<T>::removeFromCurrent(){
    Node<T>* temp; // Temp node
    T returnObj = current->getData(); // Store the current nodes data to return later
    temp = current->getPrev(); // temp now is currents previous pointer
    temp->setNext(current->getNext()); // Set temps next pointer to now currents next
    temp = current->getNext(); // Temp is now currents next 
    temp->setPrev(current->getPrev()); // Set temps previous pointer to currents previous

    // Delete temp, decrease list length and current is now temp    
    delete current;
    current = temp;
    listLength--;
    return returnObj; // Return the object that was removed

}

template <typename T>
T LinkedList<T>::getFromCurrent() const{
    return current->getData();
}
template <typename T>
T LinkedList<T>::getFromHead() const{
    return head->getData(); 
}
template <typename T>
T LinkedList<T>::getFromTail() const{
    return tail->getData();

}
template <typename T>
void LinkedList<T>::end(){
    current = tail;
}

template <typename T>
int LinkedList<T>::getSize() const{
    return listLength;

}