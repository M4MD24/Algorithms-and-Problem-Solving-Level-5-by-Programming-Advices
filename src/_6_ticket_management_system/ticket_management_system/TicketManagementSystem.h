#pragma once

#include "../data_structures/queue/Queue.h"
#include "../libraries/Utils.h"
#include "models/Ticket.h"

using namespace std;

class TicketManagementSystem {
    Queue<Ticket> tickets;
    string prefix;
    unsigned short totalTickets = 0;
    unsigned short servedClients = 0;
    unsigned short waitingClients = 0;
    unsigned short timeRemainingAverageInMinutes = 0;

public:
    TicketManagementSystem(
        const string &PREFIX,
        const size_t &TIME_REMAINING_AVERAGE_IN_MINUTES
    ) {
        prefix = PREFIX;
        timeRemainingAverageInMinutes = TIME_REMAINING_AVERAGE_IN_MINUTES;
    }

    string getPrefix() {
        return prefix;
    }

    unsigned short getTotalTickets() {
        return totalTickets;
    }

    unsigned short getServedClients() {
        return servedClients;
    }

    unsigned short getWaitingClients() {
        return tickets.size();
    }

    unsigned short getTimeRemainingAverageTimeInMinutes() {
        return timeRemainingAverageInMinutes;
    }

    void issueTicket() {
        tickets.enqueue(
            {
                prefix,
                static_cast<unsigned short>(getTotalTickets() + 1),
                getTotalTickets(),
                static_cast<unsigned short>(getTimeRemainingAverageTimeInMinutes() * getTotalTickets())
            }
        );
        totalTickets++;
    }

    void printInformation() {
        Utils::printTitle(
            "Information"
        );
        cout << "Prefix: " << getPrefix() << '\n'
            << "Total Tickets: " << getTotalTickets() << '\n'
            << "Served Clients: " << getServedClients() << '\n'
            << "Waiting Clients: " << getWaitingClients() << '\n'
            << endl;
    }

    void printTicketLine() {
        Utils::printTitle(
            "Client Line"
        );
        const size_t TICKET_SIZE = tickets.size();
        for (size_t index = 0; index < TICKET_SIZE; ++index) {
            cout << tickets.getItem(
                index
            ).getFullNumber();
            if (index < TICKET_SIZE - 1)
                cout << " <-- ";
        }
        cout << '\n' << endl;
    }

    void printTickets() {
        Utils::printTitle(
            "Tickets"
        );
        const size_t TICKET_SIZE = tickets.size();
        for (size_t index = 0; index < TICKET_SIZE; ++index) {
            tickets.getItem(
                index
            ).printTicket();
            if (index < TICKET_SIZE - 1)
                Utils::printLine();
        }
        cout << endl;
    }

    void serveClient() {
        servedClients++;
        tickets.dequeue();
    }
};