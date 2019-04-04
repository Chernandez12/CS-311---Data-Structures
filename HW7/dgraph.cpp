//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Carlos Andre Hernandez
// File Type: cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include "dgraph.h"

dgraph::dgraph() {
    for (int i = 0; i < SIZE ; i++){
        // initialize vertexName (blank) and visit numbers (0)
        Gtable[i].vertexName = ' ';
        Gtable[i].outDegree = 0;
        Gtable[i].visit = 0;
    }
    // initialize countUsed to be 0
    countUsed = 0;
}

dgraph::~dgraph(){}

void dgraph::fillTable()  // be sure to read from a file
{
    char x;
    ifstream fin ("table.txt", ios::in);
    
    while (fin >> Gtable[countUsed].vertexName) // IF I CAN READ THE NAME
    {
        fin >> Gtable[countUsed].outDegree;
        
        for (int i = 1; i <= Gtable[countUsed].outDegree; i++){
            fin >> x;
            (Gtable[countUsed].adjacentOnes).addRear(x);// this is a slist function from HW3
        }
        countUsed++;
    }
    fin.close();
}

void dgraph::displayGraph()
{
    for (int i = 0; i < countUsed; i++)
    {
        cout << "Vertex Name: " << Gtable[i].vertexName << endl;
        cout << "Out Degree: " << Gtable[i].outDegree << endl;
        cout << "Visit: " << Gtable[i].visit << endl;
        //cout << "Adjacent Ones: \t" << endl;
        (Gtable[i].adjacentOnes).displayAll();
        cout << endl;
    }
}

int dgraph::findOutDegree(char V) {
    int location = (int) V - 65;
    
    if (location < countUsed && location >= 0){
        return Gtable[location].outDegree;
    }
    cout << "Error: Vertex not found" << endl;
    return 0;
}

void dgraph::visit(int visitNum, char Key){
    int location = (int) Key - 65;
    
    Gtable[location].visit = visitNum;
}

bool dgraph::isMarked(char Key){
    int location = (int) Key - 65;
    
    if (Gtable[location].visit == 0)
        return false;
    else
        return true;
}

slist dgraph::findAdjacency(char V){
    int location = (int) V - 65;
    slist empty;
    
    if (location < countUsed && location >= 0){
        return Gtable[location].adjacentOnes;
    }
    cout << "Error: Vertex not found" << endl;
    return empty;
}
