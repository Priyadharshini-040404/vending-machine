#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void initiateClientSupport() {
    cout << "Customer found an issue.\n"; 
    cout << "Customer contacts Customer Service.\n";
}

void respondToQuery() {
    cout << "Answering customer's question.\n";
}

void forwardToSales() {
    cout << "Redirecting to Sales Support.\n";
    cout << "Issue resolved.\n";
}

void connectTechDepartment() {
    cout << "Contacting Technical Team.\n";
    cout << "Issue resolved.\n";
}

void beginIssueDiagnosis() {
    cout << "Testing the issue.\n";
}

bool attemptIssueSimulation() {
    char userInput;
    cout << "Can you simulate the issue? (y/n): ";
    cin >> userInput;
    return tolower(userInput) == 'y';
}

void requestAdditionalDetails() {
    cout << "Contacting customer for more information...\n";
}

void performIssueAnalysis() {
    cout << "Performing error analysis.\n";
}

void resolveReportedIssue() {
    cout << "Solving the issue.\n";
}

void logIssueReport() {
    cout << "Updating Error Report...\n";
    ofstream reportFile("error_report.csv", ios::app);
    if (reportFile.is_open()) {
        reportFile << "Issue Recorded\n";
        reportFile.close();
        cout << "Error Report updated successfully.\n";
    } else {
        cout << "Error: Unable to open error_report.csv\n";
    }
}

void updateErrorLog() {
    cout << "Updating Error Database...\n";
    ofstream dbFile("error_database.csv", ios::app);
    if (dbFile.is_open()) {
        dbFile << "Error logged\n";
        dbFile.close();
        cout << "Error Database updated successfully.\n";
    } else {
        cout << "Error: Unable to open error_database.csv\n";
    }
}

bool verifyResolutionWithClient() {
    char resolutionInput;
    cout << "Has the issue been fixed? Confirm with customer (y/n): ";
    cin >> resolutionInput;
    return tolower(resolutionInput) == 'y';
}

void collectClientFeedback() {
    char feedbackInput;
    cout << "Would you like to give feedback? (y/n): ";
    cin >> feedbackInput;
    if (tolower(feedbackInput) == 'y') {
        cout << "Redirecting to survey...\n";
    } else {
        cout << "No feedback given.\n";
    }
}

// Process for new technical issue
void processNewTechIssue() {
    beginIssueDiagnosis();

    bool wasSimulated = attemptIssueSimulation();
    while (!wasSimulated) {
        requestAdditionalDetails();
        wasSimulated = attemptIssueSimulation();
    }

    logIssueReport();
    updateErrorLog();

    performIssueAnalysis();
    resolveReportedIssue();

    if (!verifyResolutionWithClient()) {
        cout << "Issue not fixed after initial resolution.\n";

        wasSimulated = false;
        while (!wasSimulated) {
            requestAdditionalDetails();
            wasSimulated = attemptIssueSimulation();
        }

        logIssueReport();
        updateErrorLog();

        performIssueAnalysis();
        resolveReportedIssue();

        if (!verifyResolutionWithClient()) {
            cout << "Issue still not fixed after second attempt.\n";
        }
    }
}

// Process for existing technical issue
void processExistingTechIssue() {
    resolveReportedIssue();

    if (!verifyResolutionWithClient()) {
        cout << "Issue not fixed after resolution attempt.\n";
    }
}

// Handle non-technical issue but possibly new
void processNonTechIssue() {
    char newIssueInput;
    cout << "Is this a new issue? (y/n): ";
    cin >> newIssueInput;

    if (tolower(newIssueInput) == 'y') {
        beginIssueDiagnosis();

        bool issueSimulated = attemptIssueSimulation();
        while (!issueSimulated) {
            requestAdditionalDetails();
            issueSimulated = attemptIssueSimulation();
        }

        logIssueReport();
        updateErrorLog();

        performIssueAnalysis();
        resolveReportedIssue();

        if (!verifyResolutionWithClient()) {
            cout << "Issue not fixed after initial resolution.\n";

            issueSimulated = false;
            while (!issueSimulated) {
                requestAdditionalDetails();
                issueSimulated = attemptIssueSimulation();
            }

            logIssueReport();
            updateErrorLog();

            performIssueAnalysis();
            resolveReportedIssue();

            if (!verifyResolutionWithClient()) {
                cout << "Issue still not fixed after second attempt.\n";
            }
        }
    } else {
        resolveReportedIssue();

        bool simulationStatus = attemptIssueSimulation();
        while (!simulationStatus) {
            requestAdditionalDetails();
            simulationStatus = attemptIssueSimulation();
        }

        logIssueReport();
        updateErrorLog();

        if (!verifyResolutionWithClient()) {
            cout << "Issue not fixed after resolution attempt.\n";
        }
    }
}

int main() {
    initiateClientSupport();

    char isEnquiry;
    cout << "Is the customer enquiry? (y/n): ";
    cin >> isEnquiry;
    if (tolower(isEnquiry) == 'y') {
        respondToQuery();
        collectClientFeedback();
        cout << "End of process.\n";
        return 0;
    }

    char isSalesRelated;
    cout << "Is this a sales issue? (y/n): ";
    cin >> isSalesRelated;
    if (tolower(isSalesRelated) == 'y') {
        forwardToSales();
        collectClientFeedback();
        cout << "End of process.\n";
        return 0;
    }

    char isTechRelated;
    cout << "Is this a technical issue? (y/n): ";
    cin >> isTechRelated;
    if (tolower(isTechRelated) == 'y') {
        connectTechDepartment();  // Only contact tech team
        collectClientFeedback();  // Then collect feedback
        cout << "End of process.\n";  // Then end
        return 0;
    }

    // Handling "not a technical issue" path
    processNonTechIssue();

    collectClientFeedback();
    cout << "End of process.\n";
    return 0;
}
