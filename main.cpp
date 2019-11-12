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

getInput.open("firetest.csv");

if (!getInput.is_open()){
    cout << "File amazon.csv could not open" << endl;
    return 1;
}
    Data objFromInput;

    Stack NewObjToPush;
//reads data from the file up to the end of the file
for(int i = 0; i< 20; i++){

    cout<< "I am reading data and storing!" <<endl;
    getInput.clear();

    getline(getInput, objFromInput.year);
    cout<< "This the year: " << objFromInput.year <<endl;
    getInput.clear();
    getline(getInput, objFromInput.state);
    getInput.clear();
    cout<< "This the state: " << objFromInput.state <<endl;
    getline(getInput, objFromInput.month);
    cout<< "This the month: " << objFromInput.month <<endl;
    getInput.clear();
    // getInput >> objFromInput.numberOfFires;
    getline(getInput, objFromInput.numberOfFires);
    cout<< "This the number: " << objFromInput.numberOfFires <<endl;
    getInput.clear();




    NewObjToPush.push_head(objFromInput);
}
//close file
    getInput.close();
if(getInput.fail()){
    cout <<"File not Closed. Security Leak" << endl;

}
ofstream printOutput;

printOutput.open("stacked.txt");
if (!printOutput.is_open()){
    cout << "Output file not opened" << endl;
    return 1;
}


    for (int i = 0; i < 100; ++i) {

    Stack item;
    printOutput << NewObjToPush.pop_head();
}

    return 0;
}