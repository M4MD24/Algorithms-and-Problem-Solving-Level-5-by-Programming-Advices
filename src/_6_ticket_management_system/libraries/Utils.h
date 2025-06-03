#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Utils {
    inline void printTitle(
        const string &TITLE
    ) {
        cout << "~{" << TITLE << "}~" << endl;
    }

    inline void printLine() {
        cout << "--------------------" << endl;
    }
}