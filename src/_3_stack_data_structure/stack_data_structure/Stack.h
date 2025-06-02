#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class Stack {
    Node<type> *head = nullptr;

protected:
    size_t counter = 0;

    Node<type> *findNode(
        const size_t &INDEX
    ) {
        if (INDEX >= counter)
            return nullptr;
        Node<type> *current = head;
        for (size_t index = 0; index < INDEX; ++index)
            current = current->getNext();
        return current;
    }

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

    type bottom() {
        if (!head)
            return type();
        Node<type> *current = head;
        while (current->getNext())
            current = current->getNext();
        return current->getValue();
    }

    void pop() {
        if (head) {
            const Node<type> *TEMPORARY = head;
            head = head->getNext();
            delete TEMPORARY;
            counter--;
        }
    }

    type getItem(
        const size_t &INDEX
    ) {
        if (INDEX >= counter)
            return type();
        return findNode(
            INDEX
        )->getValue();
    }

    void reverse() {
        Node<type> *previous = nullptr,
                   *current = head,
                   *next = nullptr;

        while (current) {
            next = current->getNext();
            current->setNext(
                previous
            );
            previous = current;
            current = next;
        }

        head = previous;
    }

    bool updateItem(
        const size_t &INDEX,
        const type &VALUE
    ) {
        Node<type> *node = findNode(
            INDEX
        );
        if (!node)
            return false;
        node->setValue(
            VALUE
        );
        return true;
    }

    void clear() {
        while (head)
            pop();
        counter = 0;
    }

    void insertLast(
        const type &VALUE
    ) {
        auto *newNode = new Node<type>(
            VALUE
        );
        if (!head)
            head = newNode;
        else {
            Node<type> *current = head;
            while (current->getNext())
                current = current->getNext();
            current->setNext(
                newNode
            );
        }
        counter++;
    }

    bool insertAfter(
        const size_t &INDEX,
        const type &VALUE
    ) {
        Node<type> *targetNode = findNode(
            INDEX
        );
        if (!targetNode)
            return false;
        auto *newNode = new Node<type>(
            VALUE
        );
        newNode->setNext(
            targetNode->getNext()
        );
        targetNode->setNext(
            newNode
        );
        counter++;
        return true;
    }
};