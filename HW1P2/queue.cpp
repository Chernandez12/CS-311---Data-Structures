//INSTRUCTION:
//Look for ** using control-S
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Carlos Andre Hernandez
//Complier:  g++
//File type: queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue(){
    count = 0;
    front = 0;
    rear = -1;
}

//destructor 
queue::~queue(){}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty(){
    if(count == 0)
        return true;
    else
        return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull(){
    if (count == MAX_SIZE)
        return true;
    else
        return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem){
    if (isFull())
        throw Overflow();
    else {
        rear = (rear + 1) % MAX_SIZE;
        el[rear] = newElem;
        count++;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem){
    if (isEmpty())
        throw Underflow();
    else {
        el_t temp = el[front];              // Create a temporary variable to hold front element
        front = (front + 1) % MAX_SIZE;     // Set new front
        count--;                            // Reduce the item count
        removedElem = temp;                 // and return the old front element
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem){
    if (isEmpty())
        throw Underflow();
    else
        theElem = el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize(){
    return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll(){
    if (isEmpty())
        cout << "[ empty ]" << endl;
    else {
        int j = front;
        int current;
        cout << "[\n";
        for (int i = 1; i <= count; i++){
            current = j % MAX_SIZE;
            cout << el[current] << endl;
            j++;
        }
        cout << "]" << endl;
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack(){
    el_t elemToGoBack;  // make a local variable
    remove(elemToGoBack);   //remove the last element and store it in the local variable
    add(elemToGoBack);  //add the local variable back to the back of the queue
}

