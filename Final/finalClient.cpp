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
#include <iostream>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "htable.h"

// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{
    htable hashTable;
    el_t empty;
    //    int input = 0;
    //    char str[20];
    
    //char inputStr[4];
    string inputStr = " ";
    string firstName = " ";
    string lastName = " ";
    int key;
    int i = 0;
    //{ **
    // Loop:
    //   Interactively add about 20 keys and names to the table,
    //     making sure some of them collide. (function add)
    //     You can create el_t containing a key and name using a constructor.
    cout << "Thank you for joining the Rika-Mart Rewards club!" << endl;
    while (i != -1){
        cout << "Please Enter Your 5-Digit Rika-Mart ID, Enter -1 to quit: " ;
        cin >> inputStr;
        
        if (inputStr != "-1"){
            if (inputStr[4]!=NULL && inputStr[5] == NULL) {
                cout << "Enter First Name: " ;
                cin >> firstName;
                cout << "Enter Last Name: " ;
                cin >> lastName;
                key = atoi(inputStr.c_str()) / 50;
                
                //key = atoi(inputStr);
                el_t elem(key, firstName, lastName);
                hashTable.add(elem);
                i++;
            }
        }
        else
            i = -1;
    }
    
    // DisplayTable.
    hashTable.displayTable();
    
    int loopInput = 0;
    // Loop:
    while (loopInput != -1){
        //  Interactively look up names using keys. (function find)
        cout << "To Find Customer, Enter 5-Digit Rika-Mart ID, Enter -1 to quit" << endl;
        cin >> loopInput;
        
        if (loopInput != -1){
            //  Display the key + name if found else error message.
            loopInput /= 50;
            el_t found = hashTable.find(loopInput);
            if (found == empty)
            cout << "Error: Element not Found" << endl;
            else
            cout << "Found Customer: " << found <<  endl;
        }
    }
}
