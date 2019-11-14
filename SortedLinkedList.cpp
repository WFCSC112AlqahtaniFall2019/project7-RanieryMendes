#include "SortedLinkedList.h"
//
// Created by Raniery Costa Mendes on 11/8/19.
//

void SortedLinkedList :: insertionSortII () {


    // create a new node to iterate through the list
    Node *GOD = new Node( head);
    // set GOD pointer to point to the head of the (unsorted) linked list
    //Pointer God is the sorted part of the list
    //GOD->next = head;

    Node *previous = GOD, *current = head;

// while (outter) loop to iterate through the
    while (current != nullptr) {
        // if statement for 2 conditions
        // 1st if current next is not null and 2nd if the next node's data (number of Fires) is larger than the current node's data number of Fires)
        // if both conditions are met, the if statement executes
        if ((current->next) && (current->next->data < current->data)) {

            //using the conditions from the if statement above set a while loop to iterate through the sorted list until
            // it reaches its right location. It occurs either when previous->next is null which means it will become the last node of the linked list
            // because it is the larger value or because it find the location between its prior lower and next higher values.
            while ((previous->next) && (previous->next->data < current->next->data)) {

                previous = previous->next;
            }
            // allocate a temp node to store the
            Node *temp = previous->next;
            // makes the previous pointer stops pointing to its next pointer (current), so it starts to point to current next. So
            previous->next = current->next;
            current->next = current->next->next;

            previous->next->next = temp;
            // sets the previous as GOD
            previous =  GOD->next;// sets
            current = previous->next;

        }
            // if the node did not find the right location keep iterating
        else {
            current = current->next;
        }
    }
}

void SortedLinkedList :: append( Data item ) {

    //case it is inserting to an empty list
    if (head == nullptr) {
        head = new Node(item);
    }

        //insert at the head or after it

    else {
        Node *curr = head;
        while (curr ->next != nullptr) {
            curr = curr->next;
        }

        curr ->next = new Node (item, nullptr);

    }
}

