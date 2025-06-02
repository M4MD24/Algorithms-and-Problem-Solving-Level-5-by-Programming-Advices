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
}