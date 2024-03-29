/* Class: LinkedList
 * Description: Very basic singly linked List class with single head 
 * class for use with Data object. It is meant to be inherited for
 * more complex linked lists.
 */

#include "LinkedList.h"
#include "Stack.h"
#include <fstream>
#include <iostream>

using namespace std;


//constructor for Node with Data object and Pointer parameters
Node ::Node(const Data &d, Node *n) {
    data = d;
    next = n;
};

//constructor for node with just Data object parameter
Node ::Node(const Data &d) {
    data = d;
}

//constructor for node with just pointer parameter
Node ::Node(Node *n) {
    next = n;
}



LinkedList::LinkedList() {
    head = nullptr; // empty list
}

// copy constructor
LinkedList::LinkedList(const LinkedList& list) {
    // if list is not empty, perform deep copy
    if(list.head) {
        Node *curr, *listcurr;
        // copy head node data
        head = curr = new Node(list.head->data,head->next);
        listcurr = list.head->next;
        // loop over rest of nodes, copying data
        while (listcurr != nullptr) {
            curr = curr->next = new Node(listcurr->data, nullptr);
            listcurr = listcurr->next;
            //cout <<"Head is not null"<<endl;
        }
    } else {
       // cout << "head is null" <<endl;
        // if list is empty, create another empty list
        head = nullptr;
    }
}

// assignment operator (use copy and swap)
const LinkedList& LinkedList::operator=(LinkedList rhs) {
    swap(head,rhs.head);
    return *this;
}

void LinkedList::print(ostream &os) {
    // start at the head of the list
    Node *curr = head;

    while (curr != nullptr) {


         os << curr->data; // use overloaded output operator to print
         curr = curr->next; // go to next node in list

    }
}

void LinkedList::pop_head() {
    // if not an empty list
    if (head != nullptr) {
        // save location of where head points
        Node *curr = new Node (this->head->data,head);
        // head points to next node
        head = head->next;
        // delete node where head originally pointed
        delete curr;
    }
}
LinkedList::~LinkedList() {
    // keep popping until empty list
    while (head != nullptr) {
        pop_head();
    }
}

void LinkedList :: append( Data d) {

    //case it is inserting to an empty list
    if (head == nullptr) {
        head = new Node(d);
    }

        //insert at the head or after it

    else {
        Node *curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr ->next = new Node (d);

    }
}

