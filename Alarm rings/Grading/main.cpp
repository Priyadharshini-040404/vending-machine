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
 
        if (score >= 80) {
            cout << "Grade: A" << endl;
        } else if (score >= 60) {
            cout << "Grade: B" << endl;
        } else if (score >= 50) {
            cout << "Grade: C" << endl;
        } else {
            cout << "Fail" << endl;
        }
        break;
    }
 
    cout << "End" << endl;
 
    return 0;
}