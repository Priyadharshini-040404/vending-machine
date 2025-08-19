#include <iostream>
#include <string>
using namespace std;

// Get and validate Y/y/N/n input
char getYesNo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (input.length() == 1 &&
            (input[0] == 'y' || input[0] == 'Y' ||
             input[0] == 'n' || input[0] == 'N')) {
            return input[0];
        }

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
    }
}

int main() {
    cout << "---- Plane Boarding System ----" << endl;

    // Step 1: Plane arrived at gate
    cout << "Plane arrived at the gate." << endl;

    // Step 2: Start Priority Boarding
    cout << "Priority Boarding started." << endl;

    // Loop until boarding proceeds
    while (true) {
        char isFirstClass = getYesNo("Is passenger First Class? (y/n): ");

        if (isFirstClass == 'y' || isFirstClass == 'Y') {
            cout << "First Class passenger boards plane." << endl;
            break;
        } else {
            char halfBoarded = getYesNo("Has half of First Class boarded? (y/n): ");

            if (halfBoarded == 'y' || halfBoarded == 'Y') {
                cout << "All passengers start boarding plane." << endl;
                break;
            } else {
                cout << "Check again.\n" << endl;
                // Loop repeats to check again from "Is passenger First Class?"
            }
        }
    }

    // Step 3: 5 minutes before gate closes
    cout << "\n5 minutes before gate closes." << endl;

    char allAboard = getYesNo("Are all passengers aboard? (y/n): ");

    if (allAboard == 'y' || allAboard == 'Y') {
        cout << "Announcement: All passengers are on board." << endl;
        cout << "Gate closed." << endl;
    } else {
        cout << "Announcement: Final boarding call for passengers." << endl;
        cout << "Waiting 5 minutes..." << endl;
        cout << "Gate closed." << endl;
    }

    cout << "---- End ----" << endl;
    return 0;
}
