#pragma once
#include <stack>

using namespace std;

template <typename type>
class CallStack {
    stack<type> undoValues,
                redoValues;
    type value = type();

public:
    void setValue(
        const type &VALUE
    ) {
        if (value != VALUE) {
            undoValues.push(
                value
            );
            value = VALUE;
            while (!redoValues.empty())
                redoValues.pop();
        }
    }

    type getValue() {
        return value;
    }

    bool undo() {
        if (!undoValues.empty()) {
            redoValues.push(
                value
            );
            value = undoValues.top();
            undoValues.pop();
            return true;
        }
        return false;
    }
};