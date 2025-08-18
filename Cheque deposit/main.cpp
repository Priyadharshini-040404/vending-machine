#include <iostream>
#include <string>
using namespace std;
 
// Function for Yes/No validation
char askYesNo(const string& msg) {
    char response;
    while (true) {
        cout << msg;
        cin >> response;
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N')
            return response;
        cout << "Invalid input. Enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
 
int main() {
    cout << "=== Cheque Transaction System ===\n";
 
    // Step 1: Insert card & enter account number
    string senderAccount;
    cout << "Insert bank card into machine.\n";
    cout << "Enter Sender Bank Account Number: ";
    cin >> senderAccount;
 
    // Step 2: Enter receiver account number
    string receiverAccount;
    cout << "Enter Receiver Bank Account Number: ";
    cin >> receiverAccount;
 
    // Step 3: Enter cheque number
    string chequeNumber;
    cout << "Enter Cheque Number: ";
    cin >> chequeNumber;
 
    // Step 4: Enter value
    double chequeValue;
    cout << "Enter Cheque Value: ";
    cin >> chequeValue;
 
    // Summary before processing
    cout << "\n--- Cheque Details ---\n";
    cout << "Sender Account   : " << senderAccount << endl;
    cout << "Receiver Account : " << receiverAccount << endl;
    cout << "Cheque Number    : " << chequeNumber << endl;
    cout << "Cheque Value     : " << chequeValue << endl;
 
    
        }
    }
 
    cout << "\n=== End of Process ===\n";
    return 0;
}