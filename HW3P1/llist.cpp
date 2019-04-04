//CS311
//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  control-K cuts and control-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Carlos Andre Hernandez
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() {
    cout << "Calling the llist Constructor";
    Front = Rear = NULL;
    Count = 0;
}

llist::~llist() {
    cout << "Calling the llist deconstructor";
    el_t oldNum;
    while(!isEmpty()) {
        deleteFront(oldNum);
    }
}

// PURPOSE: Checks if the list is empty by checking if Front and Rear
// are both pointing to NULL and Count is 0
bool llist::isEmpty() {
    return Front == NULL && Rear == NULL && Count == 0;    // return true or false
}

// PURPOSE: Displays each element of the list starting from Front,
// enclosed in [] followed by Count and endl. If the list is empty, displays "[empty]"
void llist::displayAll() {
    if (isEmpty())      //Check that there is something to display.
        cout << "[ empty ]" << endl;
    else {              //else, there really is something to display
        Node *P = Front;            //set a temporary pointer to the front of the list.
        while (P != NULL) {         //while it isn't NULL (Reach the end) display the elements in brackets.
            cout << "[" << P->Elem << "] ";
            P = P->Next;            //move the pointer to the next node.
        }
        cout << endl;
    }
}

// PURPOSE: Adds a new node at the rear
//  If first node, creates new node and makes Front and Rear Point to it
// PARAMETER: The element to be added to the back of the list
void llist::addRear(el_t NewNum) {
    if (Front == NULL) {        //if this is the first element we are adding, it needs to be made front and rear
        Front = new Node;       //make a new node that is front
        Rear = Front;           //set both front and rear to the same node
    }
    else {                      //else, we can simply add a new node at the rear of the list
        Rear->Next = new Node;  //make a new rear->next node to take the elem
        Rear = Rear->Next;      //set rear to that node
    }
    Rear->Elem = NewNum;        //give the new node the elem
    Rear->Next = NULL;          //set the rear->next to NULL for reasons
    Count++;
}

// PURPOSE: Adds a new node at the front
//  If this first node, creates new node and makes Front and Rear point to it
// PARAMETER: The element to be added to the front of the list
void llist::addFront(el_t NewNum) {
    if (Front == NULL) {    //make sure we are empty
        Front = new Node;   //make a new front node
        Front->Elem = NewNum;   //front-> elem is new filled with our new elem
        Front->Next = NULL;     //front->next shouldn't be pointing to anything
        Rear = Front;       //front and rear are still pointing to the same thing
    }
    else {
        Node *x;        //make a new temp node x
        x = new Node;
        x->Next = Front;    //set x->next to front so it is added to the front
        Front = x;          //set front to x
        Front->Elem = NewNum;   //add the new elem
    }
    Count++;
}

// PURPOSE: Deletes the front element
//  If this makes the list empty, gives back the front node element
//  If the list is empty, throw an exception
// PARAMETER: The variable passed to OldNum that will be deleted
void llist::deleteFront(el_t& OldNum) {
    if (isEmpty())      //error case: make sure we have something to delete
        throw Underflow();
    else if (Count == 1) {  //else, if there's only on elem
        OldNum = Front->Elem;   //set the returned variable to the old elem in the node.
        delete Front;       //delete the front elem
        Front = NULL;       //set front to NULL
        Rear = NULL;        //same with rear
        Count--;            //decrement count
    }
    else {      //else, we have more than one node/elem
        OldNum = Front->Elem;   //set the returned variable to the old elem in the node.
        Node *Second;       //make a temporary node so we don't lose front.
        Second = Front->Next;       //make the temp node->next point to the new front
        delete Front;   //delete front
        Front = Second;     //set front to the temporary node (new front)
        Count--;
    }
}

// PURPOSE: Deletes the rear Element
//  If this makes the list empty, gives back the rear node
//  If it is empty, throws an exception
// PARAMETER: The variable the receives OldElem
void llist::deleteRear(el_t& OldNum) {
    if (isEmpty())      //error case: check if empty
        throw Underflow();      //send error
    else if (Count == 1) {      //if only one elem/node is present
        OldNum = Rear->Elem;    //save the deleted elem
        delete Rear;            //delete rear
        Front = NULL;       //set rear and front to null
        Rear = NULL;
        Count--;        //decrement count
    }
    else {      //else, we have more than one elem/node
        OldNum = Rear->Elem;    //save the old elem to be deleted.
        Node *p = Front;        //make a temporary pointer at front
        //  Make p go to the one right before rear (using while)
        while (p->Next != Rear)     //we need to move through the list until we reach rear
            p = p->Next;        //keep moving until p->next = rear
        delete Rear;    //delete rear
        Rear = p;       //make p the new rear
        Rear->Next = NULL;  //make p->next = null
        Count--;        //decrement count
    }
}

// PURPOSE: Deletes the ith node
//  If I is an illegal value throws an exception
// PARAMETER: An int representing the node you want to delete,
//  variable to receive the old element
void llist::deleteIth(int I, el_t& OldNum) {
    if (I > Count || I < 1)     //make sure we have a valid number
        throw OutOfRange();
    else if (I == 1)        //if first elem, call the func
        deleteFront(OldNum);
    else if (I == Count)    //if the last elem, call the func
        deleteRear(OldNum);
    else {      //else, it's in the middle
        Node *P = Front;    //make a temp point at p
        Node *PToDelete = Front->Next;  //make a temp pointer at the next node after front
        for (int K = 1; K < I-1; K++) {    //go through the list one node at a time, until we hit our number-1
            P = P->Next;
            PToDelete = PToDelete->Next;
        }
        P->Next = PToDelete->Next;  //then we want to make p->next to point to the elem after the one being deleted
        OldNum = PToDelete->Elem;   //save the old elem
        delete PToDelete;       //delete the node
        Count--;        //decrement count
    }
}

// PURPOSE: Inserts element before the ith node
// PARAMETER: An int representing the node you want to add, and the
//  designated element
void llist::insertIth(int I, el_t newNum) {
    if (I > Count + 1 || I < 1)   //make sure we have a valid number for the list
        throw OutOfRange();
    else if (I == 1)        //else call the right func if it's the first elem
        addFront(newNum);
    else if (I == Count+1)  //else, call the right func if it's the last elem
        addRear(newNum);
    else {      //else it's somewhere in the middle
        Node *P = Front;    //make a temp node at front to move through the list
        for (int K = 1; K < I-1; K++) {    //move through the list one node at a time
            P = P->Next;
        }
        Node *temp = P->Next;   //make a temp node to save p->next
        //Node *temp = P;
        P->Next = new Node;     //make a new node at p->next
        P->Next->Elem = newNum; //give it an elem
        P->Next->Next = temp;   //set that new node's->next to the temp node
        Count++;    //increment count
    }
}

//PURPOSE: To allow pass by value and return by value
//PARAMETER: Original list passed by reference
llist::llist(const llist& Original) {
    this->Front = NULL; this->Rear = NULL; this->Count = 0;
    
    Node* P;  // local pointer for OtherOne
    P = Original.Front;
    while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne.
    {
        this->addRear(P->Elem);    //P’s element is added to this->
        P = P->Next;               // Go to the next node in OtherOne
    }
}

//PURPOSE: Allows the client to use "=" to linked lists
//PARAMETER: Other list passed by reference
llist& llist::operator=(const llist& OtherOne) {
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    el_t x;
    if (&OtherOne != this)  // if not the same
    {
        // this-> object has to be emptied first.
        while (!this->isEmpty() )
            this->deleteRear(x);
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
            this->addRear(P->Elem);    //P’s element is added to this->
            P = P->Next;                         // Go to the next node in OtherOne
        }
    }// end of if
    return *this;    // return the result unconditionally.  Note that the result is returned by reference.
}

