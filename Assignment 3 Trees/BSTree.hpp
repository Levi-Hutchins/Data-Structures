/* Author: Levi Hutchins
   Course: SENG 1120
   Description: This is the implementation file of the BSTree.
   Allows for creation of a BSTree of any data type. Contains all the required
   functions and a few additional helper functions.

*/
#include "BSTree.h"
#include <string>

template <typename E> //Templatised Function
BSTree<E>::BSTree(){ 
    // Constructor initialises a BST
    root = NULL;
    current = NULL;
    E data;
    treeSize = 0;

}

template <typename E>//Templatised Function
BSTree<E>::~BSTree(){ 
    // Destructor destroys all nodes and free memory 
    deleteAllNodes(root);
}

template <typename E>//Templatised Function
void BSTree<E>::deleteAllNodes(BTNode<E>* root){
    // base case
    if(root == NULL) return;
    // Delete all nodes down the left and right sub trees
    // Recurses
    deleteAllNodes(root->getRight());
    deleteAllNodes(root->getLeft());

    delete root; //Delete the node
    treeSize --;
}

template <typename E>//Templatised Function
E BSTree<E>::remove(const E removeItem){
    treeSize--;
    return deleteNode(root, removeItem)->getData(); // Call recursive function with target item
}
template <typename E>//Templatised Function
BTNode<E>* BSTree<E>::deleteNode(BTNode<E>* root ,E targetItem){

    if(root == NULL) return NULL; // Base case
    // If the item is smaller than current node data then it is in left subtree
    // Send function down the subtree. fix node pointers
    if(targetItem < root->getData()){
        root->setLeft(deleteNode(root->getLeft(), targetItem));
        if(root->getLeft() != NULL) root->getLeft()->setParent(root); // added line
    }
     // If the item is greater than current node data then it is in right subtree
    // Send function down the subtree. fix node pointers
    else if(targetItem > root->getData()){
        root->setRight(deleteNode(root->getRight(),targetItem));
        if(root->getRight() != NULL) root->getRight()->setParent(root); //added line
    }
    else{
        // If the node is a leaf
        if(root->getLeft() == NULL && root->getRight() == NULL) return NULL;

        // If it has atleast one child
        else if(root->getLeft() == NULL){
            BTNode<E>* temp = root->getRight();
            delete root;
            return temp;
        }
        else if(root->getRight() == NULL){
            BTNode<E>* temp = root->getLeft();
            delete root;
            return temp;
        }
    // FInd smallest node of current node and set pointer accordingly 
    BTNode<E>* temp = leftMostChild(root->getRight());
    root->setData(temp->getData());
    root->setRight(deleteNode(root->getRight(), temp->getData()));
    }
    return root;
}

template <typename E>//Templatised Function
void BSTree<E>::add(E& item){
    // add item if no tree
    if(root == NULL) root = new BTNode<E>(item);
    else add(root, item); // Send the recursive function the object and root
    treeSize++;
}

template <typename E>//Templatised Function
void BSTree<E>::add(BTNode<E>* currentNode, E& item){
    // Base case if item already exists just update it
    if(item == currentNode->getData()) currentNode->setData(item);
    // If item is greater than current and has no right child add
    // else send down the right 
    else if(item > currentNode->getData()){
        if(currentNode->getRight() == NULL) currentNode->setRight(new BTNode<E>(item));
        else add(currentNode->getRight(), item);
    }
    else{
        // Not greater so must be smaller and if has no child set item to left node
        // else send down the left
        if(currentNode->getLeft() == NULL) currentNode->setLeft(new BTNode<E>(item));
        else add(currentNode->getLeft(),item);
    }
    
}
template <typename E>//Templatised Function
E& BSTree<E>::find(E& target){ return find(root, target);} // Call recursive function with root and target
template <typename E>//Templatised Function
BTNode<E>* BSTree<E>::find(BTNode<E>* currentNode,E& target){
    // Base case 
    if(currentNode == NULL) return NULL;
    else{
        // Find the item set current node to node
        if(target == currentNode->getData()){
            current = currentNode;
            return currentNode;
        }
        // If the target is less than current data send down left tree
        // else send down right tree
        else if (target < currentNode->getData()) return findItem(currentNode->getLeft(), target);
        else return findItem(currentNode->getRight(), target);
    }
}

template <typename E>//Templatised Function
int BSTree<E>::size() const{ return treeSize;} // Return tree size

template <typename E>//Templatised Function
void BSTree<E>::outerHelper(std::ostream& out){ inOrder(root,out);}

template <typename E>//Templatised Function
void BSTree<E>::inOrder(BTNode<E>* currentNode, std::ostream& out){
    // Recurse and add the data to out operator
    if(currentNode != NULL){
        inOrder(currentNode->getLeft(), out);
        out << currentNode->getData();
        inOrder(currentNode->getRight(),out);
    }
}
template <typename E>//Templatised Function
BTNode<E>* BSTree<E>::leftMostChild(BTNode<E>* currentNode){
    // Recurse til smallest is found
    if(currentNode->getLeft() == NULL) return currentNode;
    else return leftMostChild(currentNode->getLeft());
}

template <typename E>//Templatised Function
BTNode<E>* BSTree<E>::rightMostChild(BTNode<E>* currentNode){
    // Recurse til largest is found
    if(currentNode->getRight() == NULL) return currentNode;
    else return rightMostChild(currentNode->getRight());
}

template <typename E>//Templatised Function
int BSTree<E>::calculateParts(){ return findCodes(root);}     // Call recursive function return sum
template <typename E>//Templatised Function
int BSTree<E>::findCodes(BTNode<E>* root)const{
    // Recurse and check if the code is not empty and increment
    // add total from returned sums
    int total = 0;
    if(root != NULL){
        if(root->getData().get_code() != "") total ++;
        total += findCodes(root->getRight());
        total += findCodes(root->getLeft());
    }
    return total;
}

template <typename E>//Templatised Function
int BSTree<E>::calculateInventory(){ return findQuantites(root);}     // Call recursive function return sum

template <typename E>//Templatised Function
int BSTree<E>::findQuantites(BTNode<E>* root)const{
    // Recurse and add the total from returned sums
    int total = 0;
    if(root != NULL){
        total += root->getData().get_quantity();
        total+= findQuantites(root->getLeft());
        total+= findQuantites(root->getRight());
    }
    return total;
}

template <typename E>//Templatised Function
ostream& operator<<(std::ostream& out, BSTree<E>& treeToPrint){
    treeToPrint.outerHelper(out); //Call outer helper to be able to print tree
    return out;
}