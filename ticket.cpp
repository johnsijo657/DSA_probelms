#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Ticket class to hold ticket details
class Ticket {
public:
    int ticket_id;
    string customer_name;

    Ticket(int id, string name) : ticket_id(id), customer_name(name) {}
};

// TicketingSystem class to manage ticket operations
class TicketingSystem {
private:
    queue<Ticket> ticket_queue;
    int current_ticket_id;

public:
    TicketingSystem() : current_ticket_id(1) {}

    // Issue a new ticket
    void issue_ticket(string customer_name) {
        Ticket new_ticket(current_ticket_id++, customer_name);
        ticket_queue.push(new_ticket);
        cout << "Ticket issued: ID=" << new_ticket.ticket_id << ", Customer=" << new_ticket.customer_name << endl;
    }

    // Process the next ticket in the queue
    void process_ticket() {
        if (!ticket_queue.empty()) {
            Ticket processed_ticket = ticket_queue.front();
            ticket_queue.pop();
            cout << "Processing ticket: ID=" << processed_ticket.ticket_id << ", Customer=" << processed_ticket.customer_name << endl;
        } else {
            cout << "No tickets to process." << endl;
        }
    }

    // View details of the next ticket to be processed
    void view_next_ticket() {
        if (!ticket_queue.empty()) {
            Ticket next_ticket = ticket_queue.front();
            cout << "Next ticket to process: ID=" << next_ticket.ticket_id << ", Customer=" << next_ticket.customer_name << endl;
        } else {
            cout << "No tickets in the queue." << endl;
        }
    }
};

// Main function to test the ticketing system
int main() {
    TicketingSystem ticket_system;

    // Issuing some tickets
    ticket_system.issue_ticket("Alice");
    ticket_system.issue_ticket("Bob");
    ticket_system.issue_ticket("Charlie");

    // Viewing the next ticket to be processed
    ticket_system.view_next_ticket();

    // Processing tickets
    ticket_system.process_ticket();
    ticket_system.process_ticket();
    ticket_system.process_ticket();
    ticket_system.process_ticket();  // should print "No tickets to process."

    // Issuing another ticket
    ticket_system.issue_ticket("David");

    // Viewing the next ticket again
    ticket_system.view_next_ticket();

    // Processing the next ticket
    ticket_system.process_ticket();

    return 0;
}
