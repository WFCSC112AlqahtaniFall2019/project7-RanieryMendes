#include "Stack.h"

//
// Created by Raniery Costa Mendes on 11/7/19.
//

// default constructor for stack object
Stack::Stack() {
    top = head;
}


//function to add new Data obj at the thead of the stack
void Stack ::push_head(Data newObj) {
    //create new node with Data obj to store into the stack
    Node* newHead = new Node (newObj, head);
    //set the newly created Node as the new head/top of the stack
    head = newHead;

}

//function to pop the head of the stack
bool Stack ::pop_head() {


    //case 1: list is empty
    if (head == nullptr){
        cout << "Empty List" << endl;
        return  false;

    }

    //case 2: list is not empty so pop the head and reassign the head to next elemet
    else{

        //track previous head to be deleted later
        Node* previousHead = head;
        //update head
        head = head->next;
        // assign null to carry out deletion
        previousHead->next = nullptr;
        //delete the head = pop head
        delete previousHead;
        return true;
    }

}
