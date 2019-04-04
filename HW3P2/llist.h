//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: **
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
    el_t Elem;   // elem is the element stored
    Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
    
protected:
    Node *Front;       // pointer to the front node
    Node *Rear;        // pointer to the rear node
    int  Count;        // counter for the number of nodes
    
public:
    
    // Exception handling classes
    class Underflow{};
    class OutOfRange{};  // thrown when the specified Node is out of range
    
    llist ();     // constructor to create a list object
    ~llist();     // destructor to destroy all nodes
    
    // PURPOSE: Checks if the list is empty by checking if Front and Rear
    // are both pointing to NULL and Count is 0
    bool isEmpty();
    
    // PURPOSE: Displays each element of the list starting from Front,
    // enclosed in [] followed by Count and endl. If the list is empty, displays "[empty]"
    void displayAll();
    
    // PURPOSE: Adds a new node at the rear
    //  If first node, creates new node and makes Front and Rear Point to it
    // PARAMETER: The element to be added to the back of the list
    void addRear(el_t NewNum);
    
    // PURPOSE: Adds a new node at the front
    //  If this first node, creates new node and makes Front and Rear point to it
    // PARAMETER: The element to be added to the front of the list
    void addFront(el_t NewNum);
    
    // PURPOSE: Deletes the front element
    //  If this makes the list empty, gives back the front node element
    //  If the list is empty, throw an exception
    // PARAMETER: The variable passed to OldNum that will be deleted
    void deleteFront(el_t& OldNum);
    
    // PURPOSE: Deletes the rear Element
    //  If this makes the list empty, gives back the rear node
    //  If it is empty, throws an exception
    // PARAMETER: The variable the receives OldElem
    void deleteRear(el_t& OldNum);
    
    // PURPOSE: Deletes the ith node
    //  If I is an illegal value throws an exception
    // PARAMETER: An int representing the node you want to delete,
    //  variable to receive the old element
    void deleteIth(int I, el_t& OldNum);
    
    // PURPOSE: Inserts element before the ith node
    // PARAMETER: An int representing the node you want to add, and the
    //  designated element
    void insertIth(int I, el_t newNum);
    
    // PURPOSE: To allow pass by value and return by value
    // PARAMETER: Original list passed by reference
    llist(const llist& Original);
    
    // PURPOSE: Allows the client to use "=" to linked lists
    // PARAMETER: Other list passed by reference
    llist& operator=(const llist& OtherOne);
};
