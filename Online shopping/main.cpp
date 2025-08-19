#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function to get validated yes/no input
char getYesNo(const string &prompt) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (input.size() == 1 &&
            (input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N')) {
            return input[0];
        }
        cerr << "Invalid input! Please enter only 'y' or 'n'.\n";
    }
}

// Function to get validated positive integer input
int getPositiveInt(const string &prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cerr << "Invalid input! Please enter a positive number.\n";
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear remaining buffer
            return value;
        }
    }
}

int main() {
    cout << "Start\n";
    cout << "Order placed.\n";

    int itemCount = getPositiveInt("Enter number of items in the order: ");

    // Process each item
    for (int i = 1; i <= itemCount; i++) {
        cout << "\nChecking item " << i << "...\n";

        char inWarehouse = getYesNo("Is item " + to_string(i) + " in warehouse? (y/n): ");

        if (inWarehouse == 'y' || inWarehouse == 'Y') {
            cout << "Packed with other orders in warehouse.\n";
        } else {
            cout << "Contacting seller to ship item " << i << "...\n";
            cout << "Seller sends item " << i << " to customer.\n";
        }
    }

    // After all items processed
    cout << "\nAll items processed.\n";
    cout << "Send warehouse goods to customer.\n";
    cout << "Customer collects goods.\n";
    cout << "Seller confirms customer received order.\n";
    cout << "End\n";

    return 0;
}
