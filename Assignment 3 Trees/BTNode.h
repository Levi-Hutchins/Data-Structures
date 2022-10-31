/* Author: Levi Hutchins
   Course: SENG 1120
   Description: 
   This file is the class header definition of the BTNode.
   Consists of all the appropriate function definitions.
   The class has been templatised to allow for BTNodes of 
   any data time


*/

#ifndef BTNODE // Macroguard
#define BTNODE
#include <iostream>
#include <string>
using namespace std;


template <typename E>  // Templatised Class
class BTNode{ 
   public: 
      // Precondition: None
      // Postcondtion: BTNode created
      BTNode (); 

      // Precondition: Data to add to BTNode
      // Postcondtion: BTNode created with data
      BTNode (E& dataIn); 

      // Precondition: None
      // Postcondtion: Node deleted
      ~BTNode (); 

      // Precondition: Data to set
      // Postcondtion: Data is added to BTNode
      void setData   (const E&   newData);

      // Precondition: A node to set parent to
      // Postcondtion: Parent is set
      void setParent (BTNode<E>* newParent); 

      // Precondition: A node to set left to
      // Postcondtion: Left is set
      void setLeft   (BTNode<E>* newLeft); 

      // Precondition: A node to set right to
      // Postcondtion: Right is set
      void setRight  (BTNode<E>* newRight);

      // Precondition: A node to get data from
      // Postcondtion: Data is returned from node
      E          getData   (); 

      // Precondition: A node to retrieve parent from
      // Postcondtion: Parent is returned
      BTNode<E>* getParent (); 

      // Precondition: A node to retrieve left from
      // Postcondtion: Left is returned
      BTNode<E>* getLeft   (); 

      // Precondition: A node to retrieve right from
      // Postcondtion: Right is returned
      BTNode<E>* getRight  (); 
   private: 
   // Member Variables 
      E          data;  
      BTNode<E>* parent; 
      BTNode<E>* left; 
      BTNode<E>* right; 
};

// Include the implementation file
#include "BTNode.hpp"
#endif