#pragma once
#include <iostream>
using namespace std;

template <typename type>
class DynamicArray {
    type *values = nullptr;

protected:
    size_t size = 0;
    size_t capacity = 0;

public:
    DynamicArray(
        const size_t &INITIAL_CAPACITY = 2
    ) {
        capacity = INITIAL_CAPACITY;
        values = new type[capacity];
        size = 0;
    }

    void resize(
        const size_t &NEW_CAPACITY
    ) {
        if (NEW_CAPACITY == capacity)
            return;
        if (NEW_CAPACITY < capacity)
            size = NEW_CAPACITY;

        type *new_values = new type[NEW_CAPACITY];
        for (size_t index = 0; index < size; ++index)
            new_values[index] = values[index];
        delete[] values;
        values = new_values;
        capacity = NEW_CAPACITY;
    }

    void setItem(
        const size_t &INDEX,
        const type &VALUE
    ) {
        if (INDEX > size) {
            cout << "Index out of range\n";
            return;
        }
        if (INDEX == size) {
            if (size == capacity)
                resize(
                    capacity * 2
                );
            values[size++] = VALUE;
        } else
            values[INDEX] = VALUE;
    }

    bool isEmpty() {
        return size == 0;
    }

    size_t getSize() {
        return size;
    }

    size_t getCapacity() {
        return capacity;
    }

    void printValues() {
        cout << "Values: ";
        for (size_t index = 0; index < size; ++index)
            cout << values[index] << ' ';
        cout << endl;
    }

    void shrinkToFit() {
        if (capacity > size)
            resize(
                size
            );
    }

    ~DynamicArray() {
        delete[] values;
    }
};