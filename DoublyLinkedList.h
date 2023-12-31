// File: DoublyLinkedList.h
// Created by Thalia on 7/4/2023.
// Desc: Header file for DoublyLinkedList class template. Definitions of DoublyLinked class methods
// Updates since first submission: *added the tail pointer and updated the methods to use tail pointer instead
// of traversing the list each time. Created class template (template class is an instance of a class template).
// Added a NodeByIndex() method to the class to use in the insertAt() and removeAt() methods. Added a Destructor
// to the class.
#include <iostream>
#ifndef LINKED_LISTS_DOUBLYLINKEDLIST_H
#define LINKED_LISTS_DOUBLYLINKEDLIST_H


template<typename T> class DoublyLinkedList{
protected:
    struct Node{
        T data;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;
    int count;
    // Protected Member Functions
    Node* NodeByIndex(int index);
    Node* GetNewNode(T data);

public:
    //Constructor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Public Member Functions
    void insertFront( T data );
    void insertRear( T data );
    T removeFront();
    T removeRear();
    int size( );
    void makeEmpty();
    void print();
    bool insertAt( T data, int index );
    T removeAt(int index);
    int findIndex( T data );
};


// Methods Definitions
// **************************************************************************

// Private member functions
/**
 * Purpose: Allocate a new Node in memory and initialize it
 * @param data
 * @return Node*
 */
template<typename T>
typename DoublyLinkedList<T>::Node * DoublyLinkedList<T>::GetNewNode(T data){
    Node* newNode = new Node{data, nullptr, nullptr};
    return newNode;
}
/**
 * We traverse the list to find the Node in the given index
 * @param index
 * @return
 */
template<typename T>
typename DoublyLinkedList<T>::Node * DoublyLinkedList<T>::NodeByIndex(int index){
    Node *temp = head;
    for (int i = 0; i < index; i++) {  // traversing until we arrive at the index
        temp = temp->next;
    }
    return temp;
}

//Public Member Functions
/**
 * Purpose: Constructor to initialize list by setting head pointer to null and
 * initialize the count variable that keeps track of the size of the list.
 */
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){ //ask professor why we need to do this
    makeEmpty();
}

/**
 * Description: Insert element at the beginning of the list.
 * @param int
 */
template<typename T>
void DoublyLinkedList<T>::insertFront( T data ){
    Node* temp = GetNewNode(data);
    if (head){
        head->prev = temp;
        temp->next = head;
    } else {
        tail = temp;
    }
    head = temp;
    count++;
}

/**
 * Description: Insert element at the end of the list
 * @param int
 */
template<typename T>
void DoublyLinkedList<T>::insertRear( T data ) {
    Node *temp = GetNewNode(data);
    if (tail) {
        tail->next = temp;
        temp->prev = tail;
    } else {
        head = temp;
    }
    tail = temp;
    count++;
}

/**
 * Description: Removes the first element. We first check if head is not empty to remove
 * an element, and if is empty it will return -1;
 * @return int
 */
template<typename T>
T DoublyLinkedList<T>::removeFront(){

    if (head){
        T deleted_data = head->data;
        Node *temp = head->next;
        delete head;
        head = temp;
        if(count == 1){
            tail = temp;
        }
        count--;
        return deleted_data;
    }
    return -1;
}

/**
 * Description: We check if the head is empty so if it is we just return -1.
 * To remove the last element we enter a while-loop to traverse through the
 * list and find the last one, which occurs when pNode = nullptr after the last iteration
 * of the while loop.
 * @return int
 */
template<typename T>
T DoublyLinkedList<T>::removeRear() {
    Node *temp;
    if (tail) {
        int deleted_data = tail->data;
        temp = tail->prev;  // ****** may cause problem !!!!!!!!!!!!!!!!!!!!!!!
        if (count != 1) {
            temp->next = tail->next;
        } else {
            head = temp;
        }
        delete tail;
        tail = temp;
        count--;
        return deleted_data;
    }
    return -1;
}

/**
 * Returns the size of the list. Note count variable is updated with each function call
 * that modifies the size of the list.
 * @return int
 */
template<typename T>
int DoublyLinkedList<T>::size( ){
    return count;
}

/**
 * Description: Pointer variable temp is used to iterate through each node of the list. We store the current
 * node in pNode pointer before moving the temp variable to the next one and erase pNode pointee.
 */
template<typename T>
void DoublyLinkedList<T>::makeEmpty(){
    Node *temp = head;
    Node *pNode = nullptr;
    while (temp){
        pNode = temp;
        temp = temp->next;
        head = temp;
        delete pNode;
    }
    count = 0;
    return;
}

/**
 * Function used to print the elements of the list (I know if was not included in the specifications of the class
 * but I think it would be nice to include it in the class). We use temp pointer to access the Nodes and output
 * the data they store.
 */
template<typename T>
void DoublyLinkedList<T>::print(){
    Node* temp = head;
    while(temp){
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << "\n";
}

/**
 * Description: It returns false if the index entered does not exist.
 * @param int data
 * @param int index
 * @return bool
 */
template<typename T>
bool DoublyLinkedList<T>::insertAt( T data, int index ){

    if(index >= count || index < 0) { //if index does not exist return false
        return false;
    }else if(!index){
        insertFront(data);
    }else if(index == count-1){
        insertRear(data);
    }else{
        Node *pNode = GetNewNode(data);
        Node *temp = NodeByIndex(index);
        pNode->next = temp; // linking pNode front to temp ;
        pNode->prev = temp->prev; // linking pNode back to the previous node
        temp->prev = pNode; // linking temp back to pNode;
        temp = pNode->prev; //setting pointer temp to point at the node that goes before pNode
        temp->next = pNode; // linking the front of the previous node to pNode;
        count++;
    }
    return true;
}

/**
 * Description: It returns -1 if the index entered does not exist. After we determine if the index is valid
 * we need to check for two special cases, 1: if index is 0, and 2: if the index is the last one of the list
 * because it will change the way we link the pointers in both cases.
 * @param int index
 * @return int
 */
template<typename T>
T DoublyLinkedList<T>::removeAt(int index){
    int deleted_value = -1;
    if(!index){
        removeFront();
    } else if(index == count-1){
        removeRear();
    } else if(index < (count-1) && index > 0){
        Node *pNode = nullptr;
        Node *temp = NodeByIndex(index);
        deleted_value = temp->data;
        pNode = temp->prev; // pNode is now pointing to the previous node;
        pNode->next = temp->next; // now we link the previous node to the one in front of temp
        pNode = temp->next; // since we do not have a previous node we just update the prev property of the next node
        pNode->prev = temp->prev; // basically pNode->prev to nullptr if index is 0;
        delete temp; //now we delete the node temp is pointing to.
        count--;
    }
    return deleted_value;
}

/**
 * Description: If number is not in the list, we return -1
 * @param int data
 * @return
 */
template<typename T>
int DoublyLinkedList<T>::findIndex( T data ){
    Node *temp = head;
    for(int i = 0; i < count; i++){
        if (temp->data == data){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}


#endif //LINKED_LISTS_DOUBLYLINKEDLIST_H
