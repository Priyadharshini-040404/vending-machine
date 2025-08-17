#include <iostream>
#include <string>
using namespace std;
 
int main() {
    char power;
    bool powerOn = false;
    string coffee;
 
    cout << "=== Coffee Machine Program ===" << endl;
 
    // Start
    cout << "Press 'Y' to Power On: ";
    cin >> power;
 
    if (power == 'Y' || power == 'y') {
        powerOn = true;
        cout << "\nMachine Powered On ✅" << endl;
 
        while (powerOn) {
            cout << "\nSelect Coffee (Latte / Mocha / Espresso): ";
            cin >> coffee;
 
            if (coffee == "Latte" || coffee == "latte") {
                cout << "Preparing Latte...\n";
                cout << "Adding frothed milk...\n";
                cout << "Adding hot coffee...\n";
            }
            else if (coffee == "Mocha" || coffee == "mocha") {
                cout << "Preparing Mocha...\n";
                cout << "Adding chocolate powder...\n";
                cout << "Adding frothed milk...\n";
                cout << "Adding hot coffee...\n";
            }
            else if (coffee == "Espresso" || coffee == "espresso") {
                cout << "Preparing Espresso...\n";
                cout << "Adding hot coffee...\n";
            }
            else {
                cout << "Invalid selection ❌" << endl;
            }
 
            // 👇 This is the missing part in your code
            cout << "\nPress 'P' to Power Off OR any other key to continue: ";
            cin >> power;
 
            if (power == 'P' || power == 'p') {
                powerOn = false;
                cout << "\nMachine Powered Off ❌" << endl;
            }
        }
    } else {
        cout << "Power not turned on. Exiting program." << endl;
    }
 
    return 0;
}