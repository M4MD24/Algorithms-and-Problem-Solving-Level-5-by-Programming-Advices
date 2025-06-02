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
            cout << "Index out of range.\n";
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
            cout << "Index out of range.\n";
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

    void deleteItem(
        const size_t &INDEX
    ) {
        if (INDEX >= size) {
            cout << "Index out of range.\n";
            return;
        }
        for (size_t index = INDEX; index < size - 1; ++index)
            originalValues[index] = originalValues[index + 1];
        --size;
    }

    void deleteFirst() {
        if (size == 0) {
            cout << "Can't Delete First.\n";
            return;
        }
        for (size_t index = 0; index < size - 1; ++index)
            originalValues[index] = originalValues[index + 1];
        --size;
    }

    void deleteLast() {
        if (size == 0) {
            cout << "Can't Delete Last.\n";
            return;
        }
        --size;
    }

    size_t findItem(
        const type &ITEM
    ) {
        for (size_t index = 0; index < size; ++index)
            if (originalValues[index] == ITEM)
                return index;
        cout << "Can't Find.\n";
        return type();
    }

    bool deleteItemByValue(
        const type &VALUE
    ) {
        if (
            size_t index = findItem(
                VALUE
            );
            index == type()
        )
            return false;
        else {
            deleteItem(
                index
            );
            return true;
        }
    }

    bool insertAt(
        const size_t &TARGET_INDEX,
        const type &VALUE
    ) {
        if (TARGET_INDEX > size) {
            cout << "Index out of range.\n";
            return false;
        }

        if (size == capacity)
            resize(
                capacity * 2
            );

        for (size_t index = size; index > TARGET_INDEX; --index)
            originalValues[index] = originalValues[index - 1];

        originalValues[TARGET_INDEX] = VALUE;
        ++size;
        return true;
    }

    bool insertAfter(
        const size_t &PREVIOUS_INDEX,
        const type &VALUE
    ) {
        return insertAt(
            PREVIOUS_INDEX + 1,
            VALUE
        );
    }

    bool insertBefore(
        const size_t &NEXT_INDEX,
        const type &VALUE
    ) {
        return insertAt(
            NEXT_INDEX - 1,
            VALUE
        );
    }

    ~DynamicArray() {
        delete[] originalValues;
    }
};