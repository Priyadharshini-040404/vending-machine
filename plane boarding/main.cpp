#include <iostream>
#include <string>
using namespace std;
 
int main() {
    cout << "---- Plane Boarding System ----" << endl;
 
    // Step 1: Plane arrived at gate
    cout << "Plane arrived at the gate." << endl;
 
    // Step 2: Start Priority Boarding
    cout << "Priority Boarding started." << endl;
 
    char choice;
    cout << "Is passenger First Class? (y/n): ";
    cin >> choice;
 
    if (choice == 'y' || choice == 'Y') {
        cout << "First Class passenger boards plane." << endl;
    } else {
        cout << "Has half of First Class boarded? (y/n): ";
        cin >> choice;
 
        if (choice == 'y' || choice == 'Y') {
            cout << "All passengers start boarding plane." << endl;
        } else {
            cout << "Waiting for First Class passengers..." << endl;
        }
    }
 
    // Step 3: 5 minutes before gate closes
    cout << "\n5 minutes before gate closes." << endl;
 
    cout << "Are all passengers aboard? (y/n): ";
    cin >> choice;
 
    if (choice == 'y' || choice == 'Y') {
        cout << "Announcement: All passengers are on board." << endl;
        cout << "Waiting 5 minutes..." << endl;
        cout << "Gate closed." << endl;
    } else {
        cout << "Announcement: Final boarding call for passengers." << endl;
        cout << "Waiting 5 minutes..." << endl;
        cout << "Gate closed." << endl;
    }
 
    cout << "---- End ----" << endl;
    return 0;
}
 