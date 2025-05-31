#include <iostream>
#include "stack/Stack.h"
using namespace std;

int main() {
    Stack<short> values;

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
}