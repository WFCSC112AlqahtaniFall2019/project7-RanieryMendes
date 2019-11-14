#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "SortedLinkedList.h"
#include "Stack.h"
#include "Queue .h"
#include "Data.h"

using namespace std;




int main() {
    cout << "Opening programing" << endl;

    ifstream getInput;

    getInput.open("amazon.csv");

    if (!getInput.is_open()) {
        cout << "File amazon.csv could not open" << endl;
        return 1;
    }

    getInput.clear();

    Stack NewObjToPush;
//reads data from the file up to the end of the file
    for (int i = 0; i < 10; i++) {
        Data objFromInput;
        //cout << "I am reading data and storing!" << endl;
        getInput.clear();

        getline(getInput, objFromInput.year, ',');
       // cout << "This the year: " << objFromInput.year << endl;
         getInput.clear();
        getline(getInput, objFromInput.state, ',');
         getInput.clear();
        //cout << "This the state: " << objFromInput.state << endl;

        getline(getInput, objFromInput.month, ',');
        //cout << "This the month: " << objFromInput.month << endl;
        getInput.clear();
        // getInput >> objFromInput.numberOfFires;
        getline(getInput, objFromInput.numberOfFires);
       // cout << "This the number: " << objFromInput.numberOfFires << endl;
        getInput.clear();


        NewObjToPush.push_head(objFromInput);
    }
//close file
    getInput.close();

    if (getInput.fail()) {
        cout << "File not Closed. Security Leak" << endl;

    }

    ofstream printOutput;
    cout << "Opening Output File for Stack" << endl;
    printOutput.open("stacked.txt");

    if (!printOutput.is_open()) {
        cout << "Output file not opened" << endl;
        return 1;
    }

    NewObjToPush.print(printOutput);
    for (int i = 0; i < 5; i++){
        cout<< "Printing: ";

       // NewObjToPush.print(printOutput);

         if(printOutput.fail()){
             cout<<"Failed to print";
             return 1;
         }
        //pop out head of the stack
         NewObjToPush.pop_head();
    }

    // closing output file for stack
    printOutput.close();


    ifstream inputForQueue;

    inputForQueue.open("amazon.csv");

    if(!inputForQueue.is_open()){
        cout << "File for Queue is not opened" << endl;

        return 1;
    }


    //FOR QUEUE


    Queue NewQueue;

    for (int i = 0; i < 10; i++) {
        Data objFromInput;
        cout << "I am reading data and storing!" << endl;
        inputForQueue.clear();

        getline(inputForQueue, objFromInput.year, ',');
        cout << "This the year: " << objFromInput.year << endl;

        getline(inputForQueue, objFromInput.state, ',');

        cout << "This the state: " << objFromInput.state << endl;

        getline(inputForQueue, objFromInput.month, ',');
        cout << "This the month: " << objFromInput.month << endl;


        getline(inputForQueue, objFromInput.numberOfFires);
        cout << "This the number: " << objFromInput.numberOfFires << endl;

        inputForQueue.clear();

        NewQueue.enqueue_tail(objFromInput);
    }

    inputForQueue.close();

    ofstream printIntoQueue;

    printIntoQueue.open("queued.txt");

    if (!printIntoQueue.is_open()){
        cout << "File for print Queue is not opened" <<endl;
        return 1;
    }

    for (int i = 0; i< 9; i++){

        cout << "Printing Queue" << endl;

        NewQueue.print(printIntoQueue);

        if(printIntoQueue.fail()){
            cout << "Failed to print into Queue file" <<endl;
            return 1;
        }

        NewQueue.dequeue_head();
    }

    printIntoQueue.close();

    ifstream inputForLinkedList;

    inputForLinkedList.open("amazon.csv");

    cout << "File for Linked List opened" << endl;

    if (!inputForLinkedList.is_open()){
        cout << "File for LinkedList is not opened" <<endl;
        return 1;
    }

    SortedLinkedList NewLinkedList;


    for (int i = 0; i < 40; i++) {
        Data objFromInput;
        cout << "I am reading data and storing!" << endl;
        inputForLinkedList.clear();

        getline(inputForLinkedList, objFromInput.year, ',');
        cout << "This the year: " << objFromInput.year << endl;

        getline(inputForLinkedList, objFromInput.state, ',');

        cout << "This the state: " << objFromInput.state << endl;

        getline(inputForLinkedList, objFromInput.month, ',');
        cout << "This the month: " << objFromInput.month << endl;


        getline(inputForLinkedList, objFromInput.numberOfFires);
        cout << "This the number: " << objFromInput.numberOfFires << endl;

        inputForLinkedList.clear();

        NewLinkedList.append(objFromInput);



    }

    inputForLinkedList.close();

    ofstream printOutputForLinkedList;

    printOutputForLinkedList.open("sorted.txt" );

    if (!printOutputForLinkedList.is_open()){
         cout << "File for print LinkedList output is not opened" << endl;
         return 1;
    }

        NewLinkedList.insertionSortII();
        NewLinkedList.print(printOutputForLinkedList);


    if (printOutputForLinkedList.fail()){
        cout << "Printing Sorted LinkedList failed" << endl;
        return 1;
    }


    printOutputForLinkedList.close();



    return 0;
}