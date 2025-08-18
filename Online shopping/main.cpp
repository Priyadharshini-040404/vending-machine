#include <iostream>
using namespace std;

// Helper function for robust Y/y/N/n input
char promptYesNoInput(const string& questionText) {
    char userReply;
    while (true) {
        cout << questionText;
        cin >> userReply;
        if (userReply == 'y' || userReply == 'Y' || userReply == 'n' || userReply == 'N')
            return userReply;
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
int main() {
    cout << "Order placed.\n";

    char anotherItemChoice;
    do {
        cout << "\nProcessing an item...\n";
        char warehouseStatus = promptYesNoInput("Is the item in the warehouse? (Y/N): ");

        if (warehouseStatus == 'y' || warehouseStatus == 'Y') {
            cout << "Pack with other orders in the warehouse.\n";
        } else {
            cout << "Contact seller.\n";
            cout << "Seller sends goods to customer.\n";
        }

        anotherItemChoice = promptYesNoInput("Do you want to process another item? (Y/N): ");
    } while (anotherItemChoice == 'y' || anotherItemChoice == 'Y');

    cout << "\nSend warehouse goods to customer.\n";
    cout << "Customer collects goods.\n";

    char sellerConfirmation = promptYesNoInput("Did seller confirm customer received order? (Y/N): ");