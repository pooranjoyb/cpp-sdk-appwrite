#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "<project-id>"; // Replace with your actual project ID
    std::string apiKey = "<api-key>";       // Replace with your actual API key

    Appwrite appwrite(projectId, apiKey);   // Create Appwrite instance

    std::string messageId = "unique-message-id-0101";
    std::string subject = "Hello from C++ Appwrite SDK!";
    std::string content = "Testing email message creation with topics and targets.";

    std::vector<std::string> topics = {"<topic-id>"};     // Replace with your topic ID
    std::vector<std::string> targets = {"<target-id>"};   // Replace with your target ID (e.g. email:uid)

    try {
        std::string response = appwrite.getMessaging().createEmailMessage(
            messageId, subject, content, topics, targets
        );
        std::cout << "Email Message Created!\nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}

