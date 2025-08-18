#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// CSV file names
const string incomeFile = "Income.csv";
const string availableFile = "Available.csv";
const string orderHistoryFile = "OrderHistory.csv";

// Create CSV file with header if it doesn't exist
void ensureCSVFile(const string& filename, const string& header) {
    if (!fs::exists(filename)) {
        ofstream file(filename);
        file << header << "\n";
        file.close();
    }
}

// Append a line to a CSV file
void appendToCSV(const string& filename, const string& line) {
    ofstream file(filename, ios::app);
    file << line << "\n";
    file.close();
}

int main() {
    cout << "=== Ride Assignment Program ===\n";

    // Step 1: Order method
    char method;
    cout << "Order placed by (P)hone or (S)oftware? ";
    cin >> method;

    string methodStr;
    if (method == 'P' || method == 'p') {
        methodStr = "Phone";
        cout << "Sending request to Call Centre Server...\n";
    } else if (method == 'S' || method == 's') {
        methodStr = "Software";
        cout << "Sending request to Software Server...\n";
    } else {
        cout << "Invalid option. Exiting...\n";
        return 0;
    }

    // Step 1.1: Create and update Income.csv
    ensureCSVFile(incomeFile, "Method,Status");
    appendToCSV(incomeFile, methodStr + ",Requested");

    // Step 2: Check pickup time
    bool pickupWithin30 = false;
    while (!pickupWithin30) {
        cout << "Checking if pickup is within 30 minutes...\n";
        char ans;
        cout << "Is pickup within 30 mins? (y/n): ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            pickupWithin30 = true;
        } else {
            cout << "Not within 30 mins. Wait 1 minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1)); // simulate 1 min
        }
    }

    // Step 3: Finding taxi
    cout << "Finding taxi within 10 km of pickup location...\n";

    // Step 3.1: Ensure Available.csv exists with one sample taxi
    ensureCSVFile(availableFile, "TaxiID,Pickup,Drop");

    {
        ifstream checkFile(availableFile);
        checkFile.seekg(0, ios::end);
        if (checkFile.tellg() < 30) {
            ofstream file(availableFile, ios::app);
            file << "TX001,Available,Available\n";
            file.close();
        }
    }

    // Step 4: Check if taxi is found
    bool taxiFound = false;
    string assignedTaxiID = "TX001"; // Hardcoded taxi for simplicity

    while (!taxiFound) {
        char ans;
        cout << "Taxi found? (y/n): ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y') {
            taxiFound = true;

            // Scoped block to ensure files closed before remove/rename
            {
                ifstream inFile(availableFile);
                ofstream outFile("temp.csv");

                string header, line;
                getline(inFile, header);
                outFile << header << "\n";

                while (getline(inFile, line)) {
                    if (line.find(assignedTaxiID) != string::npos) {
                        outFile << assignedTaxiID << ",Picked,Dropped\n";
                    } else {
                        outFile << line << "\n";
                    }
                }

                // inFile and outFile closed here at end of scope
            }

            // Small delay to ensure OS releases file locks
            this_thread::sleep_for(chrono::milliseconds(100));

            fs::remove(availableFile);
            fs::rename("temp.csv", availableFile);

        } else {
            cout << "No taxi yet. Wait 1 minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1)); // simulate wait
        }
    }

    // Step 5: Assign passenger and finish ride
    cout << "Assigning passenger to driver...\n";
    cout << "Passenger reached drop point.\n";

    // Step 6: Update OrderHistory.csv
    ensureCSVFile(orderHistoryFile, "Method,TaxiID,Status");
    appendToCSV(orderHistoryFile, methodStr + "," + assignedTaxiID + ",Passenger Dropped");

    cout << "End.\n";
    return 0;
}
