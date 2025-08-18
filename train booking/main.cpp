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
int main() {
    cout << "Starting Train Journey Reservation System\n";
    bool reservationStatus = processReservation();
    beginBoarding(reservationStatus);
    cout << "Thank you for travelling with us.\n";
    return 0;
}