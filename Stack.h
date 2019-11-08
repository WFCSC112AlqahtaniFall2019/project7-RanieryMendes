#include "LinkedList.h"
//
// Created by Raniery Costa Mendes on 11/7/19.
//

#ifndef PROJECT7_STACK_H
#define PROJECT7_STACK_H
class Stack : public LinkedList{
public:
    Stack();
    void push_head (Data newObj);
    bool pop_head ();

};

#endif //PROJECT7_STACK_H
