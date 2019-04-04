//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Carlos Andre Hernandez 
// File type: client hw7client.cpp 
//==========================================

// Be sure to include dgraph, slist and stack

#include <iostream>
#include "dgraph.h"

using namespace std;
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
    // use the algorithm (read carefully) in the HW7
    // assignment sheet
    
    char vertex = ' ';
    //  0.Declare table object
    dgraph dg;
    stack s;
    //  1.fillTable()
    cout << "Filling table.... " << endl;
    dg.fillTable();
    //  2.displayGraph()
    cout << "Displaying Graph... " << endl;
    dg.displayGraph();
    
    int visitNum = 1;
    slist sl;
    s.push('A');
    
    while (!s.isEmpty()){
        s.pop(vertex);
        cout << "Removed " << vertex << " from stack." << endl;
        
        if (!dg.isMarked(vertex)){
            dg.visit(visitNum, vertex);
            cout << "Visit: " << visitNum << endl;
            visitNum++;
            
            // Get Vertex adjecency list
            if (dg.findOutDegree(vertex) == 0)
                cout << "DEADEND REACHED: BACKUP" << endl;
            else
                sl = dg.findAdjacency(vertex);
            
            while (!sl.isEmpty()) {
                sl.deleteRear(vertex);
                
                cout << "Pushing " << vertex << endl;
                s.push(vertex);
            }
            cout << endl;

        }
        else {
            cout << vertex << " has been visited already" << endl;
            cout << "Current Stack:" << endl;
            s.displayAll();
            cout << endl;
        }
    }
    dg.displayGraph();
}
