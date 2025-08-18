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
 
bool visaCheck() {
    char needV, appliedV;
    std::cout << "Do you need a visa? (y/n): ";
    std::cin >> needV;
    needV = std::tolower(needV);
    if (needV == 'y') {
        std::cout << "Have you applied for the visa? (y/n): ";
        std::cin >> appliedV;
        appliedV = std::tolower(appliedV);
        if (appliedV == 'n') {
            std::cout << "Please apply for the visa before proceeding.\n";
            return false;
        }
    }
    return true;
}
 
void hostelCheck() {
    char needH;
    std::cout << "Do you need accommodation? (y/n): ";
    std::cin >> needH;
    needH = std::tolower(needH);
    if (needH == 'y') {
        std::cout << "Accommodation will be assigned to you.\n";
    }
}
 
void courseCheck() {
    char extraC;
    std::cout << "Do you have extra credits? (y/n): ";
    std::cin >> extraC;
    extraC = std::tolower(extraC);
    if (extraC == 'y') {
        std::cout << "Please choose extra courses.\n";
    }
}
 
bool feeCheck() {
    char paidF;
    std::cout << "Have you paid the tuition fees? (y/n): ";
    std::cin >> paidF;
    paidF = std::tolower(paidF);
    if (paidF == 'n') {
        std::cout << "Please pay the tuition fees before proceeding.\n";
        return false;
    }
    return true;
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
 