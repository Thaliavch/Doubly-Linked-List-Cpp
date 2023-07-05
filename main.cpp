/**
 * File: main.cpp
 * Author: Thalia Valle Chavez
 * Desc: Doubly Linked List Implementation.
 */
#include <iostream>
#include "DoublyLinkedList.h"


void testing_list(DoublyLinkedList list);

int main() {
    DoublyLinkedList myList;
    testing_list(myList);

    return 0;
}

void testing_list(DoublyLinkedList list){
    int data;
    int index;

    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);

    list.insertRear(100);
    list.insertRear(200);
    list.insertRear(300);

    std::cout << "List: " << "\t";
    list.print();
    std::cout << "Size of the list: " << list.size() << std::endl;

    std::cout << "Removing first number in the list... " << std::endl;
    list.removeFrontInt();
    std::cout << "Removing last number in the list... " << std::endl;
    list.removeRearInt();

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
    }
    std::cout << "Size of the list: " << list.size() << std::endl;

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