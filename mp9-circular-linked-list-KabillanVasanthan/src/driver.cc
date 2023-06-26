#include <iostream>

#include "circular-linked-list.hpp"

int main() {
    CircularLinkedList<int> list;
    list.InsertInOrder(5);
    list.InsertInOrder(2);
    list.InsertInOrder(8);
    list.InsertInOrder(1);
    list.InsertInOrder(7);
    CircularLinkedList<int> copy;
    copy = list;
    //list.Reverse();
    std::cout << copy;


}
