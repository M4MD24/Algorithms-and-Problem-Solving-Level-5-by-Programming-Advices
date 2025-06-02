#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class Queue {
    Node<type> *head = nullptr;
    Node<type> *tail = nullptr;

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

    type getItem(
        const size_t &INDEX
    ) {
        Node<type> *current = findNode(
            INDEX
        );

        return current != nullptr
                   ? current->getValue()
                   : type();
    }

    bool updateItem(
        const size_t &INDEX,
        const type &NEW_VALUE
    ) {
        if (
            Node<type> *current = findNode(
                INDEX
            )
        ) {
            current->setValue(
                NEW_VALUE
            );
            return true;
        }
        return false;
    }

    void reverse() {
        if (
            !head ||
            !head->getNext()
        )
            return;

        Node<type> *previous = nullptr;
        Node<type> *current = head;
        Node<type> *next = nullptr;
        tail = head;

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

    void clear() {
        while (head) {
            const Node<type> *TEMPORARY = head;
            head = head->getNext();
            delete TEMPORARY;
        }
        tail = nullptr;
        counter = 0;
    }

    void insertFirst(
        const type &VALUE
    ) {
        auto *newNode = new Node<type>(
            VALUE
        );
        newNode->setNext(
            head
        );
        head = newNode;
        if (!tail)
            tail = newNode;
        counter++;
    }

    bool insertAfter(
        const size_t &INDEX,
        const type &VALUE
    ) {
        Node<type> *current = findNode(
            INDEX
        );
        if (!current)
            return false;

        auto *newNode = new Node<type>(
            VALUE
        );
        newNode->setNext(
            current->getNext()
        );
        current->setNext(
            newNode
        );
        if (current == tail)
            tail = newNode;
        counter++;
        return true;
    }
};