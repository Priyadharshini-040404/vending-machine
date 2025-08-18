#include <iostream>
#include <string>

using namespace std;

bool getUserConfirmation(const string& promptMessage) {
    char userInput;
    cout << promptMessage << " (y/n): ";
    cin >> userInput;
    return (userInput == 'y' || userInput == 'Y');
}
void handleTicketCollection(const string& collectionMethod) {
    if (collectionMethod == "machine") {
        cout << "Collect your ticket from the machine.\n";
    } else if (collectionMethod == "mail") {
        cout << "Check the letter box in 3 days for your ticket.\n";
    }
}
void ticketOptions() {
    while (true) {
        cout << "How do you want to collect your ticket?\n";
        cout << "1. From machine\n2. Mail\nChoose (1 or 2): ";
        int ticketChoice;
        cin >> ticketChoice;
        if (ticketChoice == 1) {
            handleTicketCollection("machine");
            break;
        } else if (ticketChoice == 2) {
            handleTicketCollection("mail");
            break;
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }
}

void reserveSeat() {
    cout << "Selecting seat for reservation...\n";
}

bool processReservation() {
    while (true) {
        if (getUserConfirmation("Do you need a seat reservation?")) {
            reserveSeat();
            ticketOptions();
            return true;
        } else {
            cout << "You need to decide whether you want reservation or not.\n";
        }
    }
}
void verifyTicket(bool hasDiscount) {
    cout << "Ticket checked.\n";
    if (hasDiscount) {
        if (getUserConfirmation("Show valid documentation for discounted ticket?")) {
            cout << "Documentation accepted.\n";
        } else {
            cout << "Valid documentation required. Returning to ticket check.\n";
            verifyTicket(hasDiscount);
        }
    }
}

void reachDestination() {
    while (true) {
        if (getUserConfirmation("Have you arrived at your destination?")) {
            cout << "Leaving the train. Journey complete.\n";
            break;
        } else {
            cout << "Keep going until you arrive at your destination.\n";
        }
    }
}
void beginBoarding(bool reservationConfirmed) {
    if (reservationConfirmed) {
        cout << "Looking for assigned seat...\n";
    } else {
        cout << "Looking for unassigned seat...\n";
    }
    bool hasDiscount = getUserConfirmation("Is your ticket discounted?");
    verifyTicket(hasDiscount);
    reachDestination();
}
int main() {
    cout << "Starting Train Journey Reservation System\n";
    bool reservationStatus = processReservation();
    beginBoarding(reservationStatus);
    cout << "Thank you for travelling with us.\n";
    return 0;
}