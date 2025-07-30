#include "Appwrite.hpp"
#include "classes/Messaging.hpp"
#include <iostream>

int main() {
    std::string projectId = "";
    std::string apiKey = ""; 

    std::vector<std::string> topicId = {""};
    std::string messageId = "";
    std::vector<std::string> userId = {""};

    Appwrite appwrite(projectId, apiKey);

    try {
        std::string response = appwrite.getMessaging().updatePush(
            messageId, "Updated Title", "Updated Body", topicId, userId);

        std::cout << "Push notification updated successfully:\n" << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }

    return 0;
}
