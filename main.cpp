/**
 * File: main.cpp
 * Author: Thalia Valle Chavez
 * Desc: Doubly Linked List Implementation.
 */
#include <iostream>
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"


void testing_list(DoublyLinkedList<char> list);
void testing_stack(Stack<int> stack);
void testing_queue(Queue<int> queue);

// *******************************************************************************
int main() {
    //DoublyLinkedList<char> myList;
    //testing_list(myList);

    //myList.~DoublyLinkedList();

    Stack<int> myStack;
    testing_stack(myStack);

    Queue<int> myQueue;
    testing_queue(myQueue);

    return 0;
}
// ********************************************************************************

void testing_list(DoublyLinkedList<char> list){
    char data;
    int index;

    list.insertFront('A');
    list.insertFront('b');
    list.insertFront('c');

    list.insertRear('d');
    list.insertRear('e');
    list.insertRear('f');

    std::cout << "List: " << "\t";
    list.print();
    std::cout << "Size of the list: " << list.size() << std::endl;

    std::cout << "Removing first number in the list... " << std::endl;
    list.removeFront();
    std::cout << "Removing last number in the list... " << std::endl;
    list.removeRear();

    std::cout << "List: " << "\t";
    list.print();
    std::cout << "Size of the list: " << list.size() << std::endl;


    for (int i = 0; i < 3; i++){
        std::cout << "Which number would you like to insert on the list? ";
        std::cin >> data;
        std::cout << "In which index?";
        std::cin >> index;
        (list.insertAt(data, index)) ? std::cout << "New element inserted at index " << index << std::endl
                                     : std::cout << "Index Not Valid..." << std::endl;
        std::cout << "Size of the list: " << list.size() << std::endl;
    }
    std::cout << "List: " << "\t";
    list.print();
    std::cout << "Size of the list: " << list.size() << std::endl;

    for(int i = 0; i < 2; i++) {
        std::cout << "Insert index of number you want to  remove: ";
        std::cin >> index;
        data = list.removeAt(index);
        if (data == -1) { std::cout << "Index Not Valid " << std::endl; } else {
            std::cout << "We removed number " << data << " from the list. " << std::endl; }
        std::cout << "List: " << "\t";
        list.print();
        std::cout << "Size of the list: " << list.size() << std::endl;
    }


    for(int i = 0; i < 2; i++){
        std::cout << "Which number would you like to find in the list? ";
        std::cin >> data;
        index = list.findIndex(data);
        (index != -1) ? std::cout << "Value " << data << " is in index " << index << std::endl :
        std::cout << "Value is not in the list ):" << std::endl;
    }


    std::cout << "Emptying the list..." << std::endl;
    list.makeEmpty();
    std::cout << "Size of the list: " << list.size() << std::endl;

}

void testing_stack(Stack<int> stack){
    std::cout<< "Testing Stack..." << std::endl;
    int element;

    for(int i = 0; i < 3; i++){
        std::cout << "Enter element in the stack: ";
        std::cin >> element;
        std::cout << "Pushing " << element << " in the stack " << std::endl;
        stack.push(element);
    }

    std::cout<< "Size of Stack: " << stack.size() << std::endl;
    std::cout << "Peeking into the stack \t";
    std::cout << stack.peek() << std::endl;
    for(int i = 0; i < 2; i++){
        std::cout << "Popping an element from the stack" << std::endl;
        stack.pop();
        std::cout << "Peeking into the stack \t";
        std::cout << stack.peek() << std::endl;
    }

    std::cout<< "Size of Stack: " << stack.size() << std::endl;
    stack.makeEmpty();

}

void testing_queue(Queue<int> queue){
    int data;
    std::cout<< "Testing Queue..." << std::endl;


    for(int i = 0; i < 3; i++){
        std::cout << "Enter number in the queue: ";
        std::cin >> data;
        std::cout << "Pushing " << data << " in the queue " << std::endl;
        queue.enqueue(data);
    }
    std::cout<< "Size of Queue: " << queue.size() << std::endl;
    std::cout << "Peeking into the queue \t";
    std::cout << queue.peek() << std::endl;
    for(int i = 0; i < 2; i++){
        std::cout << "Dequeue an element from the queue" << std::endl;
        queue.dequeue();
        std::cout << "Peeking into the queue \t";
        std::cout << queue.peek() << std::endl;
    }

    std::cout<< "Size of Queue: " << queue.size() << std::endl;
    queue.makeEmpty();
}