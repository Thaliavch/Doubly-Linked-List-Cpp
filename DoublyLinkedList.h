// File: DoublyLinkedList.h
// Created by Thalia on 7/4/2023.
// Desc: Header file for DoublyLinkedList class
#include <iostream>
#ifndef LINKED_LISTS_DOUBLYLINKEDLIST_H
#define LINKED_LISTS_DOUBLYLINKEDLIST_H

// New updates, will create a tail node that will be allways updated to point to the tail, and
// a private member function to traverse throught the list.

class DoublyLinkedList{

private:
    struct Node{
        int data;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;
    int count;
    // Private member functions
    Node* GetNewNode(int data);
    Node* NodeByIndex(int index);

public:
    //Constructor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Public Member Functions
    void insertFront( int data );
    void insertRear( int data );
    int removeFrontInt();
    int removeRearInt();
    int size( );
    void makeEmpty();
    void print();
    bool insertAt( int data, int index );
    int removeAt(int index);
    int findIndex( int data );
};


#endif //LINKED_LISTS_DOUBLYLINKEDLIST_H

