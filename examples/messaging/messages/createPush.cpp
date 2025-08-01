#include "Appwrite.hpp"
#include "classes/Messaging.hpp"
#include <iostream>

int main() {

    std::string projectId = "";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);
    std::vector<std::string> topicId = {""};
    std::vector<std::string> userId = {""};

    try {
        std::string response = appwrite.getMessaging().createPush(
            "unique()", "Title ", "Body", topicId, userId, true);

        std::cout << "Push notification created: " << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }

    return 0;
}