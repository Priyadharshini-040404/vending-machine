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