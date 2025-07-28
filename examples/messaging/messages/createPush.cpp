#include "Appwrite.hpp"
#include "classes/Messaging.hpp"
#include <iostream>

int main() {

    std::string projectId = "";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);
    std::string topicId = "67b3048600077f40b8a7";

    try {
        std::string response = appwrite.getMessaging().createPush(
            "unique()", "Title ", "Body", topicId);

        std::cout << "Push notification created: " << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }

    return 0;
}