#pragma once

#include "../data_structures/queue/Queue.h"
#include"../libraries/datetime/Date.h"
#include"../libraries/datetime/Time.h"

using namespace std;

template <typename type>
class TicketManagementSystem {
    Queue<string> tickets;

    static string getSystemDateTime() {
        return Date().getDateText() + ' ' + Time().getTimeText();
    }

public:
    
};