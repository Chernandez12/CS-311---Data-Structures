#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do.
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Carlos Andre Hernandez
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r){
    int beg = f;    // pointer from the left
    int end = r;    // pointer from the right
    int temp;       // Placeholder Value

   // loop for finding out of place pairs and swap them
    while (beg <= end){ 
        while (a[beg] < pivot)      // Loop for moving beginnning location further
            beg++;
        while (a[end] > pivot)      // Loop for moving end location closer to pivot
            end--;
        if (beg <= end){            // Swap condition
            temp =  a[beg];
            a[beg] = a[end];
            a[end] = temp;
            beg++;
            end--;
        }
    }
  // return the partition point where
  // those smaller than pivot are before what is returned
    return beg;
}

int main(){
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
    
  for (int i = 0; i < x; i++){
      cin >> nums[i];
  }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;
}
