#include <iostream>
#include <fstream>

#include "Stack.h"
#include "Queue .h"
#include "Data.h"

using namespace std;

int main() {
cout << "Opening programing" << endl;
ifstream getInput;

getInput.open("amazon.csv");

if (!getInput.is_open()){
    cout << "File Amazon.csv could not open" << endl;
    return 1;
}

//reads data from the file up to the end of the file
while (!getInput.eof()){
    Data objFromInput;
    getInput >> objFromInput.year;
    getInput >> objFromInput.state;
    getInput >>objFromInput.month;
    getInput >> objFromInput.numberOfFires;

    Stack NewObjToPush;
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



while (){
    Stack item;
    printOutput << item.pop_head()
}

    return 0;
}