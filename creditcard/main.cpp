#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to prompt for yes/no and return true/false
bool getYesNoInput(const string& promptMessage) {
    char userResponse;
    while (true) {
        cout << promptMessage << " (Y/N)? ";
        cin >> userResponse;
        userResponse = tolower(userResponse);
        if (userResponse == 'y') return true;
        if (userResponse == 'n') return false;
        cout << "Invalid input, please enter Y or N.\n";
    }
}

// Function to log transaction status to the CSV file
void logTransactionStatus(const string& transactionOutcome) {
    ofstream logFile("customer_database.csv", ios::app);
    if (!logFile) {
        cout << "Unable to open customer_database.csv for logging.\n";
        return;
    }
    logFile << "Transaction," << transactionOutcome << "\n";
    logFile.close();
    cout << "Transaction status recorded.\n";
}

// Function to simulate the payment verification process
bool processVerification() {
    while (true) {
        cout << "Payment verified by card network.\n";

        if (!getYesNoInput("Is the card valid")) {
            cout << "Invalid card. Restarting verification process...\n";
            continue; // Go back to the start
        }

        if (!getYesNoInput("Are there sufficient funds")) {
            cout << "Not enough funds. Restarting verification process...\n";
            continue; // Go back to the start
        }

        cout << "Bank has approved the transaction.\n";

        if (!getYesNoInput("Is the bank account valid")) {
            cout << "Invalid account. Restarting verification process...\n";
            continue; // Go back to the start
        }

        // All checks passed
        return true;
    }
}

// Function to finalize the transaction
void finalizeTransaction() {
    cout << "Transaction finalized.\n";
    logTransactionStatus("Success");
    cout << "Statement will be sent to the card holder at the end of the billing cycle.\n";
}

int main() {
    cout << "Order placed by the customer.\n";

    bool isVerified = processVerification();

    if (!isVerified) {
        logTransactionStatus("Failed");
        cout << "Termination.\n";
        return 0;
    }

    finalizeTransaction();

    return 0;
}
