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
    if (choice == 'n' || choice == 'N') {
        cout << "Review existing resumes\n";
        cout << "Is there a suitable candidate now? (y/n): ";
        cin >> choice;
 
        if (choice == 'n' || choice == 'N') {
            cout << "Develop recruitment plan\n";
            cout << "Place advertisement\n";
            cout << "Collect resumes\n";
            cout << "Any suitable candidate? (y/n): ";
            cin >> choice;
 
            if (choice == 'n' || choice == 'N') {
                cout << "Candidate not selected\n";
                cout << "End of program\n";
                return 0;
            }
        }
    }
    // -------- Hiring Process --------
    cout << "Arrange candidate meeting\n";
    cout << "Conduct pre-interview\n";
    cout << "Setup interview questions\n";
    cout << "Conduct interview\n";
 
    cout << "Does candidate have good references? (y/n): ";
    cin >> choice;
 
    if (choice == 'n' || choice == 'N') {
        cout << "Candidate not selected\n";
        cout << "End of program\n";
        return 0;
    }
    cout << "Select candidate\n";
    cout << "Evaluate pay rate\n";
    cout << "Send offer letter\n";
 
    cout << "Did candidate confirm offer? (y/n): ";
    cin >> choice;
 
    if (choice == 'n' || choice == 'N') {
        cout << "Candidate not selected\n";
        cout << "End of program\n";
        return 0;
    }
 
    cout << "Hire candidate\n";
    cout << "End of program\n";
    return 0;
}