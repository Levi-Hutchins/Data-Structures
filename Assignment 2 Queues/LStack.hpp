/*
Author: Levi Hutchins
Student Number: C3386116
Course: SENG1120
Description: This file allows for Stacks of any type to be created.
Works by adding items of T type to the head of a linkedlist and removing from 
the head of the stack. Stacks are based on LIFO principle (Last in first out)
*/

#include "LStack.h"
#include <string>

template <typename T> // Templatised function
// Constructor implementation
LStack<T>::LStack(){
    data = LinkedList<T>(); // Create new LinkedList of type T 
                            // Allows for creation of any type
    used = 0; // Size of stack initally 0

}
template <typename T> // Templatised function
// Destructor implementation
LStack<T>:: ~LStack(){
    used = 0; // Set size of stack to 0
}

template <typename T> // Templatised function
void LStack<T>:: push( const T& item){ 
    data.addToHead(item); // Add the item to the head of the list
    used++;
    } 


template <typename T> // Templatised function
// Return the item that was removed from the head
T LStack<T>:: pop(){ 
    used--;
    return data.removeFromHead();
    } 


// Templatised fucntion that returns the item at the head
// only if the LinkedList is not empty
template <typename T> // Templatised function
T LStack<T>::peek() const{
    if(!isEmpty()){
        return data.getFromHead();
    } 
    else{
        // Return 0 is the list is empty
        return 0;
    }
}

template <typename T> // Templatised function
// Return if data's LinkedList is empty or not
bool LStack<T>::isEmpty() const{ return used == 0;} 


template <typename T> // Templatised function
ostream& operator<<(ostream& os, LStack<T>& myS){


    LStack<T> tempS; // Create a temp stack
    while(!myS.isEmpty()){ // Loop while the stack is not empty
        T item = myS.pop(); // Store the item that was removed from the head
        os << item << " "; // Append that item to os and a space so its matches provided output XD
        tempS.push(item); // Add the item we removed to our temp stack
    }

    while(!tempS.isEmpty()){ // Loop while the temp stack is not empty
        T itemBack = tempS.pop(); // Store the item removed from the top
        myS.push(itemBack); // Add the item back to our original stack so it is not destoyed
    }


    return os; // Return os so we can display the result
}