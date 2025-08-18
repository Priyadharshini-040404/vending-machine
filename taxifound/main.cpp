#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
 
int main() {
    cout << "=== Ride Assignment Program ===\n";
 
    // Step 1: How was the order placed
    char method;
    cout << "Order placed by (P)hone or (S)oftware? ";
    cin >> method;
    if (method == 'P' || method == 'p')
        cout << "Sending request to Call Centre Server...\n";
    else if (method == 'S' || method == 's')
        cout << "Sending request to Software Server...\n";
    else {
        cout << "Invalid option. Exiting...\n";
        return 0;
    }
    / Step 2: Check pickup time
    bool pickupWithin30 = false;
    while (!pickupWithin30) {
        // (Here we just simulate the condition check)
        cout << "Checking if pickup is within 30 minutes...\n";
 
        // For demo: press y/n to simulate condition
        char ans;
        cout << "Is pickup within 30 mins? (y/n): ";
        cin >> ans;
 
        if (ans == 'y' || ans == 'Y') {
            pickupWithin30 = true;
        } else {
            cout << "Not within 30 mins. Wait 1 minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1)); // simulate 1 min as 1 sec
        }
    }
    return 0;
}