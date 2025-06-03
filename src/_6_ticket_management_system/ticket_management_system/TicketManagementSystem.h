#pragma once

#include "../data_structures/queue/Queue.h"
#include"../libraries/datetime/Date.h"
#include"../libraries/datetime/Time.h"
#include "models/Ticket.h"

using namespace std;

class TicketManagementSystem {
    Queue<Ticket> tickets;
    string prefix;
    unsigned short servedClients = 0;
    unsigned short waitingClients = 0;
    unsigned short averagingTimeInMinutes = 0;

    static string getSystemDateTime() {
        return Date().getDateText() + ' ' + Time().getTimeText();
    }

public:
    TicketManagementSystem(
        const string &PREFIX,
        const size_t &AVERAGING_TIME_IN_MINUTES
    ) {
        prefix = PREFIX;
        averagingTimeInMinutes = AVERAGING_TIME_IN_MINUTES;
    }

    string getPrefix() {
        return prefix;
    }

    unsigned short getTotalTickets() {
        return tickets.size();
    }

    unsigned short getServedClients() {
        return servedClients;
    }

    unsigned short getWaitingClients() {
        return waitingClients;
    }

    unsigned short getAveragingTimeInMinutes() {
        return averagingTimeInMinutes;
    }

    void issueTicket() {
        const unsigned short NUMBER = getTotalTickets() + 1;
        tickets.enqueue(
            {
                prefix,
                static_cast<unsigned short>(NUMBER),
                getTotalTickets(),
                getAveragingTimeInMinutes()
            }
        );
    }

    void printInformation() {
        cout << "~{Information}~" << '\n'
            << "Prefix: " << getPrefix() << '\n'
            << "Total Tickets: " << getTotalTickets() << '\n'
            << "Served Clients: " << getServedClients() << '\n'
            << "Waiting Clients: " << getWaitingClients() << '\n'
            << endl;
    }
};