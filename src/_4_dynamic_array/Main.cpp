#include <iostream>

#include "dynamic_array/DynamicArray.h"
using namespace std;

int main() {
    DynamicArray<short> values;
    values.printValues();

    cout << "■ After Set Items:" << endl;
    values.setItem(
        0,
        10
    );
    values.setItem(
        1,
        20
    );
    values.setItem(
        2,
        30
    );
    values.setItem(
        3,
        40
    );
    values.setItem(
        4,
        50
    );
    values.printValues();

    cout << "\n■ Get Size: " << values.getSize() << endl;

    cout << "\n■ Get Capacity: " << values.getCapacity() << endl;

    cout << "\n■ After Shrink to Fit:" << endl;
    values.shrinkToFit();
    cout << "Get Capacity: " << values.getCapacity() << endl;

    cout << "\n■ Is Empty: " << boolalpha << values.isEmpty() << endl;

    cout << "\n■ After Resize: " << endl;
    values.resize(
        3
    );
    values.printValues();

    cout << "\n■ After Clear:" << endl;
    values.clear();
    values.printValues();
}