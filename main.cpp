#include <iostream>
#include <string>
using namespace std;

// Function to get a valid "yes" or "no" input
string getYesOrNo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (input == "yes" || input == "no") {
            return input;
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'.\n";
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Discard invalid input
        }
    }
}

// Function to get valid coffee selection
string getCoffeeSelection() {
    string coffee;
    while (true) {
        cout << "Select coffee (latte / mocha / espresso): ";
        cin >> coffee;

        if (coffee == "latte" || coffee == "mocha" || coffee == "espresso") {
            return coffee;
        } else {
            cout << "Invalid coffee selection. Please try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Function to simulate making the selected coffee
void makeCoffee(const string& type) {
    if (type == "latte") {
        cout << "Adding frothed milk...\n";
        cout << "Adding hot coffee...\n";
    } else if (type == "mocha") {
        cout << "Adding chocolate powder...\n";
        cout << "Adding frothed milk...\n";
        cout << "Adding hot coffee...\n";
    } else if (type == "espresso") {
        cout << "Adding hot coffee...\n";
    }
    cout << type << " is ready!\n";
}

int main() {
    // Step 1: Power on
    string power = getYesOrNo("Power on the coffee machine? (yes/no): ");
    if (power == "no") {
        cout << "Machine remains off. Exiting...\n";
        return 0;
    }

    bool running = true;
    while (running) {
        // Step 2: Select coffee
        string selectedCoffee = getCoffeeSelection();

        // Step 3: Make coffee
        makeCoffee(selectedCoffee);

        // Step 4: Ask to power off
        string shutdown = getYesOrNo("Do you want to power off the machine? (yes/no): ");
        if (shutdown == "yes") {
            cout << "Powering off the machine. Goodbye!\n";
            running = false;
        } else {
            cout << "Returning to coffee selection...\n";
        }
    }

    return 0;
}
