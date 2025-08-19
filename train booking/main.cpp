#include <iostream>
#include <string>
#include <limits>
#include <thread>   // for sleep
#include <chrono>   // for sleep duration

// Function for validated yes/no input
char getYesNo(const std::string &prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (input.size() == 1 && 
           (input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N')) {
            return input[0];
        }
        std::cerr << "Invalid input! Please enter only y or n.\n";
    }
}

// Function for validated menu choice (1 or 2)
int getChoice(const std::string &prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (input == "1" || input == "2") {
            return std::stoi(input);
        }
        std::cerr << "Invalid input! Please enter 1 or 2.\n";
    }
}

int main() {
    std::cout << "Start the train journey\n";

    // Step 1: Buy ticket
    std::cout << "Ticket purchased.\n";

    // Step 2: Need seat reservation?
    char need_res = getYesNo("Need a seat reservation? (y/n): ");

    if (need_res == 'y' || need_res == 'Y') {
        std::cout << "Seat selected.\n";
    } else {
        // If no, ask if still want reservation
        char want_res = getYesNo("Do you want a seat reservation? (y/n): ");
        if (want_res == 'y' || want_res == 'Y') {
            std::cout << "Seat selected.\n";
        }
    }

    // Step 3: Ticket collection
    int ticket_choice = getChoice("How to collect ticket? (1=Mail, 2=Machine): ");

    if (ticket_choice == 1) {
        std::cout << "Check ticket in mail.\n";
    } else {
        std::cout << "Collect ticket from machine.\n";
    }

    std::cout << "Board train.\n";

    // Step 4: Seat allocation
    char have_res = getYesNo("Do you have a seat reservation? (y/n): ");
    if (have_res == 'y' || have_res == 'Y') {
        std::cout << "Look for your assigned seat.\n";
    } else {
        std::cout << "Look for an unassigned seat.\n";
    }

    // Step 5: Ticket checking
    std::cout << "Ticket checked by inspector.\n";

    // Step 6: Discount validation
    char discount = getYesNo("Do you have a discounted ticket? (y/n): ");
    if (discount == 'y' || discount == 'Y') {
        std::cout << "Show valid documentation.\n";
    }

    // Step 7: Arrival loop
    char arrived;
    do {
        arrived = getYesNo("Have you arrived at your destination? (y/n): ");
        if (arrived == 'n' || arrived == 'N') {
            std::cout << "Wait for 2 minutes...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2)); // simulate 2 minutes with 2 sec
        }
    } while (arrived == 'n' || arrived == 'N');

    std::cout << "Leave the train.\n";
    std::cout << "Journey ended.\n";

    return 0;
}
