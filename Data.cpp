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


void Data::operator<<(ostream &out) {

    out << "FIRE IN AMAZON - Year: " << this->year << " Month: " << this->month << " State: ";
    out << this->state << " Number of Fires: " << this->numberOfFires;

}


