using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Carlos Andre Hernandez
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
    int ia = 0;                     // index for A
    int ib = 0;                     // index for B
    int ir = 0;                     // index for R
    
    while (ia < A.size() && ib < B.size()) {
        if (A[ia] < B[ib]) {        // get the A element
            R[ir] = A[ia];
            ia++;
        } else {
            R[ir] = B[ib];
            ib++;                   // get the B element
        }
    cout << "comparison" << endl;
    ir++;
    }
    
    if (ia < A.size()){              // If you still have A elements left, copy them into R
        while (ia < A.size()){
            R[ir] = A[ia];
            ia++;
            ir++;
        }
    } else {                          // copy the remaining B elements into R
        while (ib < B.size()){
            R[ir] = B[ib];
            ib++;
            ir++;
        }
    }
}

int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  
    L3.resize(2*N);                 // Resizing R vector

  // call combine here to combine L1 and L2 into L3
    combine(L1,L2,L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
