#include <iostream>
#include <cctype>

void initiateCustomerSupport() {
    std::cout << "Customer contacts customer service.\n";
}

void routeToSalesSupport() {
    std::cout << "Redirecting to sales support...\n";
}

void notifyTechTeam() {
    std::cout << "Contacting technical team...\n";
}

void handleIssueSimulation() {
    char simulateOption;
    std::cout << "Simulate issue? (y/n): ";
    std::cin >> simulateOption;
    simulateOption = std::tolower(simulateOption);

    if (simulateOption == 'y') {
        std::cout << "Simulating issue...\n";
    }

    std::cout << "Resolving issue...\n";
}

void collectFeedback() {
    char feedbackChoice;
    std::cout << "Would you like to give feedback? (y/n): ";
    std::cin >> feedbackChoice;
    feedbackChoice = std::tolower(feedbackChoice);

    if (feedbackChoice == 'y') {
        std::cout << "Thank you for your feedback!\n";
    } else {
        std::cout << "No feedback given.\n";
    }
}

int main() {
    initiateCustomerSupport();

    char hasIssue;
    std::cout << "Is there an issue? (y/n): ";
    std::cin >> hasIssue;
    hasIssue = std::tolower(hasIssue);

    if (hasIssue == 'n') {
        std::cout << "No issues. Ending process.\n";
        collectFeedback();
        return 0;
    }

    char isSalesRelated;
    std::cout << "Is this a sales issue? (y/n): ";
    std::cin >> isSalesRelated;
    isSalesRelated = std::tolower(isSalesRelated);

    if (isSalesRelated == 'y') {
        routeToSalesSupport();
        collectFeedback();
        return 0;
    }

    char isTechRelated;
    std::cout << "Is this a technical issue? (y/n): ";
    std::cin >> isTechRelated;
    isTechRelated = std::tolower(isTechRelated);

    if (isTechRelated == 'y') {
        notifyTechTeam();

        char isNewProblem;
        std::cout << "Is this a new issue? (y/n): ";
        std::cin >> isNewProblem;
        isNewProblem = std::tolower(isNewProblem);

        if (isNewProblem == 'y') {
            handleIssueSimulation();

            char isResolved;
            std::cout << "Is the issue fixed? (y/n): ";
            std::cin >> isResolved;
            isResolved = std::tolower(isResolved);

            if (isResolved != 'y') {
                std::cout << "Issue still not fixed. Contacting technical team again...\n";
                handleIssueSimulation();
            }
        }
        collectFeedback();
        return 0;
    }

    std::cout << "No sales or technical issue. Proceeding to feedback.\n";
    collectFeedback();

    return 0;
}
