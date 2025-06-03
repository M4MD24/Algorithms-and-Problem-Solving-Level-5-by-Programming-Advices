#pragma once

#include "../data_structures/queue/Queue.h"
#include "../libraries/Utils.h"
#include "models/Ticket.h"

using namespace std;

class TicketManagementSystem {
    Queue<Ticket> waitingClients;
    Queue<Ticket> servedClients;
    string prefix;
    unsigned short totalTickets = 0;
    unsigned short timeRemainingAverageInMinutes = 0;

    void printTickets(
        const string &TITLE,
        Queue<Ticket> tickets
    ) {
        Utils::printTitle(
            TITLE
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
        return servedClients.size();
    }

    unsigned short getWaitingClients() {
        return waitingClients.size();
    }

    unsigned short getTimeRemainingAverageInMinutes() {
        return timeRemainingAverageInMinutes;
    }

    void issueTicket() {
        waitingClients.enqueue(
            {
                prefix,
                static_cast<unsigned short>(getTotalTickets() + 1),
                getTotalTickets(),
                static_cast<unsigned short>(getTimeRemainingAverageInMinutes() * getTotalTickets())
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
        const size_t TICKET_SIZE = waitingClients.size();
        for (size_t index = 0; index < TICKET_SIZE; ++index) {
            cout << waitingClients.getItem(
                index
            ).getFullNumber();
            if (index < TICKET_SIZE - 1)
                cout << " <-- ";
        }
        cout << '\n' << endl;
    }

    void printWaitingClients() {
        printTickets(
            "Waiting Clients",
            waitingClients
        );
    }

    void serveClient() {
        servedClients.enqueue(
            waitingClients.front()
        );
        waitingClients.dequeue();
    }

    void printServedClients() {
        printTickets(
            "Served Clients",
            servedClients
        );
    }

    string whoIsNext() {
        return waitingClients.front().getFullNumber();
    }
};