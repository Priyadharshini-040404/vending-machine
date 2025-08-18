#include <iostream>
#include <string>
using namespace std;

// Predefined passwords
const string storedLoginCode = "user123";
const string storedNewPassword = "newpass456";

// Function definitions

bool verifyUserIdentity() {
    char userResponse;
    cout << "User Identification (U)? (Y/N): ";
    cin >> userResponse;
    return (userResponse == 'Y' || userResponse == 'y');
}

bool checkAdminStatus() {
    char userResponse;
    cout << "If Admin? (Y/N): ";
    cin >> userResponse;
    return (userResponse == 'Y' || userResponse == 'y');
}

void displayAdminDashboard() {
    cout << "Admin Login (A)...\n";
    cout << "Admin Dashboard (AD)...\n";
    cout << "Update the databases.\n";
    cout << "Answer Queries.\n";
    cout << "Logout.\n";
}

bool checkUserRegistration() {
    char userResponse;
    cout << "Are you a registered user? (Y/N): ";
    cin >> userResponse;
    return (userResponse == 'Y' || userResponse == 'y');
}

bool performUserLogin() {
    string enteredPassword;
    cout << "Login (L): Enter password: ";
    cin >> enteredPassword;
    if (enteredPassword == storedLoginCode) {
        return true;
    } else {
        cout << "Incorrect password.\n";
        return false;
    }
}

bool verifyUserPassword() {
    string enteredPassword;
    cout << "Password verification (PV): Enter password: ";
    cin >> enteredPassword;
    if (enteredPassword == storedLoginCode) {
        return true;
    } else {
        cout << "Password incorrect.\n";
        return false;
    }
}

bool processNewPasswordRequest() {
    char userResponse;
    cout << "Request new password (NP)? (Y/N): ";
    cin >> userResponse;
    if (userResponse == 'Y' || userResponse == 'y') {
        string enteredNewPassword;
        cout << "Enter new password: ";
        cin >> enteredNewPassword;
        if (enteredNewPassword == storedNewPassword) {
            cout << "New password accepted.\n";
            return true;
        } else {
            cout << "New password invalid.\n";
            return false;
        }
    }
    return false;
}

void initiateVehicleRental() {
    char userResponse;
    cout << "Search for the vehicle? (Y/N): ";
    cin >> userResponse;
    if (userResponse == 'Y' || userResponse == 'y') {
        cout << "Rent Vehicle (RV)...\n";
    } else {
        cout << "Return (A)\n";
    }
}

void processPayment() {
    cout << "Make payments.\n";
}

// Main function

int main() {
    cout << "Start\n";

    if (!verifyUserIdentity()) {
        cout << "End\n";
        return 0;
    }

    if (checkAdminStatus()) {
        displayAdminDashboard();
        cout << "Return (Admin Dashboard)\n";
        cout << "End\n";
        return 0;
    }

    if (!checkUserRegistration()) {
        cout << "Sign in (S)\n";
        cout << "End\n";
        return 0;
    }

    if (!performUserLogin()) {
        cout << "Return (Login Failed)\n";
        cout << "End\n";
        return 0;
    }

    if (!verifyUserPassword()) {
        if (!processNewPasswordRequest()) {
            cout << "Return\n";
            cout << "End\n";
            return 0;
        }
    }

    initiateVehicleRental();

    processPayment();

    cout << "End\n";
    return 0;
}
