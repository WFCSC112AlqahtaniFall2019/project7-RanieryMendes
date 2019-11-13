#include "Stack.h"

//
// Created by Raniery Costa Mendes on 11/7/19.
//
Stack::Stack() {
    top = head;
}

void Stack ::push_head(Data newObj) {
    Node* newHead = new Node (newObj, top);
    top = newHead;

}

bool Stack ::pop_head() {
    if (top == nullptr){
        cout << "Empty List" << endl;
        return  false;

    }

    else{

        Node* previousHead = top;
        top = top->next;
        previousHead->next = nullptr;
        delete previousHead;
        return true;
    }

}
