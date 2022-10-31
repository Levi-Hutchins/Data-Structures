/* Author: Levi Hutchins
   Course: SENG 1120
   Description: This is the class definition for the BSTree.
    Contains all the required functions for the demo file to
    run, including a few additional helper functions
*/

#ifndef BSTREE // Macroguard
#define BSTREE
#include "BTNode.h"
using namespace std;
template <typename E>
class BSTree{ 
    public:
        // Precondition: None
        // Postcondition: A Binary Search Tree is created
        BSTree();

        // Precondition: None
        // Postcondition: A Binary Search Tree is destroyed
        ~BSTree();

        // Precondition: A BST to delete all the containing nodes
        // Postcondition: All nodes deleted
        void deleteAllNodes(BTNode<E>* root);

        // Precondition: A node to extract data
        // Postcondition: Appended the nodes data to out operator to be displayed
        void    inOrder(BTNode<E>* currentNode,std::ostream& out);

        // Precondition: Out operator
        // Postcondition:  None - Call inOrder Function?
        void    outerHelper(std::ostream& out);

        // Precondition: A valid object to added to the tree
        // Postcondition: Object is added to BST and size incremented
        void    add(E& item);

        // Precondition: A valid object to remove
        // Postcondition:  Object is removed and size is decremented
        E       remove(const E removeItem);

        // Precondition: A Valid object to find 
        // Postcondition: Object is returned if it is in the BST 
        E&      find(E& item);

        // Precondition: A BST
        // Postcondition: Size of BST
        int     size() const;

        // Precondition: A BST and root node to start from
        // Postcondition: A sum of all the quantities in the BST
        int     findQuantites(BTNode<E>* root) const;

        // Precondition: A BST and root node to start from
        // Postcondition: A sum of all the codes in the BST
        int     findCodes(BTNode<E>* root) const;

        // Precondition: A BST
        // Postcondition: calls the FindCodes function
        int     calculateParts();

        // Precondition: A BST  
        // Postcondition: Calls the findQuantities function
        int     calculateInventory();



    private:
        // Precondition: Object to add and a BTNode
        // Postcondition: Object is added to the BST
        void add(BTNode<E>* currentNode, E& item);

        // Precondition: A valid object to find
        // Postcondition: The node storing the object
        BTNode<E>* find(BTNode<E>* currentNode, E& target);

        // Precondition: A valid object to delete
        // Postcondition: Delete the node containing the object and ensure all nodes are connected
        BTNode<E>* deleteNode(BTNode<E>* root, E targetItem);

        // Precondition: A Node to find the left most child
        // Postcondition: The node containing the smallest value
        BTNode<E>* leftMostChild(BTNode<E>* currentNode);

        // Precondition: A node to find the right most child
        // Postcondition: The node containing the largest value
        BTNode<E>* rightMostChild(BTNode<E>* currentNode);
        
        //Member Variables
        BTNode<E>* root;
        BTNode<E>* current;
        E data;
        int treeSize;
};
// Overloaded function to print a BST
template <typename E> 
ostream& operator<<(ostream& os, BSTree<E>& treeToPrint); 
#include "BSTree.hpp" // Include implementation file
#endif // End macroguard 