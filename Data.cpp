#include "Data.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
//
// Created by Raniery Costa Mendes on 11/7/19.
//

using namespace std;

bool Data ::operator>(Data objComp) {
    if(this->numberOfFires > objComp.numberOfFires){
        return true;
    }
    else{
        return false;
    }

}



ostream& operator << (ostream &out, const Data& printOutput)
{
    out << "FIRE IN AMAZON - Year: " << printOutput.year << " Month: " << printOutput.month << " State: ";
    out<< printOutput.state << " Number of Fires: " << printOutput.numberOfFires;
    return out;
}
