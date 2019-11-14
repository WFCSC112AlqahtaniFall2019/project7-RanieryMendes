//
// Created by Raniery Costa Mendes on 11/8/19.
//

#ifndef PROJECT7_SORTEDLINKEDLIST_H
#define PROJECT7_SORTEDLINKEDLIST_H

#include "LinkedList.h"

class SortedLinkedList : public LinkedList {

public:

    void  insertionSortII (); //function to sort linked list
    void append( Data item ); //function to insert Data objects, that is, new nodes into the linkedlist
};

#endif //PROJECT7_SORTEDLINKEDLIST_H
