// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Carlos Andre Hernandez
// File type:  cpp
// ================================================

#include<iostream>
#include "dgraph.h"
using namespace std;

int main()
{
    char vertex = ' ';
//  0.Declare table object
    dgraph dg;
//  1.fillTable()
    cout << "Filling table.... " << endl;
    dg.fillTable();
//  2.displayGraph()
    cout << "Displaying Graph... " << endl;
    dg.displayGraph();
    
    //  while (the user does not want to stop)
    while (vertex != '1'){
        cout << "Specify Vertex to find Degree and Adjacency: (Enter '1' to quit)" << endl;
        cin >> vertex;
        cout << "Degree: " << dg.findOutDegree(vertex) << endl;
        cout << "Adjecency: " << endl;
        (dg.findAdjacency(vertex)).displayAll();
    }
}
