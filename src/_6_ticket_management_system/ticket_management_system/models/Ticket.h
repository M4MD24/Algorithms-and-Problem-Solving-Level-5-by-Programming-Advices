#pragma once

#include <string>

using namespace std;

class Ticket {
    string orderTime;
    string prefix;
    unsigned short number = 0;
    unsigned short remainingClients = 0;
    unsigned short timeRemainingAverageInMinutes = 0;

    static string getSystemDateTime() {
        return Date().getDateText() + ' ' + Time().getTimeText();
    }

public:
    Ticket() {}

    Ticket(
        const string &PREFIX,
        const unsigned short &NUMBER,
        const unsigned short &REMAINING_CLIENTS,
        const unsigned short &TIME_REMAINING_AVERAGE_IN_MINUTES
    ) {
        orderTime = getSystemDateTime();
        prefix = PREFIX;
        number = NUMBER;
        remainingClients = REMAINING_CLIENTS;
        timeRemainingAverageInMinutes = TIME_REMAINING_AVERAGE_IN_MINUTES;
    }

    string getFullNumber() {
        return prefix + to_string(
            number
        );
    }

    void printTicket() {
        cout << "Order Time: " << orderTime << '\n'
            << "Full Number: " << getFullNumber() << '\n'
            << "Remaining Clients: " << remainingClients << '\n'
            << "Time Remaining Average in Minutes: " << timeRemainingAverageInMinutes << '\n';
    }
};