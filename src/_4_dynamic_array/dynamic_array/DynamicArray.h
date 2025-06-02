#pragma once
#include <iostream>
using namespace std;

template <typename type>
class DynamicArray {
    type *originalValues = nullptr;

protected:
    size_t size = 0;
    size_t capacity = 0;

public:
    DynamicArray(
        const size_t &INITIAL_CAPACITY = 2
    ) {
        capacity = INITIAL_CAPACITY;
        originalValues = new type[capacity];
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
            new_values[index] = originalValues[index];
        delete[] originalValues;
        originalValues = new_values;
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
            originalValues[size++] = VALUE;
        } else
            originalValues[INDEX] = VALUE;
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
            cout << originalValues[index] << ' ';
        cout << endl;
    }

    void shrinkToFit() {
        if (capacity > size)
            resize(
                size
            );
    }

    void clear() {
        size = 0;
        capacity = 2;
        delete[] originalValues;
        originalValues = new type[0];
    }

    type getItem(
        const size_t &INDEX
    ) {
        if (INDEX >= size) {
            cout << "Index out of range\n";
            return type();
        }
        return originalValues[INDEX];
    }

    void reverse() {
        for (size_t index = 0; index < size / 2; ++index)
            swap(
                originalValues[index],
                originalValues[size - 1 - index]
            );
    }

    ~DynamicArray() {
        delete[] originalValues;
    }
};