#include <iostream>
#include "ticket_management_system/TicketManagementSystem.h"
using namespace std;

int main() {
    auto ticketManagementSystem = TicketManagementSystem(
        "MS",
        10
    );

    ticketManagementSystem.issueTicket();
    ticketManagementSystem.issueTicket();
    ticketManagementSystem.issueTicket();
    ticketManagementSystem.issueTicket();
    ticketManagementSystem.issueTicket();

    ticketManagementSystem.printInformation();

    ticketManagementSystem.printTicketLine();
}