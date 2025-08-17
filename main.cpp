#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string choice;
    char power;
    bool powerOn = false;
 
    cout << "=== Coffee Machine Program ===" << endl;
 
    // Start
    cout << "Press 'Y' to Power On: ";
    cin >> power;
 
    if (power == 'Y' || power == 'y') {
        powerOn = true;
        cout << "\nMachine Powered ON ✅" << endl;
 
       
    }
    else {
        cout << "\nMachine not powered ON. Exiting..." << endl;
    }
 
    cout << "\n=== Program Ended ===" << endl;
    return 0;
}