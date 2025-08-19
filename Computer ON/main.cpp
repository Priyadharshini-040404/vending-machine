#include <iostream>
using namespace std;

// Helper for Y/y/N/n validation
char getYesNo(const string& prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            return answer;
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Diagnose function (only if computer is ON)
void diagnose() {
    char errorMsg = getYesNo("Is there an error message? (Y/N): ");
    if (errorMsg == 'y' || errorMsg == 'Y') {
        cout << "Perform Diagnosis.\n";
    } else {
        cout << "Computer is in good condition. Return.\n";
    }
}

// Power supply check function
void powerSupplyCheck() {
    char powerLight = getYesNo("Is power light ON? (Y/N): ");
    if (powerLight == 'y' || powerLight == 'Y') {
        cout << "Find specialist.\n";
        exit(0);  // Exit program
    }

    // Power light is OFF, now check if it's plugged in
    char pluggedIn = getYesNo("Is power plugged into wall? (Y/N): ");
    if (pluggedIn == 'y' || pluggedIn == 'Y') {
        cout << "Find specialist.\n";
        exit(0);  // Exit program
    } else {
        cout << "Plug power into the wall and check computer again...\n";
        return;  // Go back to main loop
    }
}

int main() {
    cout << "=== Computer Diagnosis System ===\n";

    while (true) {
        cout << "Start with Power Check...\n";
        char computerOn = getYesNo("Is computer ON? (Y/N): ");

        if (computerOn == 'y' || computerOn == 'Y') {
            cout << "Computer is ON. Checking for error messages...\n";
            diagnose();
            break;  // Exit loop
        } else {
            cout << "Computer is OFF. Checking power supply...\n";
            powerSupplyCheck();  // Returns to loop unless it exits
        }
    }

    cout << "Process ended.\n";
    return 0;
}
