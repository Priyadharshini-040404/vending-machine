#include <iostream>
#include <string>
#include <cctype>
 
void formCheck(bool &formOk) {
    char chForm;
    std::cout << "Is your registration form verified? (y/n): ";
    std::cin >> chForm;
    chForm = std::tolower(chForm);
    formOk = (chForm == 'y');
}
int main() {
    std::string studName;
    bool formStatus = false;
 
    std::cout << "Enter your name: ";
    std::getline(std::cin, studName);
 
    formCheck(formStatus);
    if (!formStatus) {
        std::cout << "Please verify your form before proceeding.\n";
        return 0;
    }
 
    std::cout << "Form verified successfully.\n";
 
    if (!visaCheck()) {
        return 0;
    }
 
    if (!feeCheck()) {
        return 0;
    }
 
    hostelCheck();
    courseCheck();
 
    std::cout << "\nRegistration process completed successfully for " 
              << studName << "!\n";
 
    return 0;
}
 