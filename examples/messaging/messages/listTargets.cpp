#include "Appwrite.hpp"
#include "classes/Messaging.hpp"
#include <iostream>

int main() {
    std::string projectId = "";
    std::string apiKey = "";
    std::string messageId = "";

    std::vector<std::string> queries = {};

    Appwrite appwrite(projectId, apiKey);

    try {
        std::string response = appwrite.getMessaging().listTargets(messageId, queries);
        std::cout << "Message targets retrieved successfully:\n" << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }

    return 0;
}
