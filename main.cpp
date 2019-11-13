#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "SortedLinkedList.h"
#include "Stack.h"
#include "Queue .h"
#include "Data.h"

using namespace std;

ostream & operator << (ostream &out, const Data& printOutput)
{
    out << "FIRE IN AMAZON - Year: " << printOutput.year << " Month: " << printOutput.month << " State: ";
    out<< printOutput.state << " Number of Fires: " << printOutput.numberOfFires;

}


int main() {
    cout << "Opening programing" << endl;

    ifstream getInput;

    getInput.open("amazon.csv");

    if (!getInput.is_open()) {
        cout << "File amazon.csv could not open" << endl;
        return 1;
    }


    Stack NewObjToPush;
//reads data from the file up to the end of the file
    for (int i = 0; i < 6434; i++) {
        Data objFromInput;
        cout << "I am reading data and storing!" << endl;
        getInput.clear();

        getline(getInput, objFromInput.year, ',');
        cout << "This the year: " << objFromInput.year << endl;
        getInput.clear();
        getline(getInput, objFromInput.state, ',');
        getInput.clear();
        cout << "This the state: " << objFromInput.state << endl;

        getline(getInput, objFromInput.month, ',');
        cout << "This the month: " << objFromInput.month << endl;
        getInput.clear();
        // getInput >> objFromInput.numberOfFires;
        getline(getInput, objFromInput.numberOfFires);
        cout << "This the number: " << objFromInput.numberOfFires << endl;
        getInput.clear();


        NewObjToPush.push_head(objFromInput);
    }
//close file
    getInput.close();

    if (getInput.fail()) {
        cout << "File not Closed. Security Leak" << endl;

    }

    ofstream printOutput;
    cout << "Opening Output File" << endl;
    printOutput.open("/Users/ranierymendes/CLionProjects/project7-RanieryMendes2/stacked.txt");

    if (!printOutput.is_open()) {
        cout << "Output file not opened" << endl;
        return 1;
    }



    for (int i = 0; i < 6000; i++){
        cout<< "Printing   ";

         NewObjToPush.print(printOutput);
         if(printOutput.fail()){
             cout<<"Failed to print";
             return 1;
         }

         NewObjToPush.pop_head();
    }


    printOutput.close();


    return 0;
}