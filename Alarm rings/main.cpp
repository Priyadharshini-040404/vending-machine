#include <iostream>
using namespace std;

// Function to get validated 'y' or 'n' input
char getYesNoInput(const string& prompt) {
    char input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
            return input;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();               // Clear error flags
            cin.ignore(10000, '\n');   // Ignore rest of the line
        }
    }
}

int main() {
    char ready, late;

    cout << "=== Alarm Clock Simulation ===" << endl;

    while (true) {
        cout << "\nAlarm rings!" << endl;

        // Step 1: Check if ready to wake up
        ready = getYesNoInput("Are you ready to wake up? (y/n): ");

        if (ready == 'y' || ready == 'Y') {
            cout << "You leave the bed." << endl;
            cout << "Alarm turned off." << endl;
            break; // End program
        }

        // Step 2: If not ready, check if late
        late = getYesNoInput("Will you be late? (y/n): ");

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
