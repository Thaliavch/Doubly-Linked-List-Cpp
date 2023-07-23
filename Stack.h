//File: Stack.h
//Created by Thalia on 7/10/2023.
// Desc: Header file for Stack class template. Includes definitions of the Stack class methods. The Stack class
//is a child of the DoublyLInkedList class. I override some public members from the parent class as private
// in the child class.

#include "DoublyLinkedList.h"

#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H

template<typename T> class Stack: public DoublyLinkedList<T> {

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
    void push(T data);
    T pop();
    T peek();
};

// Member functions definitions
//***************************************************************************
template<typename T>
void Stack<T>::push(T data){
    DoublyLinkedList<T>::insertFront( data );
}

template<typename T>
T Stack<T>::pop(){
    return DoublyLinkedList<T>::removeFront();
}

template<typename T>
T Stack<T>::peek(){
  return DoublyLinkedList<T>::head->data;
}
// **************************************************************************
#endif //MAIN_CPP_STACK_H
