//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue
//Your name: Carlos Andre Hernandez
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program:
// This program is meant to use the queue class
// by adding a string to the queue every iteration until it overflows
//Algorithm: Indefinite loop that adds a string every iteration

int main(){
    queue q;                                // Declaration of the queue "q"
    q.add("A");                             // Add "A", "B", "C" in the queue
    q.add("B");
    q.add("C");
    
    while (true){                           // while loop -- indefinitely
      try {
          string phrase;                    // The string used to insert in the queue
          
        if (!q.isEmpty()) {                 // If the queue is not empty remove the front element
            q.remove(phrase);
        }
        cout << phrase << endl;             // Display front element
          
        if (!q.isFull()) {                  // While the queue isn't full
            q.add(phrase + "A");            // Add 3 branches
            q.add(phrase + "B");
            q.add(phrase + "C");
        }
    }
        
    // Catch exceptions and report problems and quit the program now.
    // Error messages describe what is wrong with the expression.
        catch(queue::Overflow){
            cerr << "Error: You have caused the stack to overflow." << endl;
            return 0;
        }
        catch(queue::Underflow){
            cerr << "Error: You have caused the stack to underflow." << endl;
            return 0;
        }
    } // end of loop
}


