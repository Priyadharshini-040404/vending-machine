#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct User {
    string username;
    string password;
    string role;
};
 
 
 
char getYN(string prompt) {
    char choice;
    while (true) {
        cout << prompt << " (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'Y' || choice == 'N') return choice;
        cout << "Invalid input. Please enter Y or N only.\n";
    }
}
 
vector<User> loadUsers(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (!file.is_open()) return users;
 
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string u, p, r;
        getline(ss, u, ',');
        getline(ss, p, ',');
        getline(ss, r, ',');
        if (!u.empty())
            users.push_back({u, p, r});
    }
    return users;
}
 
void saveUsers(const string& filename, const vector<User>& users) {
    ofstream file(filename, ios::trunc);
    for (auto& user : users) {
        file << user.username << "," << user.password << "," << user.role << "\n";
    }
}
 
bool userExists(const vector<User>& users, const string& username) {
    for (auto& u : users) {
        if (u.username == username) return true;
    }
    return false;
}
 
User* findUser(vector<User>& users, const string& username) {
    for (auto& u : users) {
        if (u.username == username) return &u;
    }
    return nullptr;
}
 
 
 
void updateCarLibrary() {
    cout << "Car library updated.\n";
}
 
void answerQueries() {
    cout << "Queries answered.\n";
}
 
void showDashboard() {
    cout << "Displaying dashboard...\n";
}
 
void logout() {
    cout << "Logout successful.\n";
}
 
 
bool registerUser(vector<User>& users, const string& filename) {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    if (userExists(users, username)) {
        cout << "Username already exists. Returning to login.\n";
        return false;
    }
    cout << "Enter new password: ";
    cin >> password;
 
    users.push_back({username, password, "user"});
    saveUsers(filename, users);
    cout << "User registered successfully.\n";
    return true;
}
 
bool forgotPassword(vector<User>& users, const string& filename) {
    string username;
    cout << "Enter your username to reset password: ";
    cin >> username;
 
    User* user = findUser(users, username);
    if (!user) {
        cout << "Username not found.\n";
        return false;
    }
 
    string newPass;
    cout << "Enter new password: ";
    cin >> newPass;
    user->password = newPass;
    saveUsers(filename, users);
    cout << "Password updated successfully.\n";
    return true;
}
 
bool loginUser(vector<User>& users, const string& filename, const string& role) {
    string username, password;
 
    while (true) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
 
        User* user = findUser(users, username);
        if (user && user->password == password && user->role == role) {
            cout << "Login successful.\n";
            return true;
        } else {
            cout << "Invalid username or password.\n";
            char reset = getYN("Forgot password?");
            if (reset == 'Y') {
                if (forgotPassword(users, filename)) {
                    cout << "Please try logging in again.\n";
                    continue; // Retry login after password reset
                }
            }
 
            char retry = getYN("Do you want to try logging in again?");
            if (retry == 'N') return false;
        }
    }
}
 
 
void selectVehicleAndPay() {
    cout << "Selecting vehicle...\n";
    char found = getYN("Did you find the desired vehicle?");
    if (found == 'Y') {
        cout << "Proceeding to payment...\n";
        cout << "Payment successful! Vehicle rented.\n";
    } else {
        cout << "Returning to dashboard.\n";
        showDashboard();
    }
}
 
 
void adminFunction(vector<User>& users, const string& filename) {
    if (loginUser(users, filename, "admin")) {
        showDashboard();
        char action;
        do {
            cout << "Choose function: (U)pdate Car Library, (A)nswer Queries, (L)ogout: ";
            cin >> action;
            action = toupper(action);
            if (action == 'U') updateCarLibrary();
            else if (action == 'A') answerQueries();
            else if (action == 'L') logout();
            else cout << "Invalid choice. Try again.\n";
        } while (action != 'L');
    } else {
        cout << "Admin login failed.\n";
    }
}
 
void userFunction(vector<User>& users, const string& filename) {
    char isRegistered = getYN("Are you a registered user?");
    if (isRegistered == 'Y') {
        if (loginUser(users, filename, "user")) {
            showDashboard();
            selectVehicleAndPay();
            logout();
        }
    } else {
        if (registerUser(users, filename)) {
            if (loginUser(users, filename, "user")) {
                showDashboard();
                selectVehicleAndPay();
                logout();
            }
        }
    }
}
 
void userIdentification(vector<User>& users, const string& filename) {
    char isAdmin = getYN("Are you an admin?");
    if (isAdmin == 'Y') {
        adminFunction(users, filename);
    } else {
        userFunction(users, filename);
    }
}
 
 
 
int main() {
    const string filename = "user.csv";
    vector<User> users = loadUsers(filename);
 
    if (!findUser(users, "admin")) {
        users.push_back({"admin", "admin123", "admin"});
        saveUsers(filename, users);
    }
 
    userIdentification(users, filename);
    return 0;
}