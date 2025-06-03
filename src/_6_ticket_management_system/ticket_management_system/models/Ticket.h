#pragma once

#include <string>

using namespace std;

class Ticket {
    string prefix;
    unsigned short number = 0;
    unsigned short remainingClients = 0;
    unsigned short averagingTimeInMinutes = 0;

public:
    Ticket() {}

    Ticket(
        const string &PREFIX,
        const unsigned short &NUMBER,
        const unsigned short &REMAINING_CLIENTS,
        const unsigned short &AVERAGING_TIME_IN_MINUTES
    ) {
        prefix = PREFIX;
        number = NUMBER;
        remainingClients = REMAINING_CLIENTS;
        averagingTimeInMinutes = AVERAGING_TIME_IN_MINUTES;
    }

    void setPrefix(
        const string &PREFIX
    ) {
        prefix = PREFIX;
    }

    string getPrefix() {
        return prefix;
    }

    void setNumber(
        const unsigned short &NUMBER
    ) {
        number = NUMBER;
    }

    unsigned short getNumber() {
        return number;
    }

    string getFullNumber() {
        return prefix + to_string(
            number
        );
    }

    void setRemainingClients(
        const unsigned short &REMAINING_CLIENTS
    ) {
        remainingClients = REMAINING_CLIENTS;
    }

    unsigned short getRemainingClients() {
        return remainingClients;
    }

    void setAveragingTimeInMinutes(
        const unsigned short &AVERAGING_TIME_IN_MINUTES
    ) {
        averagingTimeInMinutes = AVERAGING_TIME_IN_MINUTES;
    }

    unsigned short getAveragingTimeInMinutes() {
        return averagingTimeInMinutes;
    }
};