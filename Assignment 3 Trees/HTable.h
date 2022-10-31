/* Author: Levi Hutchins
   Course: SENG 1120
   Description: 
   Class definition of the hash table. Includes all
   required functions for the demo to work.
   The file has been templatised ot allow for a HTable of any data type.


*/

#ifndef HTABLE // Macroguard
#define HTABLE
#include <iostream>
using namespace std;
template <typename E> // Templatised class
class HTable{
    
    public:
        // Precondition: None
        // Postcondition: A HTable is created populated with default objects
        HTable();

        // Precondition: A given size for the HTable
        // Postcondition: A HTable is created with the specific size
        HTable(int maxSize);

        // Precondition: None
        // Postcondition: Set current HTable to empty table
        ~HTable();

        // Precondition: Valid data to find the hash
        // Postcondition: Value ios returned that represents the position
        int hashFunc(const E& data);

        // Precondition: Data to be added
        // Postcondition: Object is added into the HTable at the hashfucntion position
        void add(const E& dataIn);

        // Precondition: None
        // Postcondition: Sends the output to the out operator which calls it
        void printAll(std::ostream& out);

        // Precondition: Data to be removed
        // Postcondition: Object is removed and returned 
        E   remove(E dataToRemove);

        // Precondition: A HTable to be able calculate inventory
        // Postcondition: Returns the sum of the inventory inside the HTable
        int calculateInventory() const;

        
        // Precondition: A HTable to be able calculate parts
        // Postcondition:Returns the sum of the parts inside the HTable
        int calculateParts() const;
        


    private:
        // Member variables
        int TABLESIZE = 5000;
        E hTableData[5000];
        int size;
    









};
// Overloaded function to be able to print a HTable
template <typename E> 
ostream& operator<<(ostream& os, HTable<E>& tableToPrint); 

// Include the implementation file
#include "HTable.hpp"
#endif //End macroguard