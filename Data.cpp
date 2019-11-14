#include "Data.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
//
// Created by Raniery Costa Mendes on 11/7/19.
//

using namespace std;

//function to compare the variable Number of Fires in the Amazon Rain Forest

bool Data ::operator < (Data objComp) {
    // check if the first element is less than the second one.
    if(this->numberOfFires < objComp.numberOfFires){
        return true;
    }
    //if the first data object is  larger than the second, return false
    else{
        return false;
    }

}


// overload output operator to print the data into the files
ostream& operator << (ostream &out, const Data& printOutput)
{
    out << "FIRE IN AMAZON - Year: " << printOutput.year << " Month: " << printOutput.month << " State: ";
    out<< printOutput.state << " Number of Fires: " << printOutput.numberOfFires;
    return out;
}
