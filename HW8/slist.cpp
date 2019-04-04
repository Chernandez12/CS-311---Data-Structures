//
//  slist.cpp
//  HW3P2
//
//  Created by Andre Hernandez on 10/13/18.
//  Copyright © 2018 Andre Hernandez. All rights reserved.
//

using namespace std;
#include <iostream>
#include "slist.h"

slist::slist() {
    //cout << "Calling the slist Constructor" << endl;
    Front = NULL;
    Rear = NULL;
    Count = 0;
}   // constructor which does nothing

//search through the list to see if any node contains Key.
//If so, return its position (>=1). Otherwise, return 0.
int slist::search(el_t Key){
    Node *P = Front;
    int num = 1;            // Element number to return
    while (P != NULL) {
        if(P->Elem == Key)
            return num;
        num++;
        P = P->Next;
    }
    return 0;
}

//search through the list to see if any node contains Key.
//If so, return the element. Otherwise, return empty Element
el_t slist::search2(el_t Key){
    Node *P = Front;
    
    while (P != NULL) {
        if(P->Elem == Key)
            return P->Elem;
        P = P->Next;
    }
    el_t empty;
    return empty;
}

//go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
//If I was an illegal value, throw an exception (OutOfRange).
void slist::replace(el_t Elem, int I){
    Node *P = Front;
    if (I < 1 || I > Count)
        throw OutOfRange();
    
    for (int i = 1; i < I; i++)
        P = P->Next;
    
    P->Elem = Elem;
}

bool slist::operator==(const slist& list2) const{
    // Check if the lists are the same size
    if(this->Count != list2.Count){
        return false;
    }
    Node* P1;  // local pointer for listTest
    Node* P2;
    P1 = this->Front;
    P2 = list2.Front;
    while (P1!= NULL)
    {
        if (P1->Elem == P2->Elem){
            return true;
        }
        P1 = P1->Next;
        P2 = P2->Next;
    }
    return true;
}



