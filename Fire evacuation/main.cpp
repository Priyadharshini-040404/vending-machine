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
