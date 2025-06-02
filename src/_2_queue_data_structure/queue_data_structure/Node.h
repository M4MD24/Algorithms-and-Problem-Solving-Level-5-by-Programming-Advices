#pragma once

template <typename type>
class Node {
    type value;
    Node *next = nullptr;

public:
    Node() {}

    Node(
        const type &VALUE
    ) {
        value = VALUE;
    }

    void setValue(
        const type &VALUE
    ) {
        value = VALUE;
    }

    type getValue() {
        return value;
    }

    void setNext(
        Node *next
    ) {
        this->next = next;
    }

    Node *getNext() {
        return next;
    }
};