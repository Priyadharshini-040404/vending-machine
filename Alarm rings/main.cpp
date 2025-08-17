#include <iostream>
using namespace std;
 
int main() {
    char ready, late;
 
    cout << "=== Alarm Clock Simulation ===" << endl;
 
    while (true) {
        cout << "\nAlarm rings!" << endl;
 
        // Step 1: Check if ready to wake up
        cout << "Are you ready to wake up? (y/n): ";
        cin >> ready;
 
        if (ready == 'y' || ready == 'Y') {
            cout << "You leave the bed." << endl;
            cout << "Alarm turned off." << endl;
            break; // End program
        }
        // Step 2: If not ready, check if late
        cout << "Will you be late? (y/n): ";
        cin >> late;
 
        if (late == 'y' || late == 'Y') {
            cout << "You leave the bed." << endl;
            cout << "Alarm turned off." << endl;
            break; // End program
        } else {
            cout << "Snoozing alarm for 5 minutes..." << endl;
            cout << "Waiting... Alarm will ring again!" << endl;
            // Loop continues, alarm rings again
        }
    }
 
    cout << "\n=== Program Ended ===" << endl;
    return 0;
}