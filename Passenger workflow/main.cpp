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
    int category = getCategory();
    if (category == 1) {
        cout << "Hand search required. Return.\n";
    } else if (category == 2) {
        cout << "Give up dangerous goods. Return.\n";
    } else if (category == 3) {
        cout << "Give up restricted items above permitted limits. Return.\n";
    }
}
 

int main() {
    while (true) {
        // Security check
        performScreening();
 
        // Journey simulation
        cout << "Immigration process...\n";
        cout << "Boarding flight...\n";
        cout << "Flight departed...\n";
        cout << "Flight landed.\n";
 
        // Permit check
        if (!checkEntryPermit()) {
            break;
        }
 
        // Baggage claim
        cout << "Claim baggage.\n";
 
        // Connection flight check
        char hasConnection = askYesNo("Do you have a connecting flight? (Y/N): ");
        if (hasConnection == 'n' || hasConnection == 'N') {
            cout << "Journey ends at baggage claim.\n";
            break;
        }
 
        cout << "Proceeding to next connecting flight...\n";
    }
 
    cout << "Process finished.\n";
    return 0;
}
 