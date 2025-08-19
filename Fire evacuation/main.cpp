#include <iostream>
#include <string>
using namespace std;

// Get and validate Y/y/N/n inputs
char getYesNo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (input.length() == 1 && 
            (input[0] == 'y' || input[0] == 'Y' || input[0] == 'n' || input[0] == 'N')) {
            return input[0];
        }

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
    }
}

// Get and validate integer input from list of options
int getMenuChoice(const string& prompt, int min, int max) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;

        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a number between " << min << " and " << max << ".\n";
        } else {
            cin.ignore(10000, '\n');  // Clean up extra input
            return choice;
        }
    }
}

void packEmergencyItems() {
    cout << "Bring wallet, keys, phone, wet towels.\n";
}

void alertFireServices() {
    cout << "Contacting fire department...\n";
}

void followRescueInstructions() {
    cout << "Do not open the door.\n";
    cout << "Seal all the cracks with wet towels.\n";
    alertFireServices();
    cout << "Wave at the windows to identify survivors.\n";
    cout << "Wait for rescue.\n";
}

void activateFireAlarm() {
    cout << "Push the fire alarm trigger to alert others!\n";
}

void enterSafeZone() {
    cout << "Find and enter a safe room. Seal cracks and wait for rescue.\n";
    followRescueInstructions();
}

void moveUpward();
void evaluateUpperPath();

void moveUpward() {
    cout << "Go upstairs and reach balcony.\n";
    char atBalcony = getYesNo("Did you reach the balcony? (y/n): ");
    if (atBalcony == 'y' || atBalcony == 'Y') {
        cout << "Wait for help.\n";
    } else {
        evaluateUpperPath();
    }
}

void evaluateUpperPath() {
    char heavySmoke = getYesNo("Is there strong smoke or fire? (y/n): ");
    if (heavySmoke == 'y' || heavySmoke == 'Y') {
        enterSafeZone();
    } else {
        moveUpward();
    }
}

void reassessEscapeOption();

void tryEscapeRoute() {
    cout << "Go downstairs and get out of the building.\n";
    char escapedSafely = getYesNo("Did you successfully leave the building? (y/n): ");
    if (escapedSafely == 'y' || escapedSafely == 'Y') {
        cout << "You have safely escaped the building! Stay safe.\n";
    } else {
        reassessEscapeOption();
    }
}

void reassessEscapeOption() {
    cout << "Reason-1: Cannot exit down due to fire/strong smoke.\n";
    char sawSmokeWhileExiting = getYesNo("Do you see strong smoke or fire while escaping? (y/n): ");
    if (sawSmokeWhileExiting == 'y' || sawSmokeWhileExiting == 'Y') {
        moveUpward();
    } else {
        tryEscapeRoute();
    }
}

void examineExitDoor() {
    char doorCheck = getYesNo("Is the door hot or is strong smoke present? (y/n): ");
    if (doorCheck == 'y' || doorCheck == 'Y') {
        followRescueInstructions();
    } else {
        tryEscapeRoute();
    }
}

void handleDetectorAlert() {
    cout << "Smoke detector detects smoke and triggers alarm.\n";
    packEmergencyItems();
    examineExitDoor();
}

void handleManualDetection() {
    char fireInsideBuilding = getYesNo("Is the place of fire IN the building? (y/n): ");
    if (fireInsideBuilding == 'n' || fireInsideBuilding == 'N') {
        alertFireServices();
    } else {
        packEmergencyItems();
        activateFireAlarm();
        examineExitDoor();
    }
}

int main() {
    cout << "*** FIRE EVACUATION PLAN ***\n";

    int detectionMode = getMenuChoice(
        "How was the fire detected?\n"
        "1. You see fire/smoke\n"
        "2. Someone sees fire/smoke\n"
        "3. Smoke detector\n"
        "Choose (1/2/3): ",
        1, 3
    );

    if (detectionMode == 3) {
        handleDetectorAlert();
    } else {
        handleManualDetection();
    }

    return 0;
}
