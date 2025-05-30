#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class DoublyLinkedList {
    Node<type> *head = nullptr;

public:
    void insertFirst(
        Node<type> *node
    ) {
        if (head != nullptr) {
            head->setPrevious(
                node
            );
            node->setNext(
                head
            );
        }
        head = node;
    }

    void printValues() {
        cout << "Nodes Values: ";
        Node<type> *current = head;
        while (current != nullptr) {
            cout << current->getValue() << ' ';
            current = current->getNext();
        }
        cout << endl;
    }

    void printValuesBackward() {
        cout << "Nodes Values Backward: ";

        Node<type> *current = head;
        while (current && current->getNext())
            current = current->getNext();

        while (current != nullptr) {
            cout << current->getValue() << ' ';
            current = current->getPrevious();
        }
    }

    Node<type> *findNode(
        Node<type> *targetNode
    ) {
        Node<type> *current = head;
        while (current != nullptr) {
            if (current == targetNode)
                return current;
            current = current->getNext();
        }
        return nullptr;
    }

    void insertAfter(
        Node<type> *previousNode,
        Node<type> *node
    ) {
        if (
            Node<type> *nodeFound = findNode(
                previousNode
            );
            nodeFound == nullptr || node == nullptr
        )
            cout << "Can't Insert After." << endl;
        else {
            node->setNext(
                nodeFound->getNext()
            );
            node->setPrevious(
                nodeFound
            );

            if (nodeFound->getNext() != nullptr)
                nodeFound->getNext()->setPrevious(
                    node
                );

            nodeFound->setNext(
                node
            );
        }
    }

    void insertLast(
        Node<type> *node
    ) {
        if (node == nullptr) {
            cout << "Can't Insert Last." << endl;
            return;
        }

        node->setNext(
            nullptr
        );

        if (head == nullptr) {
            node->setPrevious(
                nullptr
            );
            head = node;
        } else {
            Node<type> *current = head;
            while (current->getNext() != nullptr)
                current = current->getNext();
            node->setPrevious(
                current
            );
            current->setNext(
                node
            );
        }
    }

    void deleteNode(
        Node<type> *targetNode
    ) {
        if (
            head == nullptr ||
            targetNode == nullptr
        ) {
            cout << "Can't Delete." << endl;
            return;
        }

        if (head == targetNode) {
            head = head->getNext();
            if (head != nullptr)
                head->setPrevious(
                    nullptr
                );
            return;
        }

        if (
            targetNode->getPrevious() == nullptr &&
            targetNode->getNext() == nullptr
        )
            cout << "Node Not Found." << endl;
        else {
            targetNode->getPrevious()->setNext(
                targetNode->getNext()
            );

            targetNode->getNext()->setPrevious(
                targetNode->getPrevious()
            );
        }
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Can't Delete First." << endl;
            return;
        }

        Node<type> *copyOfHead = head;
        head = head->getNext();

        if (head != nullptr)
            head->setPrevious(
                nullptr
            );

        if (copyOfHead != nullptr)
            copyOfHead->setNext(
                nullptr
            );
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "Can't Delete Last. List is Empty." << endl;
            return;
        }

        if (head->getNext() == nullptr) {
            head = nullptr;
            return;
        }

        Node<type> *current = head;
        while (current->getNext()->getNext() != nullptr)
            current = current->getNext();

        current->getNext()->setPrevious(
            nullptr
        );
        current->setNext(
            nullptr
        );
    }
};