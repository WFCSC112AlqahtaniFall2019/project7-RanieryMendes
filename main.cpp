#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "SortedLinkedList.h"
#include "Stack.h"
#include "Queue .h"
#include "Data.h"

using namespace std;

int main() {

    cout << "Opening program" << endl;

    // file to get input for Stack

    ifstream getInput;

    cout << "Opening file for Stack" << endl;

    //open file
    getInput.open("amazon.csv");

    // check if file was properly opened

    if (!getInput.is_open()) {
        cout << "File amazon.csv could not open" << endl;
        return 1;
    }

    //clear the ifstream just for precautions
    getInput.clear();


    //create object for Stack
    Stack NewObjToPush;

    // for loop to read data from the file up to the end of the file
    for (int i=0; i< 6434; i++) {
        Data objFromInput;

        //clear ifstream object for stack and do it again after each input that is taken in
        getInput.clear();

        //get data about year
        getline(getInput, objFromInput.year, ',');
        getInput.clear();

        //get data about state
        getline(getInput, objFromInput.state, ',');
        getInput.clear();

        //get data about month
        getline(getInput, objFromInput.month, ',');
        getInput.clear();

        //get data about Number of Fires
        getline(getInput, objFromInput.numberOfFires);
        getInput.clear();


        //push into the top of the stack the new data got from the csv file
        NewObjToPush.push_head(objFromInput);
    }

    //close file
    getInput.close();

    //check if file was properly closed
    if (getInput.fail()) {
        cout << "File not Closed. Security Leak" << endl;

    }

    //create fstream object for print output from the stack
    ofstream printOutput;


    //open file for print output
    printOutput.open("stacked.txt");

    //check if it was properly opened
    if (!printOutput.is_open()) {
        cout << "Output file not opened" << endl;
        return 1;
    }

    cout << "Printing data from Stack" <<endl;
    // print the data from stack
    NewObjToPush.print(printOutput);

    //check it failed to print
    if(printOutput.fail()){
        cout<<"Failed to print";
        return 1;
    }


    // for loop to  pop all the elements from  the stack
    for (int i = 0; i < 6434; i++){


        //pop out top of the stack
         NewObjToPush.pop_head();
    }

    // close output file for stack
    printOutput.close();


    //QUEUE SECTION IN MAIN

    cout << "Opening file for Queue" << endl;
    // create fstream object to get input to store into a queue
    ifstream inputForQueue;

    //open file to get input data
    inputForQueue.open("amazon.csv");

    //check if file was properly opened
    if(!inputForQueue.is_open()){
        cout << "File for Queue is not opened" << endl;

        return 1;
    }


    //create Queue object to store the data taken in as input
    Queue NewQueue;

    //for loop to
    for (int i = 0; i < 6434; i++) {
        Data objFromInput;

        //clear input object
        inputForQueue.clear();

        getline(inputForQueue, objFromInput.year, ',');

        getline(inputForQueue, objFromInput.state, ',');


        getline(inputForQueue, objFromInput.month, ',');


        getline(inputForQueue, objFromInput.numberOfFires);

        //clear input object
        inputForQueue.clear();

        //enqueue data  at the tail  of the queue
        NewQueue.enqueue_tail(objFromInput);
    }

    //close file
    inputForQueue.close();

    //create fstream object to print output from queue
    ofstream printIntoQueue;

    //open file
    printIntoQueue.open("queued.txt");

    //check if it is properly opened
    if (!printIntoQueue.is_open()){
        cout << "File for print Queue is not opened" <<endl;
        return 1;
    }

    cout << "Printing data from Queue" << endl;
    for (int i = 0; i< 6434; i++){

        // print data at the front of the queue
        NewQueue.print(printIntoQueue);

        //check if printed correctly
        if(printIntoQueue.fail()){
            cout << "Failed to print into Queue file" <<endl;
            return 1;
        }

        //dequeue element from queue
        NewQueue.dequeue_head();
    }

    //close output file for queue
    printIntoQueue.close();

    //LINKED LIST SECTION

    //create fstream  object to get input for link list
    ifstream inputForLinkedList;

    //open file
    inputForLinkedList.open("amazon.csv");

    cout << "File for Linked List opened" << endl;

    //check if file was properly opened
    if (!inputForLinkedList.is_open()){
        cout << "File for LinkedList is not opened" <<endl;
        return 1;
    }

    //create SortedLinkedList object to store data into nodes and conseuqently into the list
    SortedLinkedList NewLinkedList;



    for (int i = 0; i < 6434; i++) {
        //create Data object to be stored into the LinkedList
        Data objFromInput;

        // clear ifstream object
        inputForLinkedList.clear();


        // get data about year
        getline(inputForLinkedList, objFromInput.year, ',');

        //get data about state
        getline(inputForLinkedList, objFromInput.state, ',');


        //get data about month
        getline(inputForLinkedList, objFromInput.month, ',');


        // get data about the number of fires
        getline(inputForLinkedList, objFromInput.numberOfFires);

        // clear ifstream object
        inputForLinkedList.clear();

        //store data at the linkedlist
        NewLinkedList.append(objFromInput);



    }

    //close file for LinkedList
    inputForLinkedList.close();

    //create fstream object to print data stored in LinkedList
    ofstream printOutputForLinkedList;

    //open file
    printOutputForLinkedList.open("sorted.txt" );

    //checl if file was properly opened
    if (!printOutputForLinkedList.is_open()){
         cout << "File for print LinkedList output is not opened" << endl;
         return 1;
    }

    // sort the linkedlist in terms of number of fires
        NewLinkedList.insertionSortII();

    cout << "Printing LinkedList data into sorted.txt" << endl;
    //print the linkedlist sorted
        NewLinkedList.print(printOutputForLinkedList);


        //check if the object failed to print the data into the .txt file
    if (printOutputForLinkedList.fail()){
        cout << "Printing Sorted LinkedList failed" << endl;
        return 1;
    }


    //close file
    printOutputForLinkedList.close();

    //end program

    return 0;
}