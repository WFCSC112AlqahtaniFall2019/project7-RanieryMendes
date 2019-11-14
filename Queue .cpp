#include "Queue .h"
//

// Created by Raniery Costa Mendes on 11/8/19.
//

//queue default constructor
//assign both the front and tail of the queue as null
Queue ::Queue() {

   front = nullptr;

   tail = nullptr;
}

void Queue ::enqueue_tail(Data objInserted) {


        Node* temp = new Node(objInserted); // create new node with Data object taken as parameter. Do not set pointer next until
        // it finds what is the case it falls into

        //case 1: the queue is empty
        if(!front){
            //assign newly created node's pointer next as null
            temp->next = nullptr;
            // front and tail are the same node
            front = tail = temp;
            //update head
            head = front;

        }

        //case 2: the queue has more than one node
        else {
            //assign newly created node's pointer next points to the tail
            temp->next = tail;
            //update tail as Node temp
            tail = temp;

        }

    }



bool Queue::dequeue_head() {
    //case 1: the queue is empty
    if(!front) {
        //do nothing
    }
    //case 2: the queue has just one node
    else if(front == tail) {

        Node* t = front;
        //assign tail and front as null to delete them

        front = tail = nullptr;

        //delete the single node, dequeueing the queue
        delete t;

    }

    //case 3: the queue has more than one node so
    else {
        Node* t = front;// trace the front
        Node* s = tail; //trace the tail

        while( s->next != front ){
            s = s->next;}

        front = s; //update the front of the queue
        s->next = nullptr; // set as null to delete
        //delete t, dequeueing the queue
        delete t;

    }
    //update the head with the front of the queue
 head = front;
}






