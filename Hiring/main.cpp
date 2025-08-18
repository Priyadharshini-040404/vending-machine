#include <iostream>
using namespace std;
 
int main() {
    cout << "Job is defined\n";
    cout << "Crew request sent to HR\n";
 
    char choice;
 
    // Ask about regular hiring
    cout << "Is it regular hiring process? (y/n): ";
    cin >> choice;
    if (choice == 'n' || choice == 'N') {
        cout << "Special hiring process\n";
        cout << "End of program\n";
        return 0;
    }
 
    // -------- Suitable Candidate Check Sequence --------
    cout << "Is there a suitable candidate? (y/n): ";
    cin >> choice;
    return 0;
}