// CS311 Yoshii - HW5 Priority Queue Client File
// DO NOT CHANGE!!!!
//------------------------------------------

#include "pqueue.h"

int main()
{
    pqueue Jobs;
    
//    // adding 7 jobs
//    Jobs.insertjob(20);
//    Jobs.insertjob(12);
//    Jobs.displayAll();
//    Jobs.insertjob(30);
//    Jobs.insertjob(1);
//    Jobs.displayAll();
//    Jobs.insertjob(5);
//    Jobs.insertjob(6);
//    Jobs.insertjob(7);
//    Jobs.displayAll();
//
//    // printing 4 jobs
//    Jobs.printjob();
//    Jobs.displayAll();
//    Jobs.printjob();
//    Jobs.displayAll();
//    Jobs.printjob();
//    Jobs.displayAll();
//    Jobs.printjob();
//    Jobs.displayAll();
//
//    // then add 2 more jobs
//    Jobs.insertjob(2);
//    Jobs.displayAll();
//    Jobs.insertjob(3);
//    Jobs.displayAll();
    
    Jobs.insertjob(5);
    Jobs.insertjob(1);
    Jobs.insertjob(8);
    Jobs.insertjob(11);
    
    Jobs.displayAll();
    
    Jobs.printjob();
    Jobs.printjob();
    
    Jobs.insertjob(3);
    Jobs.displayAll();
    Jobs.insertjob(7);
    Jobs.displayAll();
    Jobs.insertjob(2);
    Jobs.displayAll();
    Jobs.insertjob(12);
    Jobs.displayAll();
    Jobs.insertjob(9);
    Jobs.displayAll();
    cout << endl;
    
    while (Jobs.getCount() > 0){
        Jobs.printjob();
        //cout << Jobs.getCount() << endl;
    }
    
}  
