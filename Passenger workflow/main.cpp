#include <iostream>
using namespace std;

// Function for valid yes/no input
char askYesNo(const string& message) {
    char response;
    while (true) {
        cout << message;
        cin >> response;
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N')
            return response;
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Function for valid item category selection
int getCategory() {
    int option;
    while (true) {
        cout << "Enter item category: [1] Metal, [2] Dangerous, [3] Restricted: ";
        cin >> option;
        if (option == 1 || option == 2 || option == 3)
            return option;
        cout << "Invalid input. Please enter 1, 2, or 3 only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Security screening process
void performScreening() {
    cout << "\n--- Security Screening ---\n";
    cout << "Check-in.\n";
    cout << "Baggage drop.\n";
    cout << "Enter checking.\n";

    int category = getCategory();
    if (category == 1) {
        cout << "Hand search required. Return.\n";
    } else if (category == 2) {
        cout << "Give up dangerous goods. Return.\n";
    } else if (category == 3) {
        cout << "Give up restricted items above permitted limits. Return.\n";
    }
}

// Permit verification
bool checkEntryPermit() {
    char permission = askYesNo("Permit to enter country? (Y/N): ");
    if (permission == 'y' || permission == 'Y') {
        return true;
    } else {
        cout << "Send back to originating country. Return.\n";
        return false;
    }
}

int main() {
    while (true) {
        // Step 1: Perform screening
        performScreening();

        // Step 2: Simulate flight journey after screening
        cout << "\n--- Flight Journey ---\n";
        cout << "Immigration process...\n";
        cout << "Boarding flight...\n";
        cout << "Flight departs...\n";
        cout << "Flight lands.\n";

        // Step 3: Ask about connecting flight
        char hasConnection = askYesNo("\nDo you have a connecting flight? (Y/N): ");

        if (hasConnection == 'n' || hasConnection == 'N') {
            // If no connecting flight, check permit
            if (!checkEntryPermit()) {
                break; // End if permit denied
            }

            // Final step
            cout << "Claim baggage.\n";
            cout << "Journey ends at baggage claim.\n";
            break;
        }

        // If yes connecting flight, repeat the process
        cout << "Proceeding to next connecting flight...\n";
    }

    cout << "\nProcess finished.\n";
    return 0;
}
