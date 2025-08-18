#include <iostream>
using namespace std;

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
    char atBalcony;
    cout << "Did you reach the balcony? (y/n): ";
    cin >> atBalcony;
    if (atBalcony == 'y' || atBalcony == 'Y') {
        cout << "Wait for help.\n";
    } else {
        evaluateUpperPath();
    }
}

void evaluateUpperPath() {
    char heavySmoke;
    cout << "Is there strong smoke or fire? (y/n): ";
    cin >> heavySmoke;
    if (heavySmoke == 'y' || heavySmoke == 'Y') {
        enterSafeZone();
    } else {
        moveUpward();
    }
}

void reassessEscapeOption();

void tryEscapeRoute() {
    cout << "Go downstairs and get out of the building.\n";
    char escapedSafely;
    cout << "Did you successfully leave the building? (y/n): ";
    cin >> escapedSafely;
    if (escapedSafely == 'y' || escapedSafely == 'Y') {
        cout << "You have safely escaped the building! Stay safe.\n";
    } else {
        reassessEscapeOption();
    }
}

void reassessEscapeOption() {
    cout << "Reason-1: Cannot exit down due to fire/strong smoke.\n";
    char sawSmokeWhileExiting;
    cout << "Do you see strong smoke or fire while escaping? (y/n): ";
    cin >> sawSmokeWhileExiting;
    if (sawSmokeWhileExiting == 'y' || sawSmokeWhileExiting == 'Y') {
        moveUpward();
    } else {
        tryEscapeRoute();
    }
}

void examineExitDoor() {
    char doorCheck;
    cout << "Is the door hot or is strong smoke present? (y/n): ";
    cin >> doorCheck;
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
    char fireInsideBuilding;
    cout << "Is the place of fire IN the building? (y/n): ";
    cin >> fireInsideBuilding;
    if (fireInsideBuilding == 'n' || fireInsideBuilding == 'N') {
        alertFireServices();
        return;
    } else if (fireInsideBuilding == 'y' || fireInsideBuilding == 'Y') {
        packEmergencyItems();
        activateFireAlarm();
        examineExitDoor();
    } else {
        cout << "Invalid input.\n";
    }
}

int main() {
    cout << "*** FIRE EVACUATION PLAN ***\n";
    cout << "How was the fire detected?\n";
    cout << "1. You see fire/smoke\n2. Someone sees fire/smoke\n3. Smoke detector\nChoose (1/2/3): ";
    int detectionMode;
    cin >> detectionMode;
    if (detectionMode == 3) {
        handleDetectorAlert();
    } else if (detectionMode == 1 || detectionMode == 2) {
        handleManualDetection();
    } else {
        cout << "Invalid input.\n";
    }
    return 0;
}
