// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Carlos Andre Hernandez
// File type: client hw8client.cpp
//===========================================

using namespace std;
#include "htable.h"

// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{
    htable hashTable;
    el_t empty;
    int input = 0;
    char str[20];
//{ **
// Loop:
//   Interactively add about 20 keys and names to the table,
//     making sure some of them collide. (function add)
//     You can create el_t containing a key and name using a constructor.
    for (int i = 0; i < 10; i++){
        cout << "Enter Key: " ;
        cin >> input;
        cout << "Enter Name: " ;
        cin >> str;
        
        el_t elem(input, str);
        hashTable.add(elem);
    }
    
// DisplayTable.
    hashTable.displayTable();

    int loopInput = 0;
// Loop:
    while (loopInput != -1){
        //  Interactively look up names using keys. (function find)
        cout << "Look for? " << endl;
        cin >> loopInput;
        
        if (loopInput != -1){
            //  Display the key + name if found else error message.
            el_t found = hashTable.find(loopInput);
            if (found == empty)
                cout << "Error: Element not Found" << endl;
            else
                cout << "Found: " << found <<  endl;
        }
    }
 }
