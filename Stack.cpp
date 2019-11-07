#include "Stack.h"

//
// Created by Raniery Costa Mendes on 11/7/19.
//
Stack::Stack() {

}

void Stack ::push_head(Data newObj) {
    Node* newHead = (newObj, head);
    head = newHead;

}

bool Stack ::pop_head() {
    if (head == nullptr){
        cout << "Empty List" << endl;
        return  false;

    }

    else{

        Node* previousHead = head;
        head = head->next;
        delete previousHead;
        return true;
    }

}
