//
// Created by Raniery Costa Mendes on 11/7/19.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H
class Data {
    //Class to deal with dataset about Fires in Amazon Rain forest
public:
    // items from dataset: year	state	month	number of fires date
    string year;
    string month;
    string state;
    string numberOfFires;
    ostream& operator<< ( Data obj);
    bool operator> (Data objComp);



};

#endif //PROJECT7_DATA_H
