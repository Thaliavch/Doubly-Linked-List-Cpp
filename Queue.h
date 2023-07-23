//File: Queue.h
//Created by Thalia on 7/10/2023.
// Desc: Header file for Queue class template. Queue class is a child class
// of the DoublyLinkedList class. The file Includes definitions of Queue class methods.
// I override some public members from the parent class as private in the child class.

#ifndef MAIN_CPP_QUEUE_H
#define MAIN_CPP_QUEUE_H

template<typename T> class Queue: public DoublyLinkedList<T>{
private:
    // Override publicMember as private
    using DoublyLinkedList<T>::print;
    using DoublyLinkedList<T>::removeFront;
    using DoublyLinkedList<T>::removeRear;
    using DoublyLinkedList<T>::removeAt;
    using DoublyLinkedList<T>::insertRear;
    using DoublyLinkedList<T>::insertFront;
    using DoublyLinkedList<T>::insertAt;
    using DoublyLinkedList<T>::findIndex;
public:
    using DoublyLinkedList<T>::DoublyLinkedList;
    void enqueue( T data );
    T dequeue( );
    T peek( );
};


// Member Functions Definitions
//**************************************************************
template<typename T>
void Queue<T>::enqueue( T data ){
    DoublyLinkedList<T>::insertRear(data);
}
template<typename T>
T Queue<T>::dequeue( ){
    DoublyLinkedList<T>::removeFront();
}

template<typename T>
T Queue<T>::peek( ){
    return DoublyLinkedList<T>::head->data;
}
//*************************************************************
#endif //MAIN_CPP_QUEUE_H
