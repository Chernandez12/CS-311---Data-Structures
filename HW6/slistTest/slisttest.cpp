// CS311 Yoshii
// Use this client file to test your slist thoroughly
// before you move onto HW6 to make sure slist is perfect!
// --------------------------------------------------------
#include<iostream>
#include "slist.h"
using namespace std;


slist strange(slist M)
{
    M.addRear(20);
    return M;
}

int main()
{
    slist L;
    
    for (int i = 1; i <= 10; i++)
        L.addRear(i);
    
    cout << "Display 1:" << endl;
    L.displayAll();
    
    int X;
    for (int i = 1; i <= 10; i++)
        L.deleteRear(X);
    
    cout << "Display 2:" << endl;
    L.displayAll();
    
    for (int i = 1; i <= 10; i++)
        L.addFront(i);
    
    cout << "Display 3:" << endl;
    L.displayAll();
    
    for (int i = 1; i <= 10; i++)
        L.deleteFront(X);
   
    cout << "Display 4:" << endl;
    L.displayAll();
    
    for (int i = 1; i <= 10; i++)
        L.addRear(i);
    
    cout << "Display 5:" << endl;
    L.displayAll();
    
    cout << "deleteIth test:" << endl;
    L.deleteIth(1, X);
    L.displayAll();
    L.deleteIth(9, X);
    L.displayAll();
    L.deleteIth(3, X);
    L.displayAll();
    
    cout << "insertIth test:" << endl;
    L.insertIth(1, 0);
    L.displayAll();
    L.insertIth(9, 0);
    L.displayAll();
    L.insertIth(3, 0);
    L.displayAll();
    
    cout << "search test:" << endl;
    for (int i = 1; i <= 10; i++)
        cout << i << " found in postition:" << L.search(i) << endl;
    
    cout << "replace test:" << endl;
    for (int i = 1; i <= 10; i++)
        L.replace(10, i);
    L.displayAll();
    
    slist L2;
    
    L2 = L;
    
    cout << "L2:";
    L2.displayAll();
    
    L = strange(L2);
    
    cout << "L2:";
    L2.displayAll();
    cout << "L:";
    L.displayAll();
    
}  

