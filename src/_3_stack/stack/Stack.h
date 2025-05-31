#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class Stack {
    Node<type> *head = nullptr;

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
            head
        );
        head = newNode;
        counter++;
    }

    void printValues() {
        cout << "Values: ";
        Node<type> *current = head;
        while (current) {
            cout << current->getValue() << ' ';
            current = current->getNext();
        }
        cout << endl;
    }

    bool isEmpty() {
        return counter == 0;
    }

    type top() {
        if (!head)
            return type();
        return head->getValue();
    }
};