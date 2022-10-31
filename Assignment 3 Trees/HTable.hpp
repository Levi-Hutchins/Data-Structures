/* Author: Levi Hutchins
   Course: SENG 1120
   Description: 
   This is the implementation of a working hash table.
   It includes the hash function, adding, removing, and calculating 
   information of the data. 
   The file has been templatised ot allow for a HTable of any data type.
                

*/
#include "string"
#include "HTable.h"
#include <iostream>
using namespace std;

template <typename E> // Templatised Function
HTable<E>::HTable(){
    // Default constructor, initialises the data
    for(int i = 0; i < TABLESIZE; i++) hTableData[i] = E();
    
}
template <typename E> // Templatised Function
HTable<E>::~HTable(){
    // Destructor, Setting the table[i] = NULL gives an error
    // My next guess was to just set to a default object?
    for(int i = 0; i < TABLESIZE; i++) hTableData[i] = E();
    
}
template <typename E> // Templatised Function
HTable<E>::HTable(int maxSize){
    // Specific constructor to create table of designated size
    for(int i = 0; i < maxSize; i++) hTableData[i] = E();
    
}
template <typename E> // Templatised Function
int HTable<E>::hashFunc ( const E& data ) { 
    // Maths function to determine the location of the elements 
    // being added. (provided)
    int position = 0; 
    string temp = data.get_code(); 
    for ( int i=0; i<(int)temp.length( ); i++ ) { 
    position += ( i+1 ) * ( i+1 ) * temp.at( i ); 
    } 
    return position % 5000; 
} 
template <typename E> // Templatised Function
E HTable<E>::remove(E dataToRemove){
    // Removing by finding the position
    // Storing to be returned then set that position to default object
    int loc = hashFunc(dataToRemove);
    E item = hTableData[loc];
    hTableData[loc] = E();
    size--;
    return item;

}

template <typename E> // Templatised Function
void HTable<E>::add(const E& dataIn){
    // Call the has function to determine the location then place item
    hTableData[hashFunc(dataIn)] = dataIn;
    size++;
}
template <typename E> // Templatised Function
int HTable<E>::calculateInventory() const{
    // Loop over table and count quantity and return
    int total = 0;
    for(int i = 0; i < TABLESIZE; i++) if(hTableData[i].get_quantity() != 0) total += hTableData[i].get_quantity();
        // Kind of redundant statement since 0 will not affect the sum, however just thought to be safe

    
    return total;
}
template <typename E> // Templatised Function
int HTable<E>::calculateParts() const{
    // Loop over table if there is a code increment the total and return
    int total = 0;
    for(int i = 0; i < TABLESIZE; i++) if(hTableData[i].get_code() != "") total++;
    return total;
    }
template <typename E> // Templatised Function
void HTable<E>::printAll(std::ostream& out){
    // Printing the table, taking the out operator as a parameter to directly appended.
    // Only append items that have a code and quantity
    for(int i = 0; i < TABLESIZE; i++) if(hTableData[i].get_quantity() != 0 && hTableData[i].get_code() != "") out << hTableData[i] << " ";
    
}
template <typename E> // Templatised Function
ostream& operator<<(std::ostream& out, HTable<E>& tableToPrint){
    // Call printAll function and send out operator
    tableToPrint.printAll(out);
    return out;
}

