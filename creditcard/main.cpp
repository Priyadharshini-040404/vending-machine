#include <iostream>
using namespace std;
 
int main() {
    cout << "Order placed by client\n";
    cout << "Payment verified by card network\n";
 
    char choice;
 
    while (true) {
        cout << "Is the card valid? (y/n): ";
        cin >> choice;
 
        if (choice == 'n' || choice == 'N') {
            cout << "Payment verified by card network\n";
            continue; // recheck card validity
        }
 
        // If card is valid
        cout << "Are funds available? (y/n): ";
        cin >> choice;
 
        if (choice == 'n' || choice == 'N') {
            // Not enough funds → loop back to card validity
            continue;
        }
 
        // Funds are available
        cout << "Verified by bank\n";
        cout << "Is account valid? (y/n): ";
        cin >> choice;
 
        if (choice == 'y' || choice == 'Y') {
            cout << "Transaction completed, cardholder will receive statement\n";
            cout << "End of program\n";
            break;
        } else {
            // If account invalid → loop back to card validity
            continue;
        }
    }
 
    return 0;
}