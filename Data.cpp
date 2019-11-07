#include "Data.h"
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

ostream& Data::operator<<(const Data obj) {
    cout << "FIRE IN AMAZON - Year: " << obj.year << " Month: " << obj.month << " State: ";
    cout<< obj.state << " Number of Fires: " << obj.numberOfFires;

}
