#include <iostream>
#include <string>
using namespace std;

// Helper function to get valid 'y' or 'n' input
char getYesNoInput(const string& prompt) {
    char input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
            return input;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Helper function to get valid traffic light color: red or green
string getTrafficLightColor() {
    string color;
    while (true) {
        cout << "What is the light color? (red/green): ";
        cin >> color;
        if (color == "red" || color == "Red" || color == "green" || color == "Green") {
            return color;
        } else {
            cout << "Invalid color. Please enter 'red' or 'green'." << endl;
        }
    }
}

// Function for Footbridge process
bool footbridge() {
    char available = getYesNoInput("Is footbridge available? (y/n): ");
    if (available == 'y' || available == 'Y') {
        cout << "Use the footbridge.\n";
        return true;
    }
    return false;
}

// Function for Tunnel process
bool tunnel() {
    char available = getYesNoInput("Is tunnel available? (y/n): ");
    if (available == 'y' || available == 'Y') {
        cout << "Use the tunnel.\n";
        return true;
    }
    return false;
}

// Function for Crossing process
bool crossing() {
    char available = getYesNoInput("Is crossing available? (y/n): ");
    if (available == 'y' || available == 'Y') {
        return true;
    } else {
        cout << "Walk away.\n";
        return false;
    }
}

// Function for Traffic Crossing process
bool trafficCrossing() {
    char car_left = getYesNoInput("Look left. Is a car approaching? (y/n): ");
    if (car_left == 'y' || car_left == 'Y') {
        cout << "Wait, car approaching from left.\n";
        return false;
    }
    char car_right = getYesNoInput("Look right. Is a car approaching? (y/n): ");
    if (car_right == 'y' || car_right == 'Y') {
        cout << "Wait, car approaching from right.\n";
        return false;
    }
    cout << "Safe to cross.\n";
    return true;
}

// Function for Traffic Light process (with repeated green check)
bool trafficLight() {
    char available = getYesNoInput("Is traffic light available? (y/n): ");
    if (available == 'y' || available == 'Y') {
        while (true) {
            string color = getTrafficLightColor();
            if (color == "green" || color == "Green") {
                cout << "Light is green, wait and check again.\n";
                // continue loop to check color again
            } else {
                // color is red, now check crossing
                cout << "Light is red, check traffic crossing.\n";
                if (trafficCrossing()) {
                    return true;  // safe to cross, exit function with success
                } else {
                    cout << "Not safe to cross, wait again.\n";
                    // Continue looping to check light color again
                }
            }
        }
    }
    return false;
}

int main() {
    cout << "Pedestrian Crossing Decision Simulation\n";

    while (true) {   // keep looping until a way is found
        if (footbridge()) break;
        if (tunnel()) break;
        if (!crossing()) continue; // crossing unavailable, restart loop
        if (trafficLight()) break;
    }

    cout << "Decision process ended.\n";
    return 0;
}