#include <iostream>
#include <string>
using namespace std;

bool isAccountLocked(int failedAttempts) {
    if (failedAttempts >= 5) {
        cout << "Account locked due to 5 unsuccessful attempts.\n";
        cout << "Alert: Please contact support.\n";
        return true;
    }
    return false;
}

bool validateLogin() {
    const string expectedUser = "admin";    // Predefined username
    const string expectedPass = "1234";     // Predefined password

    string inputUser, inputPass;
    cout << "Enter username: ";
    cin >> inputUser;
    cout << "Enter password: ";
    cin >> inputPass;

    if (inputUser == expectedUser && inputPass == expectedPass) {
        cout << "Access granted.\n";
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

int main() {
    int loginAttempts = 0;
    bool isAuthenticated = false;

    while (!isAuthenticated) {
        if (isAccountLocked(loginAttempts)) {
            break;
        }

        isAuthenticated = validateLogin();

        if (!isAuthenticated) {
            loginAttempts++;
        }
    }

    return 0;
}
