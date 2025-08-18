#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string correctUser = "admin";     // Predefined username
    string correctPass = "12345";     // Predefined password
    string user, pass;
    int attempts;
 
    cout << "Enter number of attempts already made: ";
    cin >> attempts;
 
    // Step 1: Check if user already has 5 attempts
    if (attempts >= 5) {
        cout << "\nAccount locked due to 5 failed attempts!" << endl;
        cout << "Alerting user..." << endl;
    } else {
        // Step 2: Allow login
        cout << "\nEnter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;
 
        // Step 3: Check authorization
        if (user == correctUser && pass == correctPass) {
            cout << "\nLogin successful! Access granted." << endl;
        } else {
            cout << "\nUnauthorized access! Alerting user..." << endl;
        }
    }
 
    cout << "---- End ----" << endl;
    return 0;
}
 