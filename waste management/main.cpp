#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string wasteType;
    char choice;
 
    cout << "---- Waste Processing System ----" << endl;
 
    // Step 1: Get Waste
    cout << "Enter waste type (organic / others): ";
    cin >> wasteType;
 
    if (wasteType == "organic") {
        // Step 2: Check High Energy
        cout << "Does it have high energy? (y/n): ";
        cin >> choice;
 
        if (choice == 'y' || choice == 'Y') {
            cout << "Process output: Bio-fuel" << endl;
        } else {
            cout << "Process output: Organic fertilizer" << endl;
        }
    } else {
        // Step 3: Check Reusable
        cout << "Is it reusable? (y/n): ";
        cin >> choice;
 
        if (choice == 'y' || choice == 'Y') {
            cout << "Process output: Reuse for other applications" << endl;
        } else {
            // Step 4: Check Recyclable
            cout << "Is it recyclable? (y/n): ";
            cin >> choice;
 
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