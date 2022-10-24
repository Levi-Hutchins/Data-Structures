/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description: This implementation file allows for Queues of any tye to be created.
It works by adding items of T type to the tail of a LinkedList and removing from 
the head. Queues are based on the FIFO (First in first out)
*/

#include "LQueue.h"


template <typename T> // Templatised function
// Constructor implementation
LQueue<T>::LQueue(){
    data = LinkedList<T>(); // Create a new LinkedList of type T
                            // Allows for creation of any type
    used = 0; // Size of queue initally 0              
}

template <typename T> // Templatised function
// Destructor implementation
LQueue<T>::~LQueue(){
    used = 0; // Set size of queue to 0
}


template <typename T> // Templatised function
// Adding item to the queue
void LQueue<T>::enqueue(const T& obj){
    data.addToTail(obj); // Add item to the tail of the queue
    used++; // 
}


//Removes item at the head of the queue and returns that item
template <typename T> // Templatised function
T LQueue<T>:: dequeue(){
    used--; // Decrement size of queue
    return data.removeFromHead();
}

// Returns item at the front of the queue
template <typename T> // Templatised function
T LQueue<T>::front() const{ return data.getFromHead();}


// Returns whether the queue is empty
template <typename T> // Templatised function
bool LQueue<T>::isEmpty() const{ return used == 0;}


// Returns size of the Queue
template <typename T> // Templatised function
int LQueue<T>::size() const{ return used;}


template <typename T> // Templatised function
ostream& operator<<(ostream& os, LQueue<T>& myQ){
    LQueue<T> tempQ; // Create a temp Queue

    while(!myQ.isEmpty()){ // Loop while the Queue is not empty
        os << myQ.front() << " "; // Append the item at the front 
        T item = myQ.dequeue(); // Store the item removed from the front
        tempQ.enqueue(item); // Add that item to the tail of the tempQ
    }
    // Now loop through tempQ to put our items back into orginal Queue
    while(!tempQ.isEmpty()){ // Loop while is not empty
        T k = tempQ.dequeue(); // Store the item removed
        myQ.enqueue(k); // Add that item back to our original Queue so its not destroyed
    }



    return os; // Return os so was can display the result
}

