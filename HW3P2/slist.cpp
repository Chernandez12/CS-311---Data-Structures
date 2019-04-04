//
//  slist.cpp
//  HW3P2
//
//  Created by Andre Hernandez on 10/13/18.
//  Copyright © 2018 Andre Hernandez. All rights reserved.
//

using namespace std;
#include<iostream>
#include "slist.h"

slist::slist() {
    cout << "Calling the slist Constructor";
    Front = NULL;
    Rear = NULL;
    Count = 0;
}   // constructor which does nothing

//search through the list to see if any node contains Key.
//If so, return its position (>=1). Otherwise, return 0.
int search(el_t Key){
    Node *P = Front;
    int num = 1;            // Element number to return
    while (P != NULL) {
        if(P->elem == Key)
            return num;
        num++;
        P = P->Next;
    }
    return 0;
}

//go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
//If I was an illegal value, throw an exception (OutOfRange).
void replace(el_t Elem, int I){
    Node *P = Front;
    if (I < 1 || I > Count)
        throw OutOfRange();
    
    for (int i = 1; i < I; i++)
        P = P->Next;
    
    P->Elem = Elem;
}

bool operator==(const slist&){
    
}
//compare two slist object to see if they look the same.

