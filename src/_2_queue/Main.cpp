#include <iostream>
#include "queue/Queue.h"
using namespace std;

int main() {
    Queue<short> values;

    cout << "■ After Enqueue Values: " << endl;

    values.enqueue(
        10
    );
    values.enqueue(
        20
    );
    values.enqueue(
        30
    );
    values.enqueue(
        40
    );
    values.enqueue(
        50
    );

    values.printValues();

    cout << "\n■ After Dequeue Values: " << endl;

    values.dequeue();
    values.dequeue();

    values.printValues();

    cout << "\n■ Count of Values: " << values.size() << endl;

    cout << "\n■ Front Value: " << values.front() << endl;

    cout << "\n■ Rear (Back) Value: " << values.rear() << endl;

    cout << "\n■ Is Empty?\n" << boolalpha << values.isEmpty() << endl;

    cout << "\n■ Get Item: " << values.getItem(
        1
    ) << endl;

    cout << "\n■ Update Item?\n" << boolalpha << values.updateItem(
        2,
        22
    ) << endl;

    values.printValues();
}