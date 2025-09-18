#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "";
    std::string apiKey = "";

    Appwrite appwrite(projectId, apiKey);

    std::string messageId = "67b30694016a7eb8";
    std::string subject = "Hello from C++ Appwrite SDK!";
    std::string content =
        "Testing SMS message creation with topics, users, and targets.";

    std::vector<std::string> topics = {};
    std::vector<std::string> users = {};
    std::vector<std::string> targets = {};

    std::string scheduled_at = "2025-09-27 18:00:00.000";
    bool draft = true;

    try {
        std::string response = appwrite.getMessaging().createSms(
            messageId, content, topics, users, targets, draft, scheduled_at);
        std::cout << "SMS Message Created!\nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}