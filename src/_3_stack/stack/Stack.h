#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class Stack {
    Node<type> *top = nullptr;

protected:
    size_t counter = 0;

public:
    void push(
        const type &VALUE
    ) {
        auto *newNode = new Node<type>(
            VALUE
        );
        newNode->setNext(
            top
        );
        top = newNode;
        counter++;
    }
};