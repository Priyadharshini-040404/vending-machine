#include <iostream>
#include <string>
#include <algorithm>
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

// Get validated waste type: "organic" or "others"
string getWasteType() {
    string input;
    while (true) {
        cout << "Enter waste type (organic / others): ";
        cin >> input;

        // Convert to lowercase for uniformity
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input == "organic" || input == "others") {
            return input;
        }

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid waste type. Please enter 'organic' or 'others'.\n";
    }
}

int main() {
    string wasteType;
    char choice;

    cout << "---- Waste Processing System ----" << endl;

    // Step 1: Get Waste Type
    wasteType = getWasteType();

    if (wasteType == "organic") {
        // Step 2: Check High Energy
        choice = getYesNo("Does it have high energy? (y/n): ");

        if (choice == 'y' || choice == 'Y') {
            cout << "Process output: Bio-fuel" << endl;
        } else {
            cout << "Process output: Organic fertilizer" << endl;
        }
    } else {
        // Step 3: Check Reusable
        choice = getYesNo("Is it reusable? (y/n): ");

        if (choice == 'y' || choice == 'Y') {
            cout << "Process output: Reuse for other applications" << endl;
        } else {
            // Step 4: Check Recyclable
            choice = getYesNo("Is it recyclable? (y/n): ");

            if (choice == 'y' || choice == 'Y') {
                cout << "Process output: Recycle for other applications" << endl;
            } else {
                cout << "Process output: Landfill" << endl;
            }
        }
    }

    cout << "---- Processing Completed ----" << endl;
    return 0;
}
