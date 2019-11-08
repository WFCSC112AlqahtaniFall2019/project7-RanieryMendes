//
// Created by Raniery Costa Mendes on 11/8/19.
//

#ifndef PROJECT7_QUEUE_H
#define PROJECT7_QUEUE_H

#include "LinkedList.h"

class Queue : public LinkedList{

public:
    Queue();
    void enqueue_tail(Data objInserted);
    bool dequeue_head ();


private:
    Node* tail;


};

#endif //PROJECT7_QUEUE_H
