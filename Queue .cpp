#include "Queue .h"
//

// Created by Raniery Costa Mendes on 11/8/19.
//

Queue ::Queue() {
    Node* cursor = head;

    while (cursor->next != nullptr){
        cursor = cursor->next;
    }
    tail = cursor;
}
void Queue ::enqueue_tail(Data objInserted) {
    Node* newTail = new Node (objInserted, nullptr);

    tail->next = newTail;
    tail = newTail;
}

bool Queue::dequeue_head() {


if(head != nullptr){
   Node  *cursor = head;
   head = head->next;
   cursor->next = nullptr;
   delete cursor;
   return true;
}

else{
    cout << "List is Empty" << endl;
    return false;
}

}



