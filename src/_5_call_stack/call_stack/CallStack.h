#pragma once
#include <stack>

using namespace std;

template <typename type>
class CallStack {
    stack<type> undoValues,
                redoValues;
    type value = type();
};