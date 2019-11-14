#include "Queue .h"
//

// Created by Raniery Costa Mendes on 11/8/19.
//

Queue ::Queue() {

   front = nullptr;

   tail = nullptr;
}

void Queue ::enqueue_tail(Data objInserted) {

        Node* temp = new Node(objInserted);
        if(!front){ //case 1: the queue is empty.
            temp->next = nullptr;
            front = tail = temp;
            head = front;

        }

        else { //case 2: the queue has nodes.
            temp->next = tail;
            tail = temp;

        }

    }



bool Queue::dequeue_head() {

    if(!front) {
        //case 1: the queue is empty, do nothing.
        cout << "Called just once" << endl;
    }
    else if(front == tail) { //case 2: the queue has one node.
        Node* t = front;
        front = tail = nullptr;
        delete t;

    }
    else { //case 3: the queue has more than one node.
        Node* t = front;
        Node* s = tail; //crawls the links
        while( s->next != front )
            s = s->next;
        front = s; //update the front of the queue
        s->next = nullptr;
        delete t;

    }
 head = front;
}






