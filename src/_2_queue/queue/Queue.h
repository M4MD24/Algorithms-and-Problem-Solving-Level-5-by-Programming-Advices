#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class Queue {
    Node<type> *head = nullptr;
    Node<type> *tail = nullptr;

protected:
    size_t counter = 0;

public:
    void enqueue(
        const type &VALUE
    ) {
        if (
            auto *newNode = new Node<type>(
                VALUE
            );
            !tail
        )
            head = tail = newNode;
        else {
            tail->setNext(
                newNode
            );
            tail = newNode;
        }
        counter++;
    }

    void dequeue() {
        if (!head)
            return;
        const Node<type> *TEMPORARY = head;
        head = head->getNext();
        if (!head)
            tail = nullptr;
        delete TEMPORARY;
        counter--;
    }

    size_t size() {
        return counter;
    }

    type front() {
        if (!head)
            return type();
        return head->getValue();
    }

    type rear() {
        if (!tail)
            return type();
        return tail->getValue();
    }

    void printValues() {
        cout << "Values: ";
        Node<type> *temporary = head;
        while (temporary) {
            cout << temporary->getValue() << ' ';
            temporary = temporary->getNext();
        }
        cout << endl;
    }

    bool isEmpty() {
        return counter == 0;
    }
};