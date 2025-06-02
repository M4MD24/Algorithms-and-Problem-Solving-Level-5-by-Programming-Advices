#include <iostream>

#include "dynamic_array/DynamicArray.h"
using namespace std;

int main() {
    DynamicArray<short> values;

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

    cout << "\n■ Get Item: ";
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
    cout << values.getItem(
        3
    ) << endl;

    cout << "\n■ Reverse:" << endl;
    cout << "Before Reverse Values:" << endl;
    values.printValues();
    cout << "After Reverse Values:" << endl;
    values.reverse();
    values.printValues();

    cout << "\n■ After Delete Item: " << endl;
    values.deleteItem(
        3
    );
    values.printValues();

    cout << "\n■ After Delete First: " << endl;
    values.deleteFirst();
    values.printValues();

    cout << "\n■ After Delete Last: " << endl;
    values.deleteLast();
    values.printValues();

    cout << "\n■ Find Item: " << values.findItem(
        30
    ) << endl;

    cout << "\n■ Delete Item By Value: " << values.deleteItemByValue(
        30
    ) << endl;
    values.printValues();

    cout << "\n■ Insert At: ";
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

    cout << values.insertAt(
        2,
        60
    ) << endl;
    values.printValues();

    cout << "\n■ Insert After: " << values.insertAfter(
        2,
        70
    ) << endl;
    values.printValues();

    cout << "\n■ Insert Before: " << values.insertBefore(
        2,
        80
    ) << endl;
    values.printValues();
}