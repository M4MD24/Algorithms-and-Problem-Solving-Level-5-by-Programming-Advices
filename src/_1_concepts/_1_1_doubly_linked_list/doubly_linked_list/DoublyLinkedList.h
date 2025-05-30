#pragma once
#include "Node.h"
using namespace std;

template <typename type>
class DoublyLinkedList {
    Node<type> *head = nullptr;

protected:
    size_t counter = 0;

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
        ++counter;
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

            ++counter;
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

        ++counter;
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
            --counter;

            delete targetNode;
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

            delete targetNode;
            --counter;
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

        delete copyOfHead;
        --counter;
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "Can't Delete Last. List is Empty." << endl;
            return;
        }

        if (head->getNext() == nullptr) {
            delete head;
            head = nullptr;
            --counter;
            return;
        }

        Node<type> *current = head;
        while (current->getNext()->getNext() != nullptr)
            current = current->getNext();

        delete current->getNext();
        current->setNext(
            nullptr
        );

        --counter;
    }

    size_t size() {
        return counter;
    }

    bool isEmpty() {
        return counter == 0;
    }

    void clear() {
        while (counter > 0)
            deleteFirst();
    }

    void reverse() {
        if (
            head == nullptr ||
            head->getNext() == nullptr
        )
            return;

        Node<type> *current = head;
        Node<type> *temporary = nullptr;

        while (current != nullptr) {
            temporary = current->getPrevious();
            current->setPrevious(
                current->getNext()
            );
            current->setNext(
                temporary
            );

            current = current->getPrevious();
        }

        if (temporary != nullptr)
            head = temporary->getPrevious();
    }
};