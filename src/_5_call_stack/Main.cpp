#include <iostream>

#include "call_stack/CallStack.h"
using namespace std;

int main() {
    CallStack<string> values;

    values.setValue(
        "First"
    );
    values.setValue(
        "Second"
    );
    values.setValue(
        "Third"
    );

    cout << "Current Value: " << values.getValue() << endl;

    cout << "\nAfter Undo: " << boolalpha << values.undo() << endl;
    cout << "Current Value: " << values.getValue() << endl;

    values.setValue(
        "Four"
    );

    cout << "\nAfter Redo: " << boolalpha << values.redo() << endl;
    cout << "Current Value: " << values.getValue();
}