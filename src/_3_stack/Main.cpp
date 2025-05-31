#include <iostream>
#include "stack/Stack.h"
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
}