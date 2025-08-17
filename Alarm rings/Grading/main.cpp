#include <iostream>
using namespace std;
 
int main() {
    int score;
 
    while (true) {
        cout << "Enter score (0-100): ";
        cin >> score;
 
        if (score < 0 || score > 100) {
            cout << "Invalid score. Please enter a value between 0 and 100." << endl;
            continue;
        }
 
        
    }
 
    cout << "End" << endl;
 
    return 0;
}