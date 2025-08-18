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
    return 0;
}