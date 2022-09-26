/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description:  This program has the ability to remove specific names from a linked list
calculate the average of scores, concatenate lists, count the number of students with a specific name
and so on. Works in conjunction with the LinkedListDemo.cpp file.
*/

#include "Node.h"
#include "LinkedList.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

// Default LinkedList constructor 
LinkedList::LinkedList(){
    // Set all memeber variables to default values
    head = NULL; 
    tail = NULL;
    current  = NULL;
    listLength = 0;   
}
// Deconstructor for LinkedList
LinkedList::~LinkedList()
    {
       while(head != NULL)  // Loop till head is NULL
       {
            Node* temp; // Create temp node that stores head
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
// Node manipulator function to set current to desired node
void LinkedList::setCurrent(Node* temp){ current = temp;}

// Return head nodes data 
LinkedList::dataType LinkedList::getFromHead() const{ return head->getData(); } 

// Return current nodes data
LinkedList::dataType LinkedList::getFromCurrent() const{ return current->getData();} 

// Return tail nodes data
LinkedList::dataType LinkedList::getFromTail() const{ return tail->getData();} 

// Move current node to the node after
void LinkedList::forward(){ current = current->getNext();} 

// Move current to the start of the list (head)
void LinkedList::start(){current = head;}

// Return current size of the list
int LinkedList::getSize() const{ return listLength;}

// Returns true if current is NULL or the list is over else false
bool LinkedList:: end() const{
    if(current == NULL) return false;
    else return true;
}







// Add to head function which creates new nodes at the head of the list
void LinkedList::addToHead(const dataType& dataToHead){
    Node* newNode = new Node(dataToHead); // Create new new node with object parameter and set previous to null

    newNode->setPrev(NULL);
    
    if(head!=NULL){ // If head is not currently null set the current heads previous to the new nodes
        head->setPrev(newNode);
    }
    
    newNode->setNext(head); // New nodes next becomes the old head and new node then becomes the head
    head = newNode;
    listLength++; // Increment list 
}
// Add to current function which adds a new node next to current
void LinkedList:: addToCurrent(const dataType& dataToCurrent){
    Node* newNode = new Node(dataToCurrent); // Create new node with object parameter
    // Set all the appropriate pointers for the new nodes so it is linked to the surrounding nodoes
    newNode->setNext(current); 
    newNode->setPrev(current->getPrev()); 
    current->setPrev(newNode); 
    newNode->getPrev()->setNext(newNode);
    current = head;
    listLength++; // Increment list 
}

// Add to tail function that adds every new node to the end of the list
void LinkedList::addToTail(const dataType& dataToTail){
    // If the head is null the list is empty therefore head, current and tail are the same node
    if(head == NULL){
        Node* newNode = new Node(dataToTail);
        head = newNode;
        current = head;
        tail = newNode;
    
    }else{
        // If head is not null set existing tails next pointer to the new node
        Node* newNode = new Node(dataToTail);
        tail->setNext(newNode);
        newNode->setPrev(tail); // Set the new nodes previous pointer to the tail
        tail = newNode; // Set tail of the list to the new node
        newNode = NULL; // New node to null
    }
    listLength++; // Increment list 
}
// Remove from head function removes the node at the head (start) of the list
LinkedList:: dataType LinkedList::removeFromHead(){
    // Temporary node and set it to head
    Node* temp;
    temp = head;
    
    dataType returnObj = head->getData(); // Storing the heads object to return later

    
    head = head->getNext(); // New head is now the node after the current head
    
    if(head != NULL) head->setPrev(NULL);// If the list is not empty set the heads previous pointer to null                  
    else tail = NULL;                   // otherwise tail to null
    
    // Delete temp, decrease list length and return the old head object
    delete temp;
    listLength--;
    current = head;
    return returnObj; // Return the object we deleted
    

}
// Remove from tail function that removes the node at the tail 
LinkedList:: dataType LinkedList::removeFromTail(){

    
    Node* temp; // Temp node set it equal to the tail      
    temp = tail;
    dataType returnObj = tail->getData(); // Storing the tail nodes data to return later
    tail = temp->getPrev(); 
                    
    if (tail != NULL) tail -> setNext(NULL); // If tail is not null then set tails next to null      
    else head = NULL;                       // Otherwise head is now null
    
    // Delete temp, decrease list length and current is now null    
    delete temp;
    listLength --;
    current = NULL;
    
    return returnObj; // Return the object we deleted
}
// Remove from current node function
LinkedList:: dataType LinkedList::removeFromCurrent(){
    Node* temp; // Temp node
    dataType returnObj = current->getData(); // Store the current nodes data to return later
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
// Remove function that consists of the previous remove functions to make it simpler
LinkedList:: dataType LinkedList::remove(const string nameToRemove){
    current = head; // Current is equal to head

    dataType obj; // Creating dataType obj to assign and then return later
     
    while(current != NULL)
    {
            // Check if current node has the name to remove and if it is the head
        if (nameToRemove==current->getData().get_name() && current==head)
        {
            obj = removeFromHead(); // Call the remove from head function and store the object removed
        }
            
            // Checks if current node has the name to remove and if it is the tail
        else if (nameToRemove==current->getData().get_name() && current==tail)
        {
            obj = removeFromTail(); // Call the remove from tail function and store the object that was removed
        }
            
            // Checks if current node is equal name to remove 
        else if(nameToRemove==current->getData().get_name()) 
        {
            obj = removeFromCurrent(); // Call the remove from current function and store object that was removed
        }
            
        else
        {
            current = current->getNext(); // Get next node
        }
                
        }

    return obj; // Return the object that was removed
}

const double LinkedList::calcAverage(){
    
    Node* temp = head; // Temp node equal to start of list
    double average = 0;
    do{
        
        average += temp->getData().get_score(); // Add each node score to average

        temp = temp->getNext();        // Set temp to the next node

    }while(temp != NULL);
    
    average /= listLength; // Divide sum of scores by length of the current list

    return average;
    
}
int LinkedList::count(const string nameToCount) const{
    int countStudent = 0;
    Node* temp = head; // Temp node equal start of the list
    do{
        if(temp->getData().get_name() == nameToCount){ // Compare temps student name if it is increment count 
            countStudent++;
        }
        temp = temp->getNext(); // Get next node
    }while(temp != NULL);
    
    delete temp; // Delete temp node
    return countStudent;
}

LinkedList& LinkedList::operator+= (LinkedList& temp_list)
{
    // IF ANY 
    temp_list.start(); // Set the current node to the head of the list
    do{
        this->addToTail(temp_list.getFromCurrent()); // Add the current nodes data to tail to concat the two lists
        temp_list.setCurrent(temp_list.current->getNext()); //  Get the next node

    }while(temp_list.current != NULL);

    return *this;
}
ostream& operator<<(ostream& os, LinkedList& temp)  
{
    temp.start(); // Call start function which sets current node to the head
    do{
        os << temp.getFromCurrent();  // Add the current data to os
        temp.forward(); // Call forward to move to the next node
    }while(temp.end());
    
   
    return os;  
}



