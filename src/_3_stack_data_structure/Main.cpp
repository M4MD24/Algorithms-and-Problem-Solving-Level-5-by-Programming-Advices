#include <iostream>
#include "stack_data_structure/Stack.h"
using namespace std;

int main() {
    Stack<short> values;

    cout << "■ After Push:" << endl;
    values.push(
        10
    );
    values.push(
        20
    );
    values.push(
        30
    );
    values.push(
        40
    );
    values.push(
        50
    );
    values.printValues();

    cout << "\n■ Is Empty?\n" << boolalpha << values.isEmpty() << endl;

    cout << "\n■ Top = " << values.top() << endl;

    cout << "\n■ Bottom = " << values.bottom() << endl;

    cout << "\n■ After Pop:" << endl;
    values.pop();
    values.printValues();

    cout << "\n■ Get Item: " <<
        values.getItem(
            2
        ) << endl;

    cout << "\n■ After Reverse:" << endl;
    values.reverse();
    values.printValues();

    cout << "\n■ After Update Item:" << endl << boolalpha << values.updateItem(
        1,
        22
    ) << endl;
    values.printValues();

    cout << "\n■ After Clear:" << endl;
    values.clear();
    values.printValues();

    cout << "\n■ After Insert Last:" << endl;
    values.insertLast(
        10
    );
    values.insertLast(
        20
    );
    values.insertLast(
        30
    );
    values.insertLast(
        40
    );
    values.insertLast(
        50
    );
    values.printValues();

    cout << "\n■ After Insert After:" << endl << values.insertAfter(
        4,
        666
    ) << endl;
    values.printValues();
}