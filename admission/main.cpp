#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

struct Applicant {
    string fullName;
    string birthDate;
    string major;
    string hometown;
    bool requiresVisa;
    bool hasAppliedVisa;
    bool hasPaidFee;
    bool needsHostel;
    bool hasExtraCredits;
    bool enrolledAdditionalCourse;
};

void storeToCSV(const Applicant &a) {
    ofstream outFile("student_database.csv", ios::app);
    if (!outFile) {
        cerr << "Error opening student_database.csv\n";
        return;
    }
    outFile << a.fullName << ","
            << a.birthDate << ","
            << a.major << ","
            << a.hometown << ","
            << (a.requiresVisa ? "Yes" : "No") << ","
            << (a.hasAppliedVisa ? "Yes" : "No") << ","
            << (a.hasPaidFee ? "Yes" : "No") << ","
            << (a.needsHostel ? "Yes" : "No") << ","
            << (a.hasExtraCredits ? "Yes" : "No") << ","
            << (a.enrolledAdditionalCourse ? "Yes" : "No") << "\n";
    outFile.close();

    cout << "\nApplicant data successfully saved to database.\n";
}

char promptYesNo(const string &message) {
    char input;
    while (true) {
        cout << message << " (y/n): ";
        cin >> input;
        cin.ignore();
        input = tolower(input);
        if (input == 'y' || input == 'n') {
            return input;
        }
        cout << "Invalid input, please enter y or n.\n";
    }
}

void handleVisa(Applicant &a) {
    char visaStatus = promptYesNo("\nDoes the applicant require a visa?");
    a.requiresVisa = (visaStatus == 'y');

    if (a.requiresVisa) {
        while (true) {
            cout << "Notify applicant to apply for visa.\n";
            char applied = promptYesNo("Has the applicant applied for visa?");
            if (applied == 'y') {
                a.hasAppliedVisa = true;
                break;
            } else {
                cout << "Visa application pending. Please advise the applicant.\n";
            }
        }
    } else {
        a.hasAppliedVisa = false;
        cout << "Visa not required. Moving forward...\n";
    }
}

void handleFee(Applicant &a) {
    while (true) {
        cout << "\nTuition fee payment step.\n";
        char paid = promptYesNo("Has the tuition fee been paid?");
        if (paid == 'y') {
            a.hasPaidFee = true;
            break;
        } else {
            cout << "Fee payment is mandatory. Please complete the payment.\n";
        }
    }
}

void handleAccommodation(Applicant &a) {
    char hostel = promptYesNo("\nDoes the applicant require accommodation?");
    a.needsHostel = (hostel == 'y');

    if (a.needsHostel) {
        cout << "Accommodation assigned.\n";
    } else {
        cout << "No accommodation needed. Proceeding...\n";
    }
}

void assignAdvisor(Applicant &a) {
    cout << "\nAssigning academic advisor...\n";
    cout << "Advisor meeting scheduled.\n";

    char credits = promptYesNo("Does the applicant have additional credits?");
    a.hasExtraCredits = (credits == 'y');

    if (a.hasExtraCredits) {
        char optIn = promptYesNo("Would the applicant like to enroll in an additional course?");
        a.enrolledAdditionalCourse = (optIn == 'y');
        if (a.enrolledAdditionalCourse) {
            cout << "Enrolled in an additional course.\n";
        } else {
            cout << "No additional course selected.\n";
        }
    } else {
        a.enrolledAdditionalCourse = false;
        cout << "No extra credits provided.\n";
    }
}

void processDepartment(Applicant &a) {
    cout << "\nForwarding applicant to Department...\n";
    storeToCSV(a);

    handleVisa(a);
    handleFee(a);
    handleAccommodation(a);
    assignAdvisor(a);
}

void beginRegistration() {
    Applicant a;

    while (true) {
        cout << "\n--- University Registration Form ---\n";
        cout << "Enter full name: ";
        getline(cin, a.fullName);

        cout << "Enter birth date (DD/MM/YYYY): ";
        getline(cin, a.birthDate);

        cout << "Enter desired department: ";
        getline(cin, a.major);

        cout << "Enter city/town: ";
        getline(cin, a.hometown);

        cout << "\nHas the admission office verified the details?\n";
        char verified = promptYesNo("Are the registration details verified?");
        if (verified == 'y') {
            break;
        } else {
            cout << "Verification failed. Please re-enter form details.\n";
        }
    }

    processDepartment(a);
}

int main() {
    beginRegistration();
    cout << "\nApplicant registration successfully completed!\n";
    return 0;
}
