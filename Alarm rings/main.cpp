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
    }
 
    cout << "\n=== Program Ended ===" << endl;
    return 0;
}