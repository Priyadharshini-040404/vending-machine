#include <iostream>
#include <string>

using namespace std;

bool getUserConfirmation(const string& promptMessage) {
    char userInput;
    cout << promptMessage << " (y/n): ";
    cin >> userInput;
    return (userInput == 'y' || userInput == 'Y');
}
int main() {
    cout << "Starting Train Journey Reservation System\n";
    bool reservationStatus = processReservation();
    beginBoarding(reservationStatus);
    cout << "Thank you for travelling with us.\n";
    return 0;
}